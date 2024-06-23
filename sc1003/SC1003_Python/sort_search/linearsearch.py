"""
linear search,
sorted or unsorted, sorted will be faster tho, for alphabets, not here
not good as it uses input() instead of command line arguments, need wait for user to type which causes greater variability
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

        try:
            user = int(input("Key in number to search: "))
        except ValueError:
            print("Not found! Not even a number lor")

        for num in array:
            if num == user:
                print("Found")
                break
        else:
            print("Not found!")






start_time = time.time()
main()
print("--- %s seconds ---" % (time.time() - start_time))