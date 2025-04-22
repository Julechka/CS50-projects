def main():
    user_input = input("Enter a string: ")
    print(convert(user_input))


def convert(string):
    return string.replace(":)", "🙂").replace(":(", "🙁")


main()
