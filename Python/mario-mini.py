from cs50 import get_int
# Printing a pyramid of n #, accepting n from 1 to 8
while True:
    n = get_int("Height: ")
    if n > 0 and n < 9:
        break
for i in range(0, n):
    print(" " * (n - i - 1) + "#" * (i + 1))
