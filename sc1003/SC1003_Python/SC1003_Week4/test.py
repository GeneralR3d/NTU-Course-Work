database={
    "FE1":{1:99,2:98,3:97},
    "FE2":{4:96,5:95,6:94},
    "FE3":{'3':90}

}

id = 3
score = 99
if database.get("FE3") != None:
    database["FE3"].update({str(id):score})
else:
    database["FE3"] = {str(id):score}

print(database)