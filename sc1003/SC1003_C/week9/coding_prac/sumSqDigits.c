	/*edit*/

/*custom header*/

	/*end_edit*/
#include  <stdio.h>
int sumSqDigits1(int num);   
void sumSqDigits2(int num, int *result);   
int main()
{
   int num, result;

   printf("Enter a number: \n");
   scanf("%d", &num);
   printf("sumSqDigits1(): %d\n", sumSqDigits1(num));
   sumSqDigits2(num, &result);
   printf("sumSqDigits2(): %d\n", result);
   return 0;
}
int sumSqDigits1(int num) 
{
	/*edit*/
   /* Write your code here */
   int extracted=0, sumOSq=0;
   while(num>=1)
   {
       extracted = num%10;
       num/=10;
       sumOSq = sumOSq + (extracted*extracted);
   }
   return sumOSq;

	/*end_edit*/
}
void sumSqDigits2(int num, int *result) 
{
	/*edit*/
   /* Write your code here */
   int extracted=0, sumOSq=0;
   while(num>=1)
   {
       extracted = num%10;
       num/=10;
       sumOSq = sumOSq + (extracted*extracted);
   }
   *result = sumOSq;
   return;

	/*end_edit*/
}