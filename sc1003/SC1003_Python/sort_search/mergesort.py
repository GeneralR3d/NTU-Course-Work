"""
merge sort
TAKE NOTE THIS VERSION IS NOT REALLY nlogn, THE TIME COMPLEXITY IS RUINED BY PYTHON BUILT IN FUNCTIONS LIKE POP(i) AND LIST SLICING
TO ACHIEVE THE TRUE THEORETICAL TIME COMPLEXITIES IN PYTHON, BUILT IN FUNCTIONS/METHODS SHOULD BE AVOIDED
way way faster than bubble sort like 33 times faster for a 5000 element list
but sort() method in built is still faster by about 15-20%

NOTE THAT IN THIS VERSION THE time.time() TIMER STARTS EVEN BEFORE THE PROGRAM READS THE WHOLE FILE INTO MEMORY SO THE TIME IS NOT ACCURATE

"""
#time module for time.time()
import time
import sys

def main():
    with open(sys.argv[1],"r") as file:
        array = []
        

        #writing every line from file into list, still in disordered manner
        for line in file:
            array.append(int(line))

        #print disordered array
        #print(array)

        sorted = mergesort(array)
        #array.sort()#this is still around 15-20% faster
        
        print(sorted)

    
def mergesort(array):
    if len(array) == 1:
        return array
    else:
        final =[]
        firsthalf = array[:len(array)//2]
        secondhalf = array[len(array)//2:]
        sub1 = mergesort(firsthalf)
        sub2 = mergesort(secondhalf)

    while True:
        if len(sub1) == 0:
            #final.extend(sub2) #seems like theres no difference between using list methods and just using + operator
            final += sub2
            return final
        elif len(sub2) == 0:
            #final.extend(sub1) #seems like theres no difference between using list methods and just using + operator
            final += sub1
            return final
        if sub1[0] > sub2[0]:
            final.append(sub2.pop(0))
        else:
            final.append(sub1.pop(0))








start_time = time.time()
if __name__ == "__main__":
    main()
print("--- %s seconds ---" % (time.time() - start_time))