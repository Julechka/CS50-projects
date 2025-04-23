def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    # check that input is 2 to 6 alphanumerics and 2 first are letters
    if not (s.isalnum() and s[:1].isalpha() and (2 <= len(s) <= 6)):
        return False
    char_count = 2
    # checking the string starting from 3d character
    for char in s[2:]:
        if char.isalpha():
            char_count += 1
        # first digit could not ne 0
        elif int(char) == 0:
            return False
        # after a digit there are not allowed to have letters
        else:
            if char.isnumeric() and s[char_count:].isnumeric():
                return True
    return True


main()
