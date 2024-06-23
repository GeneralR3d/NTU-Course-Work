	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
int platform1D(int ar[], int size);
int main() 
{
   int i,b[50],size;

   printf("Enter array size: \n");
   scanf("%d", &size);
   printf("Enter %d data: \n", size);
   for (i=0; i<size; i++) 
      scanf("%d",&b[i]);
   printf("platform1D(): %d\n", platform1D(b,size));
   return 0;
}
int platform1D(int ar[], int size)
{
	/*edit*/
   /* Write your code here */
   int lengthOfPlatform=1,lengthOfMaxPlatform=1;
   //for loop will not run if there is only 1 element
   for(int i=0;i<size-1;i++)
   {
       
       if(ar[i]==ar[i+1])
       {
            lengthOfPlatform++;
       }
       else
       {
           
           if(lengthOfPlatform>lengthOfMaxPlatform)
           {
                lengthOfMaxPlatform=lengthOfPlatform;
                
           }
           lengthOfPlatform=1;
       }
       

   }
   return lengthOfMaxPlatform;


	/*end_edit*/
}