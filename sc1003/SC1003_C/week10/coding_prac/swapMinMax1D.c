	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
void swapMinMax1D(int ar[], int size);
int main() 
{
   int ar[50],i,size;
   
   printf("Enter array size: \n");
   scanf("%d", &size);
   printf("Enter %d data: \n", size);
   for (i=0; i<size; i++) 
      scanf("%d",ar+i);
   swapMinMax1D(ar, size);
   printf("swapMinMax1D(): ");
   for (i=0; i<size; i++) 
      printf("%d ",*(ar+i)); 
   return 0;
}
void swapMinMax1D(int ar[], int size)
{
	/*edit*/

 int max=ar[0],min=ar[0],temp=0;
  int* maxPointer=NULL;
  int*minPointer=NULL;
  
  for(int i=0;i<size;i++)
  {
    // cannot put if elseif, as there are cases where both are true, not completely mutually exclusive.
    //example: when its a string of same numbers from the start, both max and min are the same values, so both blocks need to execute to move the pointer down to the latest instance.
      if(ar[i]>=max)
      {
          max=ar[i];
          maxPointer = &ar[i];
      }
      if (ar[i]<=min)
      {
          min=ar[i];
          minPointer= &ar[i];
      }
  }
  // BEFORE DEFERENCE best to check if its NULL, deferencing NULL will cause seg fault
  temp= *maxPointer;
  *maxPointer=*minPointer;
  *minPointer=temp;
  return;



}