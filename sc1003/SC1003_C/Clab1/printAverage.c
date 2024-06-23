#include<stdio.h>

int main(void)
{
/* Write your code here */
   int lines=0;
   int user=0;
   int sum =0;
   int count =0;
   
   printf("Enter number of lines:\n");
   scanf("%d",&lines);
   
   for(int i = 1;i<=lines;i++)
   {
       printf("Enter line %d (end with -1): \n",i);
       
       while(1)
       {
       scanf("%d",&user);
       if(user==-1)
       break;
       
       sum+= user;
       count++;
       
       }
       printf("Average = %.2f\n",(float)sum/count);
       sum=0;
       count=0;
   }
   
   return 0;
   
   }
//alternative

int main()
{
    int lines, input,i, total,count;
    double average;

    printf("Enter number of lines:\n");
    scanf("%d",&lines);
    for(i=0;i<lines;i++)
    {
        total =0;
        count=0;
        printf("Enter line %d (end with -1):\n",i+1);
        scanf("%d",&input);
        while (input!=-1)
        {
            total += input;
            count++;
                scanf("%d",&input);

        }
        average=(double)total/(double)count;
        printf("Average = %.2f\n",average);
    }
}