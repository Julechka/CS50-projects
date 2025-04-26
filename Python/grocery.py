def main():
    grocery_list = []
    while True:
        try:
            item_input = input()
            grocery_list.append(item_input.upper())

        except EOFError:
            # If Ctrl+D entered, print sorted and numbered list
            break
    # Printing list with counts
    grocery_dict = count_items(grocery_list)
    for item, count in sorted(grocery_dict.items()):
        print(f"{count} {item}")


def count_items(grocery_list):
    # Create a dictionary, where the key will be the item and value is a count
    grocery_dict = {}
    for item in grocery_list:
        if item in grocery_dict:
            grocery_dict[item] += 1
        else:
            grocery_dict[item] = 1
    return grocery_dict


main()
