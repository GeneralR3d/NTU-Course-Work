	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
#include <string.h>
#define SIZE 10
void findMinMaxStr(char word[][40], char *first, char *last, int size);
int main()
{
   char word[SIZE][40];
   char first[40], last[40];
   int i, size; 
   
   printf("Enter size: \n");
   scanf("%d", &size);
   printf("Enter %d words: \n", size);
   for (i=0; i<size; i++)
      scanf("%s", word[i]); 
   findMinMaxStr(word, first, last, size);  
   printf("First word = %s, Last word = %s\n", first, last);        
   return 0;
}
void findMinMaxStr(char word[][40], char *first, char *last, int size)
{
	/*edit*/
	/* lesson learnt is that when array is being passed into function as pointers, they are pointer constants and not variables.
    When the array pointer constants are reassigned to another place inside a function, a local copy of char* is created.
    The original pointer constant does not change its address, it cant be incremented, or reassigned. So need deliberately create local pointer variables and use strcpy to copy into the orig pointer constants. */
	char* localfirst=word[0];
	char* locallast=word[0];

	for(int i=0;i<size;i++)
	{

	    if(strcmp(word[i],localfirst)<0)
	    localfirst=word[i];
	    else if(strcmp(word[i],locallast)>0)
	    locallast=word[i];
	

	    
	}
    strcpy(first,localfirst);
    strcpy(last,locallast);

	/*end_edit*/
}