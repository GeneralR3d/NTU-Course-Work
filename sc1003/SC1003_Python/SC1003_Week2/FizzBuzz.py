
for number in range(1,21):
    if number % 15 == 0:
        print("FizzBuzz")
    elif number % 5 == 0:
        print("Buzz")
    elif number % 3 == 0:
        print("Fizz")S
    else:
        print(number)
"""



for number in range(1,21):
    is_multiple = False
    if number % 3 == 0:
        print("Fizz")
        is_multiple = True
    if number % 5 == 0:
        print("Buzz")
        is_multiple = True
    
    if is_multiple == False:
        print(number)
    
"""