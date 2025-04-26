def main():
    menu_dict = {
        "Baja Taco": 4.25,
        "Burrito": 7.50,
        "Bowl": 8.50,
        "Nachos": 11.00,
        "Quesadilla": 8.50,
        "Super Burrito": 8.50,
        "Super Quesadilla": 9.50,
        "Taco": 3.00,
        "Tortilla Salad": 8.00
    }
    menu_dict = {key.lower(): value for key, value in menu_dict.items()}
    total = 0

    while True:
        # Check the item is in menu, if not continue prompting
        try:
            # Prompting user to add item
            menu_item = input("Item: ").lower()
            total += menu_dict[menu_item]
            print(f"Total: ${total:.2f}")
        except KeyError:
            continue
        except EOFError:
            # If Ctrl+D entered, print total value in $
            print()
            break


main()
