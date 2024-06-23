import random

def main():
    target = four_diff_digits()
    print(target)
    attempt = 0


    while True:

        bulls = 0
        cows = 0
        while True:
            user = input("Please input 4 different digits: ")
            if user.isdigit() and len(user) == 4 and noDuplicates(user):
                break

        attempt += 1
        for digit in user:
            if digit == target[user.index(digit)]:
                bulls += 1
            elif digit in target:
                cows += 1
            else:
                pass
        
        if bulls == 4:
            print("You win!!")
            break
        else:
            print("{} A (Bulls) {} B (Cows)".format(bulls,cows))
            continue

    print("Attempts: {}".format(attempt))




def four_diff_digits():
    while True:
        num = random.randint(0,9999)
        num = str(num)
        num = str(format(num,"0>4"))
        if num.count(num[0]) != 1:
                break
        if num.count(num[1]) != 1:
                break
        if num.count(num[2]) != 1:
                break
        if num.count(num[3]) != 1:
                break
        return num

def noDuplicates(num):
        if num.count(num[0]) != 1:
            return False
        if num.count(num[1]) != 1:
            return False
        if num.count(num[2]) != 1:
            return False
        if num.count(num[3]) != 1:
            return False

        return True    








def diff_digits(no_of_digits):

    while True:
        num = random.randint(0,int("9"*no_of_digits))
        num = str(num)
        x = no_of_digits
        num = str(format(num,"0>x"))
        for i in range(no_of_digits):
            if num.count(num[i]) != 1:
                break
        else:
            return num

if __name__ == "__main__":
    main()


