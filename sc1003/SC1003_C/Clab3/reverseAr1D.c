	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
void reverseAr1D(int ar[], int size);
int main()
{
   int ar[10];
   int size, i;
      
   printf("Enter array size: \n");
   scanf("%d", &size);
   printf("Enter %d data: \n", size);
   for (i=0; i <= size-1; i++)
      scanf("%d", &ar[i]);
   reverseAr1D(ar, size);
   printf("reverseAr1D(): ");
   if (size > 0) {
      for (i=0; i<size; i++)
         printf("%d ", ar[i]);
   }
   return 0;
}
void reverseAr1D(int ar[], int size)
{
	/*edit*/
   /* Write your code here */
   int middleIndex=size/2-1;
   int tmp=0;

   for(int i=0;i<=middleIndex;i++)
   {
       tmp=ar[i];
       ar[i]=ar[size-1-i];
       ar[size-1-i]=tmp;
   }


	/*end_edit*/
}