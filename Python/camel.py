def main():
    camel_case = input("camelCase: ")
    # Printing the input, converted to snake case
    print(f"snake_case: {convert_to_snake_case(camel_case)}")


def convert_to_snake_case(string):
    # handling first character to modified string
    snake_string = string[0].lower()
    # checking all letters in a string and replacing all uppercase with _lowercase
    for letter in string[1:]:
        snake_string += "_" + letter.lower() if letter.isupper() else letter

    return snake_string


main()
