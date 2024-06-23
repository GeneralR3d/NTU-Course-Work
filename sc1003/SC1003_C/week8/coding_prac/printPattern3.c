#include<stdio.h>

int main(void)
{
    /* Write your code here */
    int user =0;
   printf("Enter the height:\n");
   scanf("%d",&user);
   
   printf("The pattern is:\n");
   for(int i=1;i<=user;i++)
   {
       for(int j =1,n=i;j<=i;j++,n++)
       {
           
           printf("%d",n%10);
        
       }
       printf("\n");
   }
   return 0;
}