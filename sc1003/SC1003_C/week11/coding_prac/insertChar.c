	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
#include <string.h>
void insertChar(char *str1, char *str2, char ch);
int main() 
{
   char a[80],b[80];
   char ch, *p;
   
   printf("Enter a string: \n");  
   fgets(a, 80, stdin);
   if (p=strchr(a,'\n')) *p = '\0'; 
   printf("Enter a character to be inserted: \n");  
   ch = getchar();
   insertChar(a,b,ch);
   printf("insertChar(): ");  
   puts(b);     
   return 0;
}
void insertChar(char *str1, char *str2, char ch)
{
	/*edit*/
  /* Write your code here */
  int count=0,i=0,j=0;
  //clear out the empty string of garbage values first
  for(int n=0;n<80;n++)
  {
      str2[n]='\0';
  }
  //i is index tracker for str1, j is index tracker for str2
  while(str1[i]!='\0')
  {
      str2[j]=str1[i];
      count++;
      if(count==3)
      {
          str2[j+1]=ch;
          count=0;
          j++;
      }
      i++;
      j++;
  }


	/*end_edit*/
}