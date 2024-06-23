database = {}

def main():
    print("Welcome to the grading system! ")
    while True:
        print("""Please enter your option:
        1: input record
        2: query a student
        3: list grades in a group
        4: get max in a group
        5: list all group names
        6: exit
        """,end="")

        option = getInt("option: ",1,6)

        if option == 1:
            group = input("Please input the group name: ")
            id = getInt("Please input the student id: ",1,40)
            score = getInt("Please input the score: ",0,100)
            
            if inputRecord(database,group,id,score):
                print("Successful")
                continue
            else:
                print("Unsuccessful")
                continue

        elif option == 2:
            group = input("Please input the group name: ")
            id = getInt("Please input the student id: ",1,40)
            score = query(database,group,id)
            if score == False:
                print("Unsuccessful")
                continue
            else:
                print("Score is {}".format(score))
                print("Successful")
                continue

        elif option == 3:
            group = input("Please input the group name: ")
            scores = listGrades(database,group)
            if scores == False:
                print("Unsuccessful")
                continue
            else:
                print("Scores for {} are {}".format(group,scores))
                print("Successful")
                continue

        elif option == 4:
            group = input("Please input the group name: ")
            maxscore = maxGrade(database,group)
            if maxscore == False:
                print("Unsuccessful")
                continue
            else:
                print("Max score for {} is {}".format(group,maxscore))
                print("Successful")
                continue

        elif option == 5:
            listofkeys = list()
    
            for key in database:
                listofkeys.append(key) 
            
            if len(listofkeys) != 0:
                print(listofkeys)
                print("Successful")
                continue
            else:
                print("Unsuccessful")
                continue

        else:
            exit("End")

def inputRecord(database, group, id, score):
    if database.get(group) == None:
        database[group] = {str(id):score}
    else:
        database[group].update({str(id):score})
    
    return True

def query(database, group, id):
    score = 0
    try:
        score = database[group][str(id)]
    except KeyError:
        return False
    else:
        return score
    
def listGrades(database, group):
    grplist = list()
    try:
        for key in database[group]:
            grplist.append(database[group][key])
    except KeyError:
        return False
    else:
        return grplist


def maxGrade(database, group):
    max = 0
    try:
        for key in database[group]:
            if database[group][key] > max:
                max = database[group][key]
    except KeyError:
        return False
    else:
        return max


def getInt(message,lowerinclusive,upperinclusive):
    while True:
        try:
            number = int(input(message))
        except ValueError:
            print("Only key in numbers from {} to {}".format(lowerinclusive,upperinclusive))
        else:
            if lowerinclusive <= number <= upperinclusive:
                return number
            else:
                print("Only key in numbers from {} to {}".format(lowerinclusive,upperinclusive))

if __name__ == "__main__":
    main()