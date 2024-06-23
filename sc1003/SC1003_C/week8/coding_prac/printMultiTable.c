#include <stdio.h>

int main(void)
{
    int user =0;
   do
   {
       printf("Enter a number (between 1 and 9):\n");
       scanf("%i",&user);
   }
   while(user<1 || user>9);
   
   printf("Multiplication Table:\n");
   
   printf(" ");
   for(int i=1;i<=user;i++)
   {
       printf("%d ",i);
   }
   printf("\n");
   
   for(int i=1;i<=user;i++)
   {
       printf("%d ",i);
       for(int j =1;j<=i;j++)
       {
           printf("%d ",i*j);
       }
       printf("\n");
   }

   return 0;
}