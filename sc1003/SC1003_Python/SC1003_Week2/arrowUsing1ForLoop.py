while True:
    try:
        userInput = int(input("Please enter pattern width: "))
    except ValueError:
        print("Please enter a valid number!")
    else:
        if userInput > 0 and userInput <1000:
            break

hasPassedMax = False
for height in range(1,2*userInput):
    if hasPassedMax == False:
        print("*" * height)
    else:
        print("*" * (2*userInput - height))
    
    if height == userInput:
        hasPassedMax = True