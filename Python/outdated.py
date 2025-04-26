# List of valid input months
valid_month = [
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
]


def main():
    while True:
        # Prompt user input
        date_input = input("Date: ")
        date_input = date_input.strip(' "\'')
        try:
            convert_to_ISO(date_input)
        except ValueError:
            continue
        break


def convert_to_ISO(date_input):
    # Splitting format "month/day/year"
    if date_input.count("/") == 2:
        month, day, year = date_input.split("/")
        # Handling the input is not int
        if not (month.isdigit() and day.isdigit() and year.isdigit()):
            raise ValueError
        month = int(month)
        day = int(day)
        year = int(year)

    # Splitting format "Month day, year"
    elif (date_input.count(" ") == 2 and date_input.count(",") == 1):
        month_day, year = date_input.split(",")
        month, day = month_day.split(" ")
        # handle invalid month
        if month not in valid_month:
            raise ValueError
        else:
            month = valid_month.index(month) + 1
            day = int(day)
            year = int(year)
    else:
        raise ValueError

    # Checking month, day, year are valid numbers
    if not (month in range(1, 13) and day in range(1, 32) and year in range(0, 10000)):
        raise ValueError
    else:
        print(f"{year:04}-{month:02}-{day:02}")
        return


main()
