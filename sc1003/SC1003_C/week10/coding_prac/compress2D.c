	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
#define SIZE 100
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize);
int main() 
{
   int data[SIZE][SIZE];
   int i,j;
   int rowSize, colSize;

   printf("Enter the array size (rowSize, colSize): \n");
   scanf("%d %d", &rowSize, &colSize); 
   printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
   for (i=0; i<rowSize; i++)
      for (j=0; j<colSize; j++)
         scanf("%d", &data[i][j]);     
   printf("compress2D(): \n");
   compress2D(data, rowSize, colSize);
   return 0;
}
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize) 
{
	/*edit*/
   /* Write your code here */
   //variables for original array, to store the current number and how many times it has occured, repeat for each row
   int current=-1;
   int currentCount=1;//initialise to 1 not 0, as its comparing starting from 2nd element, whether is same as first
   
   //variables for compressed row, to mark the start of a new sequence of numbers and its occurence
   int markForNewSequence=-1;
   int compressedRow[2*colSize];
   
   //set whole compressed row to 0
//    for(int k=0;k<2*colSize;k++)
//        {
//            compressedRow[k]=0;
           
//        }
   
   //repeat for each row, each row is the same
   for(int i=0;i<rowSize;i++)
   {
       //set current to the first element,
       current=data[i][0];
       markForNewSequence=0;
       currentCount=1;
       //copy the current number to the compressed row at the new position
       compressedRow[markForNewSequence]=current;
       for(int j=0;j<colSize-1;j++)
       {
           if(data[i][j+1]==current)
           {
            
               currentCount++;//if the number is equal to the current sequence just increment count and move on
           }
           else
           {
               compressedRow[markForNewSequence+1]=currentCount;//record down the occurence into the compressed row
               currentCount=1;//reset counter
               current=data[i][j+1];//reset current number to the new one which broke the sequence
               markForNewSequence+=2;
               compressedRow[markForNewSequence]=current;
           }
           compressedRow[markForNewSequence+1]=currentCount;
       }

       
       //for printing the compressed row
       for(int k=0;k<2*colSize;k++)
       {
           if(k<=markForNewSequence+1)
           {
            printf("%d ",compressedRow[k]);
            break;
           }
           
           
       }
       printf("\n");
   }


	/*end_edit*/
}