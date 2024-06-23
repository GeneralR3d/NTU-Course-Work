"""
Using c method of indexing, copying into temp and copying back
Much faster than using python built in list methods, 3x faster
this uses nested for loops to reduce the number comparisons on subsequent passes as the list gets more and more sorted
better than bubble sort
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
        #print(array)

        #n passes for n elements in array, each time building the smallest element
        for unsorted_start in range(len(array)):
            #unsorted_start increases every pass means the part that is unsorted gets smaller with each pass;lesser and lesser comparisons are needed
            current_min_index = unsorted_start

            #inner for loop for finding the smallest element in the unsorted part
            for j in range(unsorted_start,len(array)):
                if array[j] < array[current_min_index]:
                    current_min_index = j #index is copied, not the actual value
                    
            #swapping then increment swap counter
            temp = array[current_min_index]
            array[current_min_index] = array[unsorted_start]
            array[unsorted_start] = temp
            swaps += 1

      

        
        #print(array)
        print(swaps,"swaps")

start_time = time.time()
main()
print("--- %s seconds ---" % (time.time() - start_time))