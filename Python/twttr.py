VOWELS = {"a", "e", "i", "o", "u"}


def main():
    # Prompts the user for a text and  outputs same text without vowels
    input_string = input("Input: ")
    print(f"Output: {remove_vowels(input_string)}")


def remove_vowels(string):
    # checking all letters in a string and omitting all vowels
    twttr_string = ''.join([letter for letter in string if letter.lower() not in VOWELS])
    return twttr_string


main()
