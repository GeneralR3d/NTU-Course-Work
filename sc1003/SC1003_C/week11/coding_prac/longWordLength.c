	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
#include <string.h>
#include<ctype.h>
int longWordLength(char *s);
int main() 
{
   char str[80], *p;
   
   printf("Enter a string: \n");
   fgets(str, 80, stdin);
   if (p=strchr(str,'\n')) *p = '\0';   
   printf("longWordLength(): %d\n", longWordLength(str));    
   return 0;
}

int longWordLength(char *s)
{

int max=0,len=0;
char* start=s;//helper pointer
char word[strlen(s)];//temporary buffer array to store the word read



while(*start!='\0')//while not at the end of the whole string
{
    if(*start==' ')//if helper is at a space, advance forward by 1
    start++;

    sscanf(start,"%s",word);//scan a word

    while(!isspace(*start))//find the next space
    {
        if(*start=='\0')//if reach the end still haven find a space, ie for a single word string, break
        {
            break;
        }
        start++;
    }
    

    //goes over each char in buffer array to check for alphabets, if NUL is reached, NUL was placed there by sscanf, then break
    for(int i=0;i<strlen(s);i++)
    {
        if(isalpha(word[i]))
        {
            len++;
        }
        if(word[i]=='\0')
        break;
    }

//for every word update the length to find the longest
    if(len>max)
    max=len;
    len=0;
}
return max;

}

/*SUGGESTED SOLUTIONS
*
*
*
*
*
SUGGESTED SOLUTIONS*/
int longWordLength(char* s)
{
    int max=0,len=0;

    while(*s!='\0')
    {
        //while(((*s<='Z') && (*s>='A')) || ((*s<='z') && (*s>='a')))
        while(isalpha(*s))
        {
            len++;
            s++;
        }

        if(len>max)
        {
            max=len;
        }
        len=0;
        s++;//move from space to the next letter
    }
    return max;
}