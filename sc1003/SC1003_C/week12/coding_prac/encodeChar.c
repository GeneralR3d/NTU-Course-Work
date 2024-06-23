	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
#include <string.h>
typedef struct {
   char source;
   char code;
} Rule;
void createTable(Rule *table, int *size);
void printTable(Rule *table, int size);
void encodeChar(Rule *table, int size, char *s, char *t);
int main() 
{
   char s[80], t[80], dummychar, *p;
   int size, choice;
   Rule table[100];
     
   printf("Select one of the following options:\n");
   printf("1: createTable()\n");     
   printf("2: printTable()\n");
   printf("3: encodeChar()\n");      
   printf("4: exit()\n");    
   do {
      printf("Enter your choice: \n");
      scanf("%d", &choice);  
      switch (choice) {
         case 1:           
            printf("createTable(): \n");
            createTable(table, &size);           
            break;               
         case 2:           
            printf("printTable(): \n");
            printTable(table, size);           
            break;               
         case 3:       
            scanf("%c",&dummychar);
            printf("Source string: \n");
            fgets(s, 80, stdin);  
            if (p=strchr(s,'\n')) *p = '\0'; 
            encodeChar(table,size,s,t);
            printf("Encoded string: %s\n", t);   
            break;   
         default: 
            break;
      } 
   } while (choice < 4);
   return 0;
}
void printTable(Rule *table, int size)
{
   int i;

   for (i=0; i<size; i++)
   {
      printf("%d: %c->%c\n", i+1, table->source, table->code);
      table++;
   }
}
void createTable(Rule *table, int *size)
{
	/*edit*/
	/* Write your code here */
    printf("Enter number of rules:\n");
    scanf("%d",size);
  for (int i=0; i<*size; i++)
   {
       printf("Enter rule %d:\n",i+1);
       printf("Enter source character:\n");
       scanf("\n");
       scanf("%c",&(table->source));
       printf("Enter code character:\n");
       scanf("\n");
       scanf("%c",&(table->code));
      table++;
   }

	/*end_edit*/
}
void encodeChar(Rule *table, int size, char *s, char *t) 
{
	/*edit*/
	/* Write your code here */
	for(int i=0;i<=strlen(s);i++)//iterate one more time than the number of letters to account for NUL char being copied over
	{
	    t[i]=s[i];
	    for(int j=0;j<size;j++)
	    {
	        if(table[j].source==s[i])
	        {
	            t[i]=table[j].code;
	            break;
	        }
	    }
	}


	/*end_edit*/
}

//SUGGESTED SOLUTIONS.....i think mine is better leh
void encodeChar(Rule* table, int size, char* s, char* t)
{
   Rule* p;
   int i;
   //for each char in the source string
   while(*s!='\0')
   {
      p=table;
      for(i=0;i<=(size-1);i++)//scan the table for that char
      {
         if(*s!= p->source)
         p++;
      }

      if(*s!= p->source)//if still not equals, means the char is not found in the table, then just copy the orig over
      *t=*s;
      else //found, copy the encoded one from the table
      *t = p->code;

      t++;
      s++;
   }
   *t='\0';//NUL at the back
}