light_speed = 300000000


def main():
    user_input = int(input("m: "))
    print(f"E: {energy(user_input)}")


def energy(m):
    return m * pow(light_speed, 2)


main()
