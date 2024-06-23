########################################################
from curses.ascii import isdigit
import random
from unittest import result
WIDTH = 4
numList = [1,2,3,4,5,6,7,8,9,0]
########################################################
#functionality
#input
#numList : the list w 10 digits
#count : the number of digits to generate
#output : a list w four digits(integers)

def genNumbers(numList,count):
    random.shuffle(numList)
    numbers = []

    for i in range(count):
        numbers.append(numList[i])

    return numbers

#functionality : obtain the guessing from users
#input : None
#output : a list w four digits(integers)

def userGuess():
    inputStr = input("Please input 4 digits: ")
    while inputStr.isdigit() == False or len(inputStr) != WIDTH:
        inputStr = input("Wrong format!! Please input 4 digits: ")

    guess = []

    for i in range(WIDTH):
        num = int(inputStr[i])
        guess.append(num)
    
    return guess


answer = genNumbers(numList,WIDTH)
attempts = 0

while True:
    guesses = userGuess()
    attempts += 1

    result = checkGuess(guesses,answer)

    if result[0] = WIDTH:
        print("you win!!")
        print("Attempts: ",attempts)`
        break
    else: 
        print(result[0],"A (bulls)",result[1],"B (cows)")
