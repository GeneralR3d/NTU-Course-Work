"""
bubble sort using python built in list methods, turns out its about 3x as slow as using c method of indexing, copying into temp and copying back

"""
#time module for time.time()
import time
import sys

def main():
    with open(sys.argv[0]) as file:
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
                    temp = array.pop(i) #using list methods is about 3x as slow as using c method of indexing, copying into temp and copying back
                    array.insert(i+1,temp)
                    swaps += 1 # swaps counter
                    need_swap = True # flag for saying a swap happened during the pass

                else:
                    pass #if no swaps happened, flag will remain as false and the while loop will terminate
 
        print(array)
        print(swaps)

start_time = time.time()
main()
print("--- %s seconds ---" % (time.time() - start_time))