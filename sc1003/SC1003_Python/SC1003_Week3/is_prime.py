print("Welcome! Find if numbers are prime. Press fullstop to exit")
num = ""

while num != ".":
    num = input("Enter a number: ")
    try:
        num = int(num)
    except ValueError:
        print("Not a number!")
    else:
        for divisor in range(2,int(num/2)+1):
            if num%divisor == 0:
                print("The number is not prime!")
                break
        else: 
            print("The number is prime!")
            

print("Thanks for playing!")
