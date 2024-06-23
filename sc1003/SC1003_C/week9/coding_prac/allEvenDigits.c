	/*edit*/

/*custom header*/

	/*end_edit*/
#include  <stdio.h>
int allEvenDigits1(int num); 
void allEvenDigits2(int num, int *result);    
int main()
{
   int number, p=999, result=999;

   printf("Enter a number: \n");
   scanf("%d", &number);
   p = allEvenDigits1(number);
   if (p == 1)
      printf("allEvenDigits1(): yes\n");
   else if (p == 0)
      printf("allEvenDigits1(): no\n");
   else 
      printf("allEvenDigits1(): error\n");
   allEvenDigits2(number, &result);
   if (result == 1)
      printf("allEvenDigits2(): yes\n");
   else if (result == 0)
      printf("allEvenDigits2(): no\n");
   else 
      printf("allEvenDigits2(): error\n");
   return 0;
}
int allEvenDigits1(int num) 
{
	/*edit*/
   /* Write your code here */
    int extracted=0,allEven=1;
   while(num>=1)
   {
       extracted = num%10;
       num/=10;
       if(extracted%2!=0)
       {
           allEven=0;
       }
       
   }
   return allEven;


	/*end_edit*/
}
void allEvenDigits2(int num, int *result) 
{
	/*edit*/
   /* Write your code here */
    int extracted=0,allEven=1;
   while(num>=1)
   {
       extracted = num%10;
       num/=10;
       if(extracted%2!=0)
       {
           allEven=0;
       }
       
   }
   *result = allEven;
   return;


	/*end_edit*/
}