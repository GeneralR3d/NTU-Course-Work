"""
merge sort
TAKE NOTE THIS VERSION PYTHON BUILT IN FUNCTIONS LIKE POP(i) ARE NOT USED
BUT LIST SLICING IS STILL USED
IS NOT REALLY nlogn, THE TIME COMPLEXITY IS STILL RUINED
TO ACHIEVE THE TRUE THEORETICAL TIME COMPLEXITIES IN PYTHON, BUILT IN FUNCTIONS/METHODS SHOULD BE AVOIDED

also in this version the timer only starts right before calling the sort function itself, and stops right after
even this also not does not solve the problem of list slicing ruining the time complexity

UPDATE: it seems like list slicing doesnt actually affect time complexity, so this is the best version already

"""
#time module for time.time()
import time
import sys
import numpy as np

keyComparisons=0
def main():
    global keyComparisons
    
    keyComparisons=0

    array = np.random.randint(1,512000,512000)
    
    array=array.tolist()

    #sorted = hybridSort(array,THRESHOLD)
    
    start_time = time.time()
    sorted=mergesort(array)
    print("--- %s seconds ---" % (time.time() - start_time))
    
    print("The number of keyComparisons is ",end="")
    print(keyComparisons)

    return keyComparisons

    
def mergesort(array):
    if len(array) == 1:
        return array
    else:
        final =[]
        firsthalf = array[:len(array)//2]
        secondhalf = array[len(array)//2:]
        sub1 = mergesort(firsthalf)
        sub2 = mergesort(secondhalf)
        final=merge(sub1,sub2)
        return final


def merge(left,right):
    global keyComparisons
    final=[]
    leftIndex=0
    rightIndex=0
    length_left=len(left)
    length_right=len(right)
    while leftIndex < length_left and rightIndex < length_right:
        if left[leftIndex] <= right[rightIndex]:
            final.append(left[leftIndex])
            leftIndex+=1
            keyComparisons+=1
        else:
            final.append(right[rightIndex])
            rightIndex+=1
            keyComparisons+=1
        
    #if there are elements left over in left half, just copy over everything
    while leftIndex < length_left:
        final.append(left[leftIndex])
        leftIndex += 1
        
    #if there are elements left over in right half, just copy over everything
    while rightIndex < length_right:
        final.append(right[rightIndex])
        rightIndex += 1
        
    #after everything is done    
    return final





if __name__ == "__main__":
    main()
