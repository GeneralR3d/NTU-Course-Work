#include<stdio.h>
#include<string.h>

char* strncopy(char* s1, char* s2, int n);
int main(void)
{
    char user[1000];
    char* p, target;
    int n=0;


    printf("Enter the string:\n");
    fgets(user,1000,stdin);
    if(p=strchr(user,'\n'))
    *p='\0';

    printf("Enter the number of characters:\n");
    scanf("%d",&n);

    char copied[n+1];
    target = strncopy(copied,user,n);
    printf("stringncopy(): %s",target);
    

}
char* strncopy(char* s2, char* s1, int n)
{
    for(int i=0,j=0;i<n;i++)
    {

        s2[i]=s1[j];
        if(s1[j]!='\0')
        {
            j++;
        }
    }
    return NULL;
}

/*SUGGESTED SOLUTIONS
*
*
*
*
SUGGESTED SOLUTIONS*/
char* stringncpy(char* s1,char* s2,int n)
{
    for(int k=0;k<n;k++)
    {
        if(s2[k]!'\0')
        {
            s1[k]=s2[k];
        }
        else
        {
            break;
        }
    }
    s1[k]='\0';

    //to append '\0' after copying if s2 length is shorter than n
    //does not affect correctness of program, it only follows the question specification
    for(int h=k;h<n;h++)
    {
        s1[h]='\0';
    }
    return s1;
}