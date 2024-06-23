#include <stdio.h>
#include <stdlib.h>
#define MIN(a,b) ((a)<(b)?a:b)
/*
int waysToScore(int n, int* score)
{   //linear time means can only use bottom up dynamic programming w memoization using a 1D array
    //write your code here

    //init
    int arraySize=n+1;
    int* array=(int*)malloc(sizeof(int)*arraySize);//size n+1 since we are starting the array from 1-index
    for(int i=0;i<arraySize;i++) array[i]=0;

    //init the 2 bases 3 and 5
    array[3]=1;
    array[5]=1;
    for(int i=1;i<=arraySize;i++){
        if(i<6) continue;
        int minusthree= i-3;
        int minusfive=i-5;
        int minusten= i-10;
        if(minusthree>=0) array[i]=array[i]+array[minusthree];//the no of ways to reach any particular n is the sum of the num of ways to reach of the -3,-5,-10 scores
        if(minusfive>=0) array[i]=array[i]+array[minusfive];
        if(minusten>=0) array[i]=array[i]+array[minusten];
    }
    return array[n];
    free(array);

}


int waysToScore(int n, int* score){
    int* arr;
    arr = (int*) malloc(sizeof(int)*n);
    int i;
    for(i=0;i<n;i++) arr[i]=0;

    arr[0] = 1;

    for(i=1;i<=n;i++)
    {
        if(i-score[0]>=0) arr[i] += arr[i-score[0]];
        if(i-score[1]>=0) arr[i] += arr[i-score[1]];
        if(i-score[2]>=0) arr[i] += arr[i-score[2]];
    }

    return arr[n];

}
*/


//Recursive approach
int waysToScore(int n,int* score)
{
   if(n<0) return 0;
   if(n==0) return 1;

   return waysToScore(n-score[0],score) +
          waysToScore(n-score[1],score) +
          waysToScore(n-score[2],score);

}

 
void main ()
{
    int n;

    int score[3] = {3,5,10}; 

    printf("Enter the value of N: ");
    scanf("%d",&n);


    printf("The number of ways to reach to a score of %d is: %d \n",n, waysToScore(n,score));
}
