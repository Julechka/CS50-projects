def main():
    user_time = input("What time is it? ")

    if user_time.endswith("m."):
        user_time = convert_12_hour_format(user_time)
    else:
        user_time = convert(user_time)

    # Printing results
    if 7.0 <= user_time <= 8.0:
        print("breakfast time")
    elif 12.0 <= user_time <= 13.0:
        print("lunch time")
    elif 18.0 <= user_time <= 19.0:
        print("dinner time")


def convert_12_hour_format(time):
    # splitting the input
    time = time.split(":")

    if time[1].endswith("p.m."):
        time[0] = int(time[0]) + 12
    else:
        time[0] = int(time[0])

    time[1] = int(time[1].split()[0])

    return float(time[0] + time[1] / 60)


def convert(time):
    time = time.split(":")
    return float(int(time[0]) + (int(time[1]) / 60))


if __name__ == "__main__":
    main()
