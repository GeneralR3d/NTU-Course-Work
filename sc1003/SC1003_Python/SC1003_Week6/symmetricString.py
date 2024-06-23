def main():
    user = input("Enter string to make it symmetrical: ")

    print(symmetricString(user))

def symmetricString(a_str):
    if len(a_str) == 1:
        return a_str + a_str
    else:
        return a_str[0] + symmetricString(a_str[1:]) + a_str[0]
        
def symmetricString2(a_str):
    suffix = reverser(a_str)

    return a_str + suffix

def reverser(a_str):
    if len(a_str)==1:
        return a_str
    else:
        new_str = reverser(a_str[1:]) + a_str[0]
    return new_str

if __name__ == "__main__":
    main()