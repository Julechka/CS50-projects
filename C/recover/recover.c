#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool signature_found(uint8_t sign[512]);

int main(int argc, char *argv[])
{
    //  Accept a single cmd-line argument
    if (argc != 2)
    {
        //  If not, print error message and return 1
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    //  Open forensic image card.raw for reading
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        //  If the file can't be opened print error message and return 1
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }
    //  Create 512 bytes buffer
    uint8_t buffer[512];

    //  Create numeric name for the first file
    char filename[8];
    int count = 0;
    FILE *image = NULL;

    //  Read card.raw into buffer until the EOF found
    while (fread(buffer, 1, 512, card) == 512)
    {
        if (signature_found(buffer))
        {
            // Close previous file
            if (image != NULL)
                fclose(image);
            // Create new filename
            sprintf(filename, "%03i.jpg", count);
            count++;
            // Open created file for writing
            image = fopen(filename, "w");
            //  Write 512 bytes to this file from buffer
            if (image == NULL)
            {
                printf("Could not create file %s \n", filename);
                fclose(card);
                return 1;
            }
            fwrite(buffer, 1, 512, image);
        }
        else
        {
            // Continue reading to buffer and write them into image file
            if (image != NULL)
                fwrite(buffer, 1, 512, image);
        }
    }
    if (image != NULL)
        fclose(image);
    fclose(card);
    return 0;
}

bool signature_found(uint8_t sign[512])
{
    return (sign[0] == 0xff && sign[1] == 0xd8 && sign[2] == 0xff && (sign[3] & 0xf0) == 0xe0);
}
