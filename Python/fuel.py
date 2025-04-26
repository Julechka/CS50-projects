def main():
    while True:
        # Prompting the input of fraction
        fraction = input("Fraction: ")
        try:
            percent = round(convert_fraction_to_percent(fraction))
        # In case of invalid input propt the use to input again
        except (ValueError, ZeroDivisionError):
            continue
        # If the tank is less than 1% full, print E
        if percent <= 1:
            print("E")
        # If the tank is more than 99% full, print F
        elif percent >= 99:
            print("F")
        # Print the fuel gauge in %
        else:
            print(f"{percent}%")
        break

def convert_fraction_to_percent(string):
    # Handling the input has no /
    if string.count("/") != 1:
        raise ValueError

    # Splitting the input into to two parts
    numerator, denominator = string.split("/")

    # Handling the input is not int/int
    if not (numerator.isdigit() and denominator.isdigit()):
        raise ValueError
    numerator = int(numerator)
    denominator = int(denominator)
    # Handling numinator > denominator case
    if numerator > denominator:
        raise ValueError

    # Returning the franction converted to %
    return (numerator / denominator) * 100


main()
