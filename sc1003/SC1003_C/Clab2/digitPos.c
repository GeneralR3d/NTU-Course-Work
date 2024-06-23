	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
int digitPos1(int num, int digit);
void digitPos2(int num, int digit, int *result);
int main()
{
   int number, digit, result=0;

   printf("Enter the number: \n");
   scanf("%d", &number);
   printf("Enter the digit: \n");
   scanf("%d", &digit);            
   printf("digitPos1(): %d\n", digitPos1(number, digit));           
   digitPos2(number, digit, &result);          
   printf("digitPos2(): %d\n", result);   
   return 0;
}
int digitPos1(int num, int digit) 
{
	/*edit*/
   /* Write your code here */
   int position =1,extracted=0;
   while(num>0)
   {
       extracted = num%10;
       num/=10;
       if(extracted==digit)
       {
           return position;
       }
       else
       {
           position++;
       }
   }
   return 0;


	/*end_edit*/
}
void digitPos2(int num, int digit, int *result) 
{
	/*edit*/
   /* Write your code here */
   int position =1,extracted=0;
   while(num>0)
   {
       extracted = num%10;
       num/=10;
       if(extracted==digit)
       {
           *result= position;
           return;
       }
       else
       {
           position++;
       }
   }
   *result =0;
   return;

	/*end_edit*/
}

/*SUGGESTED SOLUTIONS

int digitPos1(int num, int digit)
{
    int pos =0;
    do
    {
        pos++
        if(num%10 == digit)
        {
            return pos;
        }
        num = num/10;
    }(while num>0)
    return 0;
}*/