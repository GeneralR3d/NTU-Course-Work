sumSq = 0
sumSingle = 0
for i in range(1,160,2):
    sumSq+=(1*i)**2

for i in range(2,161,2):
    sumSingle+=(1*i)**2

print(sumSq-sumSingle)


wordIsValid = False
score = 0

while wordIsValid == False:
    word = input("you better give me a correct word")
    for letter in word:
        if letter in letters:
            wordIsValid = True
        else:
            wordIsValid = False
            break
for letter in word:
    i = ord(letter) - 97
    score+= points[i]
        
    

