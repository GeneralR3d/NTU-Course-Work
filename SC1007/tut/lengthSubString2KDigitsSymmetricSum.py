s=[1,2,3,4,5,6,7]
def main():
    longestEven=len(s)-(len(s)%2)
    store={}
    for i in range(2,longestEven+1,2):
        store[i]=[]
    print(store)
#def longestSubString(s):



    

main()