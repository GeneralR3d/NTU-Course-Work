while True:
    try:
        userInput = int(input("Please enter pattern width: "))
    except ValueError:
        print("Please enter a valid number!")
    else:
        if userInput > 0 and userInput <1000:
            break


for height in range(1,userInput):
    print("*" * height)

print("*" * userInput)

for height in range(userInput-1,0,-1):
    print("*" * height)