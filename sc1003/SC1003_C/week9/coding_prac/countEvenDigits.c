	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
int countEvenDigits1(int number);
void countEvenDigits2(int number, int *count);
int main()
{
   int number, result;
   
   printf("Enter a number: \n");
   scanf("%d", &number);
   printf("countEvenDigits1(): %d\n", countEvenDigits1(number));
   countEvenDigits2(number, &result);
   printf("countEvenDigits2(): %d\n", result);
   return 0;
}
int countEvenDigits1(int number) 
{  
	/*edit*/
   /* Write your code here */
       int extracted=0,counter=0;
   while(number>=1)
   {
       extracted = number%10;
       number/=10;
       if(extracted%2==0)
       {
           counter++;
       }
       
   }
  return counter;


	/*end_edit*/
}
void countEvenDigits2(int number, int *count) 
{  
	/*edit*/
   /* Write your code here */
    int extracted=0,counter=0;
   while(number>=1)
   {
       extracted = number%10;
       number/=10;
       if(extracted%2==0)
       {
           counter++;
       }
       
   }
  *count = counter;
  return;


	/*end_edit*/
}