names = ["Yulia", "David", "John"]
name = input("Name: ")

for n in names:
    if name == n:
        print("Found")
        break
else:
    print("Not found")

# without "for" loop:
if name in names:
     print("Found")
else:
    print("Not found")

# with dictionary function:
people = [
    {"name": "Julia", "number": "045032458048"},
    {"name": "Dave", "number": "4054808045"},
    {"name": "Joan", "number": "12349874"},
]
name = input("Name: ")
for person in people:
    if person["name"] == name:
        number = person["number"]
        print(f"Found {number}")
        break
else:
    print("Not found")

# another way of using dict:
people = {
    "Juliia": "045032458048",
    "Daves": "4054808045",
    "Joanna": "12349874",
}
name = input("Name: ")
if name in people:
    print(f"Number: {people[name]}")
else:
    print("Not found")
