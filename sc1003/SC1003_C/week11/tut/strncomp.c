#include<stdio.h>
#include<string.h>

int strncomp(char* s1, char* s2);
int main(void)
{
    char s1[1000];
    char s2[1000];
    char* p;
    int result=-1;

    printf("Enter a source string:\n");
    fgets(s1,1000,stdin);
    if(p=strchr(s1,'\n'))
    *p='\0';

    printf("Enter a target string:\n");
    fgets(s2,1000,stdin);
    if(p=strchr(s2,'\n'))
    *p='\0';


    result=strncomp(s1,s2);
    if(result==0)
    {
        printf("strncomp(): equal\n");
    }
    else if(result==-1)
    {
        printf("strncomp(): less than\n");
    }
    else if(result==1)
    {
        printf("strncomp(): greater than\n");
    }
    else
    {
        printf("error\n");
    }
    char* h="hdhhdhd";
    printf(h);
}
int strncomp(char* s1, char* s2)
{
    int lengthofshorter;
    int prelim;//assign preliminary result based on length
    if(strlen(s1)>strlen(s2))
    {
        lengthofshorter=strlen(s2);
        prelim = 1;
    }
    else if(strlen(s1)<strlen(s2))
    {
        lengthofshorter=strlen(s1);
        prelim =-1;
    }
    else
    {
        lengthofshorter=strlen(s1);
        prelim =0;
    }
    
    //this for loop is a chance to check if prelim is wrong, ie a shorter string has a greater char inside
    for(int i=0;i<lengthofshorter;i++)
    {
        if(s1[i]>s2[i])
        {
            return 1;
        }
        else if(s1[i]<s2[i])
        {
            return -1;
        }
        else
        ;

    }
    //after this for loop we can cfm that both strings are equal for the length of the shorter one, means the longer string is greater.
    //or if both are same length, means they are exactly the same string
    
    return prelim;
    
}

/*SUGGESTED SOLUTIONS
*
*
*
*
SUGGESTED SOLUTIONS*/
int stringcmp(char* s1, char* s2)
{
    while(1)
    {
        if(*s1=='\0' && *s2=='\0')
            return 0;
        else if(*s1=='\0')
            return -1;
        else if(*s2=='\0')
            return 1;
        else if(*s1<*s2)
            return -1;
        else if(*s1>*s2)
            return 1;
        
        s1++;
        s2++;
    }
}