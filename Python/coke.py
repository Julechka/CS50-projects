COKE_PRICE = 50


def main():
    # Coke Machine sells bottles of Coke for 50 cents
    # accepts coins in 25 cents, 10 cents, and 5 cents
    # A program  prompts the user to insert a coin, one at a time
    # informes the user of the amount due and change owed.

    amount = COKE_PRICE
    # Check the coin inserted and total sum
    while amount > 0:
        print(f"Amount Due: {amount}")
        coin = int(input("Insert Coin: "))
        if coin in [5, 10, 25]:
            amount -= coin

    print(f"Change Owed: {abs(amount)}")


main()
