import csv


def main():
    # prompting user to input a fruit
    fruit_name = input("Item: ")
    print(get_fruit_calories(fruit_name))


def get_fruit_calories(item):
    with open("table_veg.csv", "r") as fruits:
        table = csv.DictReader(fruits)
        for row in table:
            if row["Fruit"].lower() == item.lower():
                calories = row["Calories"]

    return calories


main()
