	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void cipher(char *s); 
void decipher(char *s);
int main()
{
   char str[80], dummychar, *p;
   int choice;
 
   printf("Select one of the following options: \n");
   printf("1: cipher() \n");     
   printf("2: decipher() \n");
   printf("3: exit() \n"); 
   do {
      printf("Enter your choice: \n");
      scanf("%d", &choice);
      switch (choice) {
         case 1:  
            scanf("%c",&dummychar);
            printf("Enter the string: \n");
            fgets(str, 80, stdin);
            if (p=strchr(str,'\n')) *p = '\0';  
            printf("To cipher: %s -> ", str);
            cipher(str);
            printf("%s\n", str); 
            break;
         case 2: 
            scanf("%c",&dummychar);  
            printf("Enter the string: \n");
            fgets(str, 80, stdin);
            if (p=strchr(str,'\n')) *p = '\0';  
            printf("To decipher: %s -> ", str);
            decipher(str);
            printf("%s\n", str);  
            break;
         default:
            break;
      }
   } while (choice < 3);    
   return 0;
}
void cipher(char *s)  
{
	/*edit*/
   /* Write your code here */
   for(int i=0;i<strlen(s);i++)
   {
       if(isupper(s[i]))
       {
           s[i]=65+modulo((s[i]-65+1),26);// 65 + char-65+1 %26 // 65 is A // basically every letter will add 1
       }
       else if(islower(s[i]))
       {
           s[i]=97+modulo((s[i]-97+1),26);// 97 + char-97+1 %26 //97 is a // basically every letter will add 1
       }
   }


	/*end_edit*/
}
void decipher(char *s)  
{
	/*edit*/
   /* Write your code here */
      for(int i=0;i<strlen(s);i++)
   {
       if(isupper(s[i]))
       {
           s[i]=65+modulo((s[i]-65-1),26);// 65 + char-65-1 %26 // 65 is A // basically every letter will minus 1
       }
       else if(islower(s[i]))
       {
           s[i]=97+modulo((s[i]-97-1),26); // 97 + char-97-1 %26 //97 is a // basically every letter will minus 1
       }
   }


	/*end_edit*/
}

//take care of both positive and negative modulo numbers
int modulo(int x,int N){
    return (x % N + N) %N;
}

/*SUGGESTED SOLUTIONS
*
*
*
*
*
*
*
SUGGESTED SOLUTIONS*/
void cipher(char* s)
{
   char* str;
   int len;
   
   len=strlen(s);
   for(int i=0;i<len;i++)
   {
      if(isalpha(s[i]))
      {
         if(s[i]=='z')
            s[i]='a';
         else if(s[i]=='Z')
            s[i]='A';
         else
            s[i]=s[i]+1;
      }
   }
}
/*SUGGESTED SOLUTIONS
*
*
*
*
*
*
*
SUGGESTED SOLUTIONS*/
void decipher(char* s)
{
   char* str;
   int len;
   
   len=strlen(s);
   for(int i=0;i<len;i++)
   {
      if(isalpha(s[i]))
      {
         if(s[i]=='a')
            s[i]='z';
         else if(s[i]=='A')
            s[i]='Z';
         else
            s[i]=s[i]-1;
      }
   }
}