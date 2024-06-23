list = []
for i in range(1,101):
    if (i**2)%3 == 0:
        list.append(i ** 2)
print(list)

list1 = [x**2 for x in range(1,101) if (x**2)%3 == 0] #the one line version, super concise, alot of logic can be put into a single line in python
