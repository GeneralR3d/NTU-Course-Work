#include<stdio.h>

int main(void)
{
        int lines=0;
        printf("Enter number of lines:\n");
        scanf("%d",&lines);
        
        for(int i=1,sum=0,elements=0;i<=lines;i++)
        {
            sum =0;
            printf("Enter line %i:\n",i);
            scanf("%d",&elements);
            for(int j=1;j<=elements;j++)
            {
                int number=0;
                scanf("%d",&number);
                sum += number;
            }

            printf("Total: %d\n",sum);
            
        }
        
        return 0;
}