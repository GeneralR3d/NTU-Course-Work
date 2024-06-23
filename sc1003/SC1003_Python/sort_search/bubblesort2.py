"""
Using c method of indexing, copying into temp and copying back
Much faster than using python built in list methods, 3x faster
this uses nested for loops to reduce the number comparisons on subsequent passes as the list gets more and more sorted
this method is around 30% faster than while loop
"""
#time module for time.time()
import time
import sys

def main():
    with open(sys.argv[1],"r") as file:
        array = []
        swaps = 0
        

        #writing every line from file into list, still in disordered manner
        for line in file:
            array.append(int(line))

        #print disordered array
        print(array)

        #number of passes starting from 1st pass til n-1
        for passes in range(1,len(array)):

            #number of comparisons per pass, should get lesser every pass, as the elements at the back of list no need check, alr sorted
            for i in range(len(array)-passes):
                if array[i] > array[i+1]:
                    temp = array[i] #copy larger value to temp
                    array[i] = array[i+1] #copy smaller value to position of larger value, now array has 2 smaller value
                    array[i+1] = temp #copy the larger value from temp to the right of smaller value
                    swaps += 1 # swaps counter
                    

                else:
                    pass #if no swaps happened, do nothing



        
        print(array)
        print(swaps)

start_time = time.time()
main()
print("--- %s seconds ---" % (time.time() - start_time))