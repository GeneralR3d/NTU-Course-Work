	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
#include <string.h>
#define INIT_VALUE -1000
int palindrome(char *str);
int main()
{
   char str[80], *p;
   int result = INIT_VALUE;
   
   printf("Enter a string: \n");
   fgets(str, 80, stdin);
   if (p=strchr(str,'\n')) *p = '\0'; 
   result = palindrome(str);
   if (result == 1)
      printf("palindrome(): A palindrome\n");
   else if (result == 0)
      printf("palindrome(): Not a palindrome\n");    
   else 
      printf("An error\n");      
   return 0;
}
int palindrome(char *str)
{
	/*edit*/
   /* Write your code here */
   int size=strlen(str);
   if(size<3)
   return 0;
   
   int middleindex=size/2-1;
   for(int i=0;i<=middleindex;i++)
   {
       if(str[i]==str[size-1-i])
       {
           ;
       }
       else
       {
           return 0;
       }
   }
    return 1;

	/*end_edit*/
}
/*SUGGESTED SOLUTIONS seems more complicated hmmm*/
int palindrome(char *str)
{
   int len,i;
   char* p1,p2;

   i=0,len=0;
   while(*(str+i)!='\0')
   {
      i++;
      len++;
   }

   p1=str;//front of str
   p2=str+len-1;//back of str

   while(p1<p2
   {
      if(*p1!=*p2)//if even 1 char is different, just break and return false
      {
         break;
      }
      else
      {
         p1++;
         p2--;//until they meet in middle
      }
   }
   //basically 2 ways it would have reached here,if p1<p2 means it exited the loop early, ie break, thus return false
   //if it exited the loop naturally, p1 would be equal to p2, and that also means it is a palindrome, so return true
   if(p1<p2)
   return 0;
   else
   return 1;

}