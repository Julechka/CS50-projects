def main():
    expression = input("Expression: ")
    print(f"{interpret(expression):.1f}")


def interpret(s):
    s = s.split()
    x = float(s[0])
    y = s[1]
    z = float(s[2])

    if y == "+":
        return x + z

    elif y == "-":
        return x - z

    elif y == "/" and z != 0:
        return x / z

    elif y == "*":
        return x * z


main()
