	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
#include <string.h>
char *sweepSpace(char *str);
int main()
{
   char str[80], *p;
 
   printf("Enter the string: \n");
   fgets(str, 80, stdin);
   if (p=strchr(str,'\n')) *p = '\0'; 
   printf("sweepSpace(): %s\n", sweepSpace(str));
   return 0;
}

//uses the same array but cannot handle punctuation in sentence like fullstops
char *sweepSpace(char *str)  
{
	/*edit*/
   /* Write your code here */
   int j=0;//for the while loop
   
   for(int i=0,n=strlen(str);i<n;i++)
   {

       j=0;
       
       if(str[i]==' ')
       {
           while(1)
           {
               if(isalpha(str[i+j]) || i+j>=n)
               break;
               j++;
           }
            str[i]=str[i+j];
            str[i+j]=' ';
       }
   }
   return str;


	/*end_edit*/
}


//the correct one, uses one addtional buffer array the same size as str
char *sweepSpace(char *str)  
{
	/*edit*/
   /* Write your code here */
char * arrnew = malloc((strlen(str)+1)*sizeof(char));

for(int i=0,j=0,n=strlen(str);i<n;i++,j++)
{
    while(str[i]==' ')
    i++;
    
    arrnew[j]=str[i];
    
}
strcpy(str,arrnew);
free(arrnew);
return str;
}

/*SUGGESTED SOLUTIONS
*
*
*
*
*
*
*SUGGESTED SOLUTIONS*/
char * sweepSpace(char *str)
{
    int j=0;
    int len =strlen(str);
    for(int i=0;i<len;i++)
    {
        if(str[i]!=' ')
        {
            str[j]=str[i]
            j++;
        }
    }
    str[j]='\0';
    return str;
}