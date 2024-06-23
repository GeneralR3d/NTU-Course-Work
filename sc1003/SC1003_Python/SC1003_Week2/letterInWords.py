count = 0
str_sentinal = input("Enter a string (enter #### to stop): ")

while str_sentinal != "####":
    for letter in str_sentinal:
        if letter == "a":
            count +=1
            break
    str_sentinal = input("Enter a string (enter #### to stop): ")

print(count, "strings with letter 'a' ")