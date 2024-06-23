import random

with open("sorted5000000.txt","w") as file:

    list = []
    # list=[2,1]

    # for i in range(3,5000001):
        
    #     # while True:
    #     #     target = random.randint(1,50000)
    #     #     if target in list:
    #     #         continue
    #     #     else:
    #     #         list.append(target)
    #     #         break
        
    #     list.insert(random.randint(1,len(list)-1),i)

    for i in range(1,5000001):
        list.append(i)

        



    for num in list:
        file.write(str(num))
        file.write("\n")