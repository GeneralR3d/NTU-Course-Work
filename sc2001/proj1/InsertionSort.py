def insertionSort(array):
    for i in range(1,len(array),1):
        for j in range(i,0,-1):
            if array[j]< array[j-1]:
                array[j],array[j-1]=array[j-1],array[j]
            else:
                break

def main():

    array=[9,15,3,5,6,32,44,12,11,2]
    insertionSort(array)
    print(array)

    
if __name__ == "__main__":
    main()