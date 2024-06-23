#include <stdio.h>
#define SIZE 10
void transpose2D(int ar[][SIZE], int rowSize, int colSize);
int main()
{
   int ar[SIZE][SIZE]={0};
   int rowSize, colSize;
   int i, j,tmp;
   
   printf("Enter row size of the 2D array: \n");
   scanf("%d", &rowSize);
   printf("Enter column size of the 2D array: \n");
   scanf("%d", &colSize);


   printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
   for (i=0; i<rowSize; i++)
      for (j=0; j<colSize; j++)
         scanf("%d", &ar[i][j]);

   transpose2D(ar, rowSize, colSize);
   //swap dimensions of new matrix
    tmp=rowSize;
    rowSize=colSize;
    colSize=tmp;

   //print tranposed array 
   printf("Transposed matrix (%dX%d):\n",rowSize,colSize);
      for (i=0; i<rowSize; i++)
      {
        for (j=0; j<colSize; j++)
            printf("%d ", ar[i][j]);
        printf("\n");
      }
}

void transpose2D(int ar[][SIZE], int rowSize, int colSize)
{
    int temp=0;
    for (int i=0; i<rowSize; i++)
    {
        for (int j=0; j<colSize; j++)
        {   
            if(i<j)
            {
                temp= ar[i][j];
                ar[i][j]=ar[j][i];
                ar[j][i]=temp;
            }
        }
         
    }
      
}

//SUGGESTED SOLUTIONS
void transpose2D(int ar[][SIZE], int rowSize, int colSize)
{
    int h,k;
    int temp;
    for(h=1;h<rowSize;h++)//traverse row starting from row 2, as row 1 index 0 the first element is on the diagonal
    {
        for(k=0;k<h;k++)//process coloumn for k<h
        {
            temp=ar[h][k];
            ar[h][k]=ar[k][h];
            ar[k][h]=temp;
        }
    }
}