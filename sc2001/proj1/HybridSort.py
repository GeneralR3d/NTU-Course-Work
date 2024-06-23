"""
combine 
Mergesort with Insertion Sort to come up with a hybrid sorting algorithm for better 
efficiency. The idea is to set a small integer S as a threshold for the size of subarrays. 
Once the size of a subarray in a recursive call of Mergesort is less than or equal to S, 
the algorithm will switch to Insertion Sort, which is efficient for small-sized input
"""
#time module for time.time()
import time
import sys

def main():

    THRESHOLD=5

    with open(sys.argv[1],"r") as file:
        array = []
        

        #writing every line from file into list, still in disordered manner
        for line in file:
            array.append(int(line))

        sorted = hybridSort(array,THRESHOLD)
        
        

    
def hybridSort(array,THRESHOLD):
    if len(array) <=THRESHOLD:
        insertionSort(array)
        return array
    else:
        firsthalf = array[:len(array)//2]
        secondhalf = array[len(array)//2:]
        sub1 = hybridSort(firsthalf,THRESHOLD)
        sub2 = hybridSort(secondhalf,THRESHOLD)
        final=merge(sub1,sub2)
        return final


def merge(sub1,sub2):
    final=[]
    while True:
        if len(sub1) == 0:
            final += sub2
            return final
        elif len(sub2) == 0:
            final += sub1
            return final
        if sub1[0] > sub2[0]:
            final.append(sub2.pop(0))
        else:
            final.append(sub1.pop(0))

def insertionSort(array):
    for i in range(1,len(array),1):
        for j in range(i,0,-1):
            if array[j]< array[j-1]:
                array[j],array[j-1]=array[j-1],array[j]
            else:
                break
        








start_time = time.time()
if __name__ == "__main__":
    main()
print("--- %s seconds ---" % (time.time() - start_time))