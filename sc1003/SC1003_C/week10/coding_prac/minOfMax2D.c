	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
#define SIZE 10
int minOfMax2D(int ar[][SIZE], int rowSize, int colSize);
int main() 
{
   int ar[SIZE][SIZE], rowSize, colSize;
   int i,j,min;
   
   printf("Enter row size of the 2D array: \n");
   scanf("%d", &rowSize);
   printf("Enter column size of the 2D array: \n");
   scanf("%d", &colSize);
   printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
   for (i=0; i<rowSize; i++)
      for (j=0; j<colSize; j++)
         scanf("%d", &ar[i][j]);
   min=minOfMax2D(ar, rowSize, colSize);
   printf("minOfMax2D(): %d\n", min);
   return 0;
}
int minOfMax2D(int ar[][SIZE], int rowSize, int colSize)
{
	/*edit*/
   /* Write your code here */
   int rowmax=0,globalmin=10*9;
   for(int i=0;i<rowSize;i++)
   {
       rowmax=ar[i][0];
       for(int j=0;j<colSize;j++)
       {
           if(ar[i][j]>rowmax)
           {
               rowmax=ar[i][j];
           }
       }
       if(rowmax<globalmin)
       {
           globalmin=rowmax;
       }
   }
   return globalmin;


	/*end_edit*/
}
/* SUGGESTED SOLUTIONS
int minOfMax2D(int ar[][SIZE], int rowSize, int colSize)
{
    int row, col,max,min;
    for(row=0;row<rowSize;row++)
    {
        max=ar[row][0];
        for(col=1;col<colSize;col++)
        {
            if(ar[row][col]>max)
            {
                max=ar[row][col];
            }
        }
        if(row==0)
        {
            min=max;
        }
        else if(max<min)
        {
            min=max;
        }
    }
    return min;
}
*/