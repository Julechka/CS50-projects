from cs50 import get_float

# Accepting only positive number as input
while True:
    amount = get_float("Change: ")
    if amount > 0:
        break
# converting amount to cents and converting to int
amount = round(amount * 100)

# initializing coins count
count = 0

# counting coins
for coin in [25, 10, 5, 1]:
    coin_count = amount // coin
    count += coin_count
    amount = amount % coin

print(count)
