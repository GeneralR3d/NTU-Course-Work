	/*edit*/

/*custom header*/
#include<ctype.h>
	/*end_edit*/
#include <stdio.h>
#include <string.h>
void processString(char *str, int *totVowels, int *totDigits);
int main()
{
   char str[50], *p;
   int totVowels, totDigits;

   printf("Enter the string: \n");
   fgets(str, 80, stdin);
   if (p=strchr(str,'\n')) *p = '\0'; 
   processString(str, &totVowels, &totDigits);   
   printf("Total vowels = %d\n", totVowels);
   printf("Total digits = %d\n", totDigits);
   return 0;
}
void processString(char *str, int *totVowels, int *totDigits)
{
	/*edit*/
	/* Write your code here */
	int i=0;
	char vowels[6]="AEIOU";
	
	*totVowels =0;
	*totDigits=0;
	while(str[i]!='\0')
	{
	    if(isdigit(str[i]))
	    {
	        *totDigits=*totDigits +1;
	    }
	    for(int j=0;j<5;j++)
	    {
	        if(vowels[j]==toupper(str[i]))
	        {
	           *totVowels=*totVowels +1; 
	           break;
	        }
	    }
	    i++;
	}


	/*end_edit*/
}