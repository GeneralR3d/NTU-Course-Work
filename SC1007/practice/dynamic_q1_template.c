////////////////////////////////////////////////////////////

#include "stdlib.h"
#include "stdio.h"
#include<string.h>

////////////////////////////////////////////////////////////

char* insert(char *s,int n, char ch);
char* removes(char *s, int n);

//////////////////////////////////////////////////////////
void main ()
{
	int n;
    char *s;
	int choice;


	printf("How many characters do you want to input:");
	scanf("%d", &n);

	s=(char *)malloc((n+1)*sizeof(char));

    if (s==NULL)
	{
		printf("can't allocate the memory!");
		return;
	}

	printf("Input the string:");
	scanf("%s",s);



	do
	{
		printf("The string is %s\n", s);
		printf("Do you want to 1-insert or 2-remove or 3-quit?:");
		scanf("%d",&choice);
		getchar(); //to clear the return carriage in the buffer

		if (choice==1)
		{
			printf("enter char: ");
			char ch=getchar();
			s=insert(s,n,ch);
		}
		else if (choice==2)
			s=removes(s,n);
	}while (choice!=3);

	free(s);


}

//////////////////////////////////////////
char* removes(char *s, int n)
{
	// write your code here
	char* tmp=(char*)malloc((n+1-1)*sizeof(char));
	strcpy(tmp,&s[1]);
	free(s);
	return tmp;


}

//////////////////////////////////////////
char* insert(char *s, int n,char ch)
{
	// write your code here
		char* tmp=(char*)malloc((n+1+1)*sizeof(char));
		tmp[0]=ch;
		strcpy(&tmp[1],s);
		free(s);
		return tmp;
}
