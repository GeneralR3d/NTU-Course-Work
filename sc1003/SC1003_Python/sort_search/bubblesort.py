"""
Using c method of indexing, copying into temp and copying back
Much faster than using python built in list methods, 3x faster
but it uses while loop for number passes which is slower than using nested for loops, around 30% slower
"""
#time module for time.time()
import time
import sys

def main():
    with open(sys.argv[1],"r") as file:
        array = []
        swaps = 0
        need_swap = True #flag for while loop

        #writing every line from file into list, still in disordered manner
        for line in file:
            array.append(int(line))

        #print disordered array
        print(array)

        while need_swap == True:

            need_swap = False #for loop will change this to True if a swap happened

            for i in range(len(array)-1):
                if array[i] > array[i+1]:
                    temp = array[i] #copy larger value to temp
                    array[i] = array[i+1] #copy smaller value to position of larger value, now array has 2 smaller value
                    array[i+1] = temp #copy the larger value from temp to the right of smaller value
                    swaps += 1 # swaps counter
                    need_swap = True # flag for saying a swap happened during the pass

                else:
                    pass #if no swaps happened, flag will remain as false and the while loop will terminate


        # while need_swap == True:

        #     need_swap = False
        #     for number in array:
        #         if number > next(number):
        #             temp = number
        #             number = next(number)
        #             next(number) = temp
        #             swaps += 1
        #             need_swap = True

        #         else:
        #             pass
        
        print(array)
        print(swaps)

start_time = time.time()
main()
print("--- %s seconds ---" % (time.time() - start_time))