#include <stdio.h>
#include <stdlib.h>

void dualSearch (int[],int, int, int[]);

int main()
{
    int i,size,K;
    int* A;
    int index[2] = {-1,-1};

    //Search key
    scanf("%d",&K);

    //create an array
    scanf("%d",&size);
    A=(int *)malloc(sizeof(int)*size);
    for(i=0; i<size; i++)
    {
        scanf("%d",&A[i]);
    }

    //A is array of number
    //size is given by user
    //k is the search key, ie the target value for 2 elements to add up to

    dualSearch(A,size,K,index);

    if(index[0]!=-1)
        printf("%d %d\n",index[0], index[1]);
    else
        printf("Not found");

    free(A);
    return 0;
}

void dualSearch(int A[], int size, int K, int dualIndex[])
{
   // Write your code here
   //not returning anything,simply comparing time taken
   for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
        if(A[i]+A[j]==K){
        dualIndex[0]=i;
        dualIndex[1]=j;
        return;
        }
        
    }
   }

}
