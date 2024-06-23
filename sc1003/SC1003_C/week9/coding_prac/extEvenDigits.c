	/*edit*/

/*custom header*/
int lengthOfNumber(int num);
	/*end_edit*/
#include <stdio.h>
#define INIT_VALUE 999
int extEvenDigits1(int num);
void extEvenDigits2(int num, int *result);
int main()
{
   int number, result = INIT_VALUE;
   
   printf("Enter a number: \n");
   scanf("%d", &number);
   printf("extEvenDigits1(): %d\n", extEvenDigits1(number));        
   extEvenDigits2(number, &result);
   printf("extEvenDigits2(): %d\n", result);
   return 0;
}
int extEvenDigits1(int num) 
{  
	/*edit*/
   /* Write your code here */
      int extracted=0,new=0;
   while(num>=1)
   {
       extracted = num%10;
       num/=10;
       
       if(extracted%2==0)
       {
           new+=extracted*pow(10,lengthOfNumber(new));
       }
       
   }
   if(new==0)
   {
       return -1;
   }
   else
   {
       return new;
   }


	/*end_edit*/
}
void extEvenDigits2(int num, int *result) 
{  
	/*edit*/
   /* Write your code here */
   //suggested answer is better, see below
     int extracted=0,new=0;
   while(num>=1)
   {
       extracted = num%10;
       num/=10;
       
       if(extracted%2==0)
       {
           new+=extracted*pow(10,lengthOfNumber(new));//10 to the power of 0, since length of number returns 0 for number 0. Then subsequently as new has more digits, length of number will also increase.
       }
       
   }
   if(new==0)
   {
    *result = -1;
   }
   else
   {
       *result = new;
   }
  return;

	/*end_edit*/
}
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

//suggested solutions
//first extracted digit is in the 1s place, so digit times 1
//after changing the final number which is total, power becomes 10, basically power*=10 , since the next extracted digit will be in the 10s place, then 100s place and so on.
int extEvenDigits1(int num)
{
    int power =1; int total =0; int digit;

    while(num>0)
    {
        digit = num%10;
        num/=10;

        if((digit%2)==0)
        {
            total += digit*power;
            power *=10;
        }
    }
    return (power==1)? -1:total;
}