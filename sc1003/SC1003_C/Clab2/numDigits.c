	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
int numDigits1(int num);
void numDigits2(int num, int *result);
int main()
{
   int number, result=0;
   
   printf("Enter the number: \n");
   scanf("%d", &number);
   printf("numDigits1(): %d\n", numDigits1(number));   
   numDigits2(number, &result);
   printf("numDigits2(): %d\n", result);           
   return 0;
}
int numDigits1(int num)
{
	/*edit*/
   /* Write your code here */
    if(num==0)
    {
    return 1;
    }
    
   int count =0;
   while(num>0)
   {
       num/=10;
       count++;
   }
    return count;

	/*end_edit*/
}
void numDigits2(int num, int *result)
{
	/*edit*/
   /* Write your code here */
   if(num==0)
   {
    *result =1;
   return;
   }
    
   int count =0;
   while(num>0)
   {
       num/=10;
       count++;
   }
    *result = count;
    return;
	/*end_edit*/
}
//when working with ints, the % operator always gives the remainder of number, and / operator gives the quotient of the number.
//%10 gives the last digit, /10 gives the new number after "popping" off the last digit