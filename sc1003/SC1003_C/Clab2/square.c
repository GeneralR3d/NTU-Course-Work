	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
int square1(int num);
void square2(int num, int *result);
int main()
{
   int number, result=0;

   printf("Enter the number: \n");
   scanf("%d", &number);
   printf("square1(): %d\n", square1(number)); 
   square2(number, &result);
   printf("square2(): %d\n", result);                
   return 0;
}
int square1(int num)
{ 
	/*edit*/
   /* Write your code here */
   int sum=0;
   for(int i=1;i<=num;i++)
   {
       sum+=((i*2)-1);
   }
    
    return sum;

	/*end_edit*/
}  
void square2(int num, int *result)
{ 
	/*edit*/
   /* Write your code here */
      int sum=0;
   for(int i=1;i<=num;i++)
   {
       sum+=((i*2)-1);
   }
    
    *result = sum;
    return;


	/*end_edit*/
}

/*SUGGESTED SOLUTION
int square1(int num)
{
    int count=0,k=1, result=0;
    while(count<num)
    {
        result+=k;
        k+=2;
        count++;
    }
    return result;
}

*/