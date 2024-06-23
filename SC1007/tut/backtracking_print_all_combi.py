
s=[1,2,3,4,5]
def main():
    used=[False,False,False,False,False]
    result=[0,0,0,0,0]
    printperm(result,used,0)

def printperm(result,used,position):
    #print(result,"received at position",position)
    if position>4:
        return
    for i in range(len(s)):
        if used[i]==False:
            used[i]=True
            result[position]=s[i]
            printperm(result,used,position+1)
            if 0 not in result:
                print(result)
            result[position]=0
            used[i]=False
    return
    
if __name__=="__main__":
    main()


