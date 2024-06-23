def main():
    user = input("Enter string to reverse and double: ")
    while True:
        try:
            num = int(input("How many times to repeat? "))
        except ValueError:
            print("Enter a valid number!")
        else:
            if 0 <num <9999:
                break
    print(reverseAndRepeat(user,num))

def reverseAndRepeat(a_str, num):
    if len(a_str) == 1:
        return num*a_str

    else:
        new_str = reverseAndRepeat(a_str[1:],num) + num * a_str[0]
        return new_str

#iterative method
def reverseAndRepeat2(a_str,num):
    reversedStr = reverser(a_str) #call recursive reverser()
    resultStr = ""
    for i in range(len(reversedStr)):
        resultStr = resultStr + (reversedStr[i]*num)
    
    return resultStr

#reverser to return reversed string
def reverser(a_str):
    if len(a_str)==1:
        return a_str
    else:
        new_str = reverser(a_str[1:]) + a_str[0]
    return new_str

if __name__ == "__main__":
    main()