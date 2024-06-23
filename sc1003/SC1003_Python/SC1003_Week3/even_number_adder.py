print("Welcome to even number adder! Key in even number to add. Key in fullstop to stop.")

user = ""
sum = 0

while user != ".":
    user = input("Enter a even number: ")
    try:
        user = int(user)
    except ValueError:
        print("Not a number!")
    else:
        if user%2 != 0:
            print("Not a even number!")
            continue

        sum+=user
        print("Added!")
else:
    print(f"Sum of even numbers is {sum}.\nThanks for playing!")

