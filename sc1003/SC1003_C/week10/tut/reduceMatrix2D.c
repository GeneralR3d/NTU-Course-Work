#include <stdio.h>
#define SIZE 10
void reduceMatrix2D(int ar[][SIZE], int rowSize, int colSize);
int main()
{
   int ar[SIZE][SIZE]={0};
   int rowSize, colSize;
   int i, j,tmp;
   
   do
   {
    printf("Must be a square matrix for upper triangular to be defined!\n");
    printf("Enter row size of the 2D array: \n");
    scanf("%d", &rowSize);
    printf("Enter column size of the 2D array: \n");
    scanf("%d", &colSize);
   }
   while(rowSize!=colSize);



   printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
   for (i=0; i<rowSize; i++)
      for (j=0; j<colSize; j++)
         scanf("%d", &ar[i][j]);

   reduceMatrix2D(ar, rowSize, colSize);


   //print reduced matrix 
   printf("Reduced matrix (%dX%d):\n",rowSize,colSize);
      for (i=0; i<rowSize; i++)
      {
        for (j=0; j<colSize; j++)
            printf("%d ", ar[i][j]);
        printf("\n");
      }
}

void reduceMatrix2D(int ar[][SIZE], int rowSize, int colSize)
{
    int sum=0;
    for(int j=0;j<colSize;j++)
    {
        sum=0;
        for(int i =0;i<rowSize;i++)
        {
            if(i>=j)
            {
            sum+=ar[i][j];
            ar[i][j]=0;
            }
        }
        ar[j][j]=sum;
    }
}

//SUGGESTED SOLUTIONS
void reduceMatrix2D(int matrix[][SIZE], int rowSize, int colSize)
{
    int i,j, sum;

    for(j=0;j<colSize;j++)
    {
        sum=0;
        for(i=j+1;i<rowSize;i++)
        {
            sum+=matrix[i][j];
            matrix[i][j]=0;
        }
        matrix[j][j] += sum;
    }
}