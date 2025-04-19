import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py arg1 arg2")
        sys.exit(1)

    # Read database file into a variable
    try:
        with open(sys.argv[1], "r") as csvfile:
            reader_csv = csv.DictReader(csvfile)
            header_csv = reader_csv.fieldnames
            data_csv = [row for row in reader_csv]
    except FileNotFoundError:
        print(f"Could not open {sys.argv[1]}")
        sys.exit(2)

    # Read DNA sequence file into a variable
    try:
        with open(sys.argv[2], "r") as txtfile:
            dna_data = txtfile.read()
    except FileNotFoundError:
        print(f"Could not open {sys.argv[2]}")
        sys.exit(3)

    # Find longest match of each STR in DNA sequence
    str_longest = []
    for str_name in header_csv[1:]:
        str_longest.append(longest_match(dna_data, str_name))

    # Check database for matching profiles
    for person in data_csv:
        match = True
        for i, str_name in enumerate(header_csv[1:]):
            if int(person[str_name]) != str_longest[i]:
                match = False
                break
        if match:
            print(person["name"])
            break
    else:
        print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
