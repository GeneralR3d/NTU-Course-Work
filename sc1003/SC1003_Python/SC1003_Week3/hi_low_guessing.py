import random, sys

num = 0
random.seed()
target = random.randint(0,100)
while True:
    num = input("Enter a number between 0 and 100 to guess the number! ")
    try:
        num = int(num)
    except ValueError:
        print("KEY in a NUMBER!!")
    else:
        if num < 0 or num > 100:
            print("KEY in a NUMBER from 0 to 100!!")
            continue
        if num == target:
            print("Congrats you are a legend!")
            break
        elif num > target:
            print("Lower!")
        else:
            print("Higher!")

print("Thank you for playing this game")
sys.exit(0)
        
    
    
        

