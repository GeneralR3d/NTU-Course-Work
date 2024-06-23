classOne = list1
classTwo = list2

classOneSum = 0
classTwoSum = 0
classOneMax = 0
classTwoMax = 0

for score in classOne:
    classOneSum += score
    if score > classOneMax:
        classOneMax = score

for score in classTwo:
    classTwoSum += score
    if score > classTwoMax:
        classTwoMax = score

if (classOneSum/classOne.count()) = (classTwoSum/classTwo.count()):
    print("same average score!")
elif (classOneSum/classOne.count()) > (classTwoSum/classTwo.count()):
    print("Class One has higher average score!")
else:
    print("Class Two has higher average score!")

if classOneMax = classTwoMax:
    print("same max score!")
elif classOneMax > classTwoMax:
    print("Class One has higher max score!")
else:
    print("Class Two has higher max score!")

"""
use sum() to sum up all values in a list
sum(list)/len(list) gives avg
use max() to find max value in list

max(avg1,avg2) to find the bigger avg score
max(max(list1),max(list2)) to find the bigger max score from the 2 lists

thus which class has the higher avg and the higher max can be found
"""