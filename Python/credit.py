from cs50 import get_int
import sys

# Prompting card number input
card_num = get_int("Number: ")

# Converting a card number to a string for slicing
card_str = str(card_num)

# Accepting only positive number of 13, 15 or 16 digits
if card_num <= 0 or len(card_str) not in [13, 15, 16]:
    print("INVALID")
    sys.exit(1)

# Implementing Luhn’s Algorithm:

# computing sum of alternating digits starting from second-to-last multiplied by 2
control_sum = 0
for i in card_str[-2::-2]:
    double = int(i) * 2
    if double <= 9:
        control_sum += double
    else:
        control_sum += double - 9
# computing control sum
for j in card_str[-1::-2]:
    control_sum += int(j)

# Checking control sum
if control_sum % 10 != 0:
    print("INVALID")
    sys.exit(2)

# check for VISA (13 or 16 digits starts with 4)
if int(card_str[0]) == 4 and len(card_str) in [13, 16]:
    print("VISA")
    sys.exit(0)

# check for Master (16 digits starts with 51, 52, 53, 54, 55)
if int(card_str[:2]) in [51, 52, 53, 54, 55] and len(card_str) == 16:
    print("MASTERCARD")
    sys.exit(0)

# check for American Express (15 digits starts with 34 or 37)
if int(card_str[:2]) in [34, 37] and len(card_str) == 15:
    print("AMEX")
    sys.exit(0)
else:
    print("INVALID")
    sys.exit(3)
