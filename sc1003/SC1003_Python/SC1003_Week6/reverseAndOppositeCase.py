from curses.ascii import isupper


def main():
    user = input("Enter string to reverse and flip the case: ")

    print(reverseAndOppositeCase(user))

def reverseAndOppositeCase(a_str):
    if len(a_str) == 1:
        if a_str.isupper():
            return a_str.lower()
        else:
            return a_str.upper()

    else:
        if a_str[0].isupper():
            new_char = a_str[0].lower()
        else:
            new_char = a_str[0].upper()
        return reverseAndOppositeCase(a_str[1:]) + new_char

def reverseAndOppositeCase2(a_str):
    reversedStr = reverser(a_str)

    resultStr = ""
    for i in range(len(reversedStr):
        if reversedStr[i].isupper():
            resultStr = resultStr + reversedStr[i].lower()
        else:
            resultStr = resultStr + reversedStr[i].upper()

    return resultStr

def reverser(a_str):
    if len(a_str)==1:
        return a_str
    else:
        new_str = reverser(a_str[1:]) + a_str[0]
    return new_str


    
if __name__ == "__main__":
    main()