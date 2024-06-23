#math library for math.inf in minNode()
import math,time

#main opens text file containing 100 numbers ordered randomly
def main():
    with open("random50000.txt","r") as file:

        myCBT = [None,None,None]

        #for every number in file add it to the binary tree
        for line in file:
            myCBT = CBT_creator(myCBT,int(line))

        #custom function not to be confused with print()
        printCBT(myCBT)

        #print results returned from the rest of the functions
        print("{} nodes in TOTAL".format(numOfNodes(myCBT)))
        print("Sum of all numbers in nodes is {}".format(sumNodes(myCBT)))
        print("the biggest node is {}".format(maxNode(myCBT)))
        print("the smallest node is {}".format(minNode(myCBT)))
        
#takes in an existing tree in the form of a list w 3 elements, and an int
#recursively compares the current int with whats already in the tree and finds a place to put it such that its in order
def CBT_creator(tree,int):
    if tree[1] == None:
        tree[1] = int
        return tree
    elif int > tree[1]:
        if tree[2] == None:
            tree[2] = CBT_creator([None,None,None],int)
        else:
            tree[2] = CBT_creator(tree[2],int)
        return tree
    elif int <= tree[1]:
        if tree[0] == None:
            tree[0] = CBT_creator([None,None,None],int)
        else:
            tree[0] = CBT_creator(tree[0],int)
        return tree

#prints the whole binary tree in order from smallest to biggest number
def printCBT(tree):

    if tree == None:
        return
    
    printCBT(tree[0])
    print(tree[1])
    printCBT(tree[2])
    return

#returns number of nodes in binary tree
def numOfNodes(tree):
    
    if tree == None:
        return 0
    else:
        return 1 + numOfNodes(tree[0]) + numOfNodes(tree[2])

#returns the sum of all numbers in all nodes in binary tree
def sumNodes(tree):
    
    if tree == None:
        return 0
    else:
        return tree[1] + sumNodes(tree[0]) + sumNodes(tree[2])

#returns the biggest number in the binary tree by recursively searching and comparing
def maxNode(tree):

    if tree == None:
        return 0
    else:
        return max([maxNode(tree[0]),tree[1],maxNode(tree[2])])

#returns the smallest number in the binary tree by recursively searching and comparing
def minNode(tree):

    if tree == None:
        return math.inf
    else:
        return min([minNode(tree[0]),tree[1],minNode(tree[2])])



start_time = time.time()
if __name__ == "__main__":
    main()
print("--- %s seconds ---" % (time.time() - start_time))




