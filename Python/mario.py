from cs50 import get_int
# Printing a pyramid, valid n is from 1 to 8
while True:
    n = get_int("Height: ")
    if n > 0 and n < 9:
        break
# Printing pyramid with a two spaces gap
for i in range(0, n):
    print(" " * (n - i - 1) + "#" * (i + 1) + "  " + "#" * (i + 1))
