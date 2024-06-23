	/*edit*/

/*custom header*/
//seems like diagonal can only be calculated if its a square matrix,so rowSize must == colSize, no need 2 size parameters
	/*end_edit*/
#include <stdio.h>
#define SIZE 10
void diagonals2D(int ar[][SIZE], int rowSize, int colSize, int *sum1, int *sum2);
int main()
{
   int ar[SIZE][SIZE], rowSize, colSize;
   int i, j, sum1=0, sum2=0;
   
   printf("Enter row size of the 2D array: \n");
   scanf("%d", &rowSize);
   printf("Enter column size of the 2D array: \n");
   scanf("%d", &colSize);
   printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
   for (i=0; i<rowSize; i++)
      for (j=0; j<colSize; j++)
         scanf("%d", &ar[i][j]);
   diagonals2D(ar, rowSize, colSize, &sum1, &sum2);
   printf("sum1=%d; sum2=%d\n",sum1,sum2);
}
void diagonals2D(int ar[][SIZE], int rowSize, int colSize, int *sum1, int *sum2)
{
	/*edit*/
	/* Write your code here */
	for(int i=0;i<rowSize;i++)
	{
	    for(int j=0;j<colSize;j++)
	    {
	        // the 2 if conditions should not be if-else, should not be mutually exclusive, 
	        //as there is one case that satisfies both, ie in odd square matrices, the middle elements belongs to both sum1 and sum2
	        if(i==j)
	        {
	            *sum1+=ar[i][j];
	        }
	        if (i+j==rowSize-1||i+j==colSize-1)
	        {
	            *sum2+=ar[i][j];
	        }
	    }
	}
	return;


	/*end_edit*/
}