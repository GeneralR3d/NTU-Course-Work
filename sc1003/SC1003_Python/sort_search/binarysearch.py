"""
binary search requires sorting first
uses command line arguments, no need wait for user to type which causes greater variability
its better to just use linear search as sorting takes signifcantly more time the larger the data set is
mathemically proven that its impossible to sort and search n elements faster than O(n)
"""
#time module for time.time()
import time
import sys

def main():
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


        #sorted = mergesort(array)
        
        if binary_search(array,user,0):
            print("Found!")
        else:
            print("Not Found!")
        return

#my own binary search function that somehow doesnt work, slower than linear search, suspect: list splicing taking up alot of time
def binarySearch(list,target):

    if len(list) == 0:
        return False
    elif len(list) == 1:
        if list[0] == target:
            return True
        else:
            return False
    else:
        middle_index = len(list)//2
        if list[middle_index] == target:
            return True
        elif list[middle_index] < target:
            return binarySearch(list[middle_index+1:],target)#includes middle index+1
        else:
            return binarySearch(list[:middle_index],target)#up to but not including middle index

#binary search provided, does not use list splicing but instead passes the starting and ending search range
def binary_search(items, target, low=0,high=None):
    if high == None:
        high = len(items) -1
    
    if low>high:
        return False
    mid = (low+high)//2

    if target == items[mid]:
        return True
    elif target > items[mid]:
        return binary_search(items,target, low=(mid + 1), high = high)
    else:
        return binary_search(items,target,low = low, high =(mid-1))


#iterative binary search provided
def BinarySearch(items, target):
    #start with entire list
    low =0
    high = len(items) - 1

    #repeatedly subdivide the list in half until the target is found

    while low<= high:

        #locates the middle item of the list
        mid = (low+high) // 2

        #compares middle item with the search key
        if items[mid] == target:
            return True
        
        #target is less than middle item
        elif target < items[mid]:
            high = mid -1
        #target is greater than middle item
        else:
            low = mid + 1

    return False



start_time = time.time()
if __name__ == "__main__":
    main()
print("--- %s seconds ---" % (time.time() - start_time))