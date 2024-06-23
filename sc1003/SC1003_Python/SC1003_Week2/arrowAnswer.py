
#standard way
width = int(input("Please enter pattern width: "))

for i in range(width+1):
    for j in range(i):
        print("*",end="")
    print()

for i in range(width-1,0,-1):
    for j in range(i):
        print("*",end="")
    print()


#using 2 for loops
max = input("Please enter an integer for the maximum width of the pyramid: ")

max_int = int(max)

for count in range(1,max_int+1):
    print(count * "*")

for count in range(max_int-1,0,-1):
    print(count * "*")


#using 1 for loop only
width = int(input("Please enter pattern width: "))

count = 0
for i in range(2*width+1):
    count+=1
    if count<= width+1:
        print("*" * i)
        j = i
    else:
        j-=1
        print("*" * j)