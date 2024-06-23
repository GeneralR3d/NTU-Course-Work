import string

bigLetters = string.ascii_uppercase
smallLetters = string.ascii_lowercase
symbols = string.punctuation
numerics = string.digits



goodPassword = True
password = input("Enter a password: ")

#check for length of at least 8
if len(password) < 8:
    goodPassword = False
    print("Your password should be at least 8 characters long!")

#check for uppercase letter
for bigLetter in bigLetters:
    if password.find(bigLetter) != -1:
        break
else:
    goodPassword = False
    print("Please include at least one uppercase letter!")
    
#check for lowercase letter
for smallLetter in smallLetters:
    if password.find(smallLetter) != -1:
        break
else:
    goodPassword = False
    print("Please include at least one lowercase letter!")

#check for symbols
for symbol in symbols:
    if password.find(symbol) != -1:
        break
else:
    goodPassword = False
    print("Please include at least one special character!")

#check for numbers
for numeric in numerics:
    if password.find(numeric) != -1:
        break
else:
    goodPassword = False
    print("Please include at least one number!")

#final display message and quit part
if goodPassword == True:
    exit("Good Job! Your password is secure.")
    
else:
    exit("Please think of a new one and try again.")
    
'''
Alternative is to use is.digit(), is.lower(), is.upper() for each char in password. Then have 1 bool to represent each.

hasUpper
hasLower
hasDigit

length = len(password)

strong = hasUpper and hasLower and hasDigit and length>8

if strong:
    print("password is good")
else:
    print("password is bad")

'''




