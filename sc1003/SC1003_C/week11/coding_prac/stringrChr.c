	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>  
#include <string.h> 
char *stringrChr(char *s, char ch);
int main()
{
   char s[80], c, *p;
   char *temp=NULL;
   
   printf("Enter a string: \n");
   fgets(s, 80, stdin);
   if (p=strchr(s,'\n')) *p = '\0'; 
   printf("Enter a char: \n");
   scanf("%c", &c);    
   temp = stringrChr(s, c); 
   if (temp!=NULL)  
      printf("stringrChr(): %s\n", temp);   
   else 
      printf("stringrChr(): null string\n");
   return 0;
}
char *stringrChr(char *s, char ch)
{
	/*edit*/
/* Write your code here */
int i=0;
char* traverse;
while(s[i]!='\0')
{
    i++;
}
traverse=&s[i-1];

while(traverse!=s)
{
    if(*traverse==ch)
    {
        return traverse;
    }
    traverse--;
}
return NULL;

	/*end_edit*/
}