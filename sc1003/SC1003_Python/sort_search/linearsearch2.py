"""
linear search,
sorted or unsorted, sorted will be faster tho, for alphabets, not here
uses command line arguments, no need wait for user to type which causes greater variability
"""
#time module for time.time()
import time
import sys


if len(sys.argv) != 3:
    print("Usage: python scriptName textfile numberToSearch")
    #return
try:
    user = int(sys.argv[2])
except ValueError:
    print("Not found! Not even number lor")
    #return


with open(sys.argv[1]) as file:
    array = []
    

    #writing every line from file into list, still in disordered manner
    for line in file:
        array.append(int(line))

def main():   
        #actual searching part
        for num in array:
            if num == user:
                print("Found")
                return
        else:
            print("Not found!")






start_time = time.time()
main()
print("--- %s seconds ---" % (time.time() - start_time))