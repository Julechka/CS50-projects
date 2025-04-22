n = input("Input n: ")
if n.isnumeric():
    print("Integer.")
else:
    print("Not integer.")

try:
    m = int(input("Input m: "))
except ValueError:
    print("Not integer.")
else:
    print("Integer.")
