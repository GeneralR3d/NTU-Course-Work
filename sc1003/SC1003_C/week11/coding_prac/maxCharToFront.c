
	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
#include <string.h>
void maxCharToFront(char *str);
int main() 
{
   char str[80], *p;
   
   printf("Enter a string: \n");
   fgets(str, 80, stdin);
   if (p=strchr(str,'\n')) *p = '\0'; 
   printf("maxCharToFront(): ");  
   maxCharToFront(str); 
   puts(str);
   return 0;
}
//swap largest ascii char with front char
void maxCharToFront(char *str) 
{
	/*edit*/
   /* Write your code here */
   char* largest=&str[0];
   char* helper=&str[0];
   char tmp;
   for(int i=1;i<strlen(str);i++)
   {
       if(str[i]>*largest)
       {
           largest=&str[i];
       }
   }
   tmp=*largest;
   *largest=str[0];
   *helper=tmp;


	/*end_edit*/
}

//moves the largest ascii char to front and shift every other char backwards 1 by 1 to fill in the gaps
void maxCharToFront(char *str) 
{
       /* Write your code here */
   char* largest=str;//point at start of string
   char* helper;
   char tmp;
   //this loop compares ascii value of every char, at the end largest will point at the char with largest ascii value
   for(int i=1;i<strlen(str);i++)
   {
       if(str[i]>*largest)
       {
           largest=&str[i];
       }
   }
   tmp=*largest;//copy the largest value char into tmp first
    helper=largest-1;//put helper just before largest
    while(largest!=str)
    {
        *largest=*helper;//copy over the value at helper to largest, now the "hole" is at helper
        largest--;
        helper--;
        //after moving, the "hole" is at largest
    }
    //when the loop ends, largest will be at the very front, which means helper went out of array
    *largest=tmp;//copy tmp to helper which is at the very front
    


}

/*SUGGESTED SOLUTIONS
*
*
*
*
*
SUGGESTED SOLUTIONS*/
void maxCharToFront(char* str)
{
    char max;
    char* q;
    int i=0;

    max = str[0];
    q= str; // q is like the helper pointer here

    while(str[i]!='\0')
    {
        if(str[i]>max)//same process of finding the largest char and pointing both max and q at it
        {
            max=str[i];
            q=str+i;
        }
        i++;
    }

    while(q>str) // while q is at a char which is in front of the first char
    {
        *q=*(q-1); //move every char forward by 1
        q--;
    }
    str[0]=max; //set the first char to the max char

}