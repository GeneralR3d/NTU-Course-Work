	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h> 
#include <string.h>
int countWords(char *s);
int main() 
{
   char str[80], *p;

   printf("Enter the string: \n");
   fgets(str, 80, stdin);
   if (p=strchr(str,'\n')) *p = '\0';   
   printf("countWords(): %d", countWords(str));
   return 0;
}
int countWords(char *s)
{
	/*edit*/
   /* Write your code here */
   int words=1;
   int i=0;
   while(s[i]!='\0')
   {
       if(s[i]==' ')
       words++;
       
       i++;
   }
   return words;


	/*end_edit*/
}