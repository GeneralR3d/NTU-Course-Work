	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
int digitValue1(int num, int k);
void digitValue2(int num, int k, int *result);
int main()
{
   int num, digit, result=-1;
   
   printf("Enter the number: \n");
   scanf("%d", &num);     
   printf("Enter k position: \n");
   scanf("%d", &digit);   
   printf("digitValue1(): %d\n",  digitValue1(num, digit));
   digitValue2(num, digit, &result);
   printf("digitValue2(): %d\n", result);   
   return 0;
}
int digitValue1(int num, int k)
{
	/*edit*/
   /* Write your code here */
   int extracted=0;
   for(int i=0;i<k;i++)
   {
       extracted = num%10;
       num/=10;
   }
   return extracted;


	/*end_edit*/
}
void digitValue2(int num, int k, int *result) 
{
	/*edit*/
   /* Write your code here */
   int extracted=0;
   for(int i=0;i<k;i++)
   {
       extracted = num%10;
       num/=10;
   }
   *result = extracted;
   return;

	/*end_edit*/
}

//in the end dont need this function lol
int lengthOfNumber(int num)
{
    int length =0;
    while(num>=1)
    {
        num/=10;
        length++;
    }
    return length;
}