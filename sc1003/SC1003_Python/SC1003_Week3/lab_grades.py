import random

random.seed()
lab = {}

for index in range(1,41):
    lab[("FE2",index)] = random.randint(1,100) #wah, you can just do random string concat in the middle of nowhere sia

print(lab[("FE2",1)])

"""
while True:
    Search = input("Key in the index number of the student you want to search: ")
    try:
        print(f"Score is {lab[Search]}")
    except KeyError:
        print("Invalid index number")
    else:
        exit("Sucess")

"""

'''
Solution is to use dictionary of tuples,each tuple containing class group number and index number

grades ={
("FE2",01):score
("FE2",02):score
("FE2",03):score
}

'''