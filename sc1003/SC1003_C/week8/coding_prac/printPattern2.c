#include<stdio.h>

int main(void)
{
    int user =0;
   printf("Enter the height:\n");
   scanf("%d",&user);
   
   
   for(int i=1;i<=user;i++)
   {
       for(int j =1;j<=i;j++)
       {
           if(i%2==0)
           {
               if(j%2==0)
               {
                   printf("A");
               }
               else
               {
                   printf("B");
               }
           }
           else
           {
               if(j%2==0)
               {
                   printf("B");
               }
               else
               {
                   printf("A");
               }
           }
        
       }
       printf("\n");
   }
   return 0;
}