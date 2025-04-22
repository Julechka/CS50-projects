while True:
    n = int(input("Height: "))
    if n > 0:
        break
for _ in range(n):
    print("#")

# with cs50 library:
import cs50
while True:
    n = cs50.get_int("Height: ")
    if n > 0:
        break
for _ in range(n):
    print("#")

# printing horisontal
for _ in range(4):
    print("?", end="")
print()

# or use multiplication in print:
print("%" * 5)

# print blocks:
for _ in range(3):
    print("#" * 5)



