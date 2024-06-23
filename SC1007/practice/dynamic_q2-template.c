////////////////////////////////////////////////////////////


//#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

////////////////////////////////////////////////////////////

typedef struct _listnode{
	int item;
	struct _listnode *next;
} ListNode;


void main()
{
	ListNode *head, *p, *temp;
	int n;


	head=NULL;
	p=NULL;		// pointing to the last node in the list
	printf("Enter a list of numbers, terminated by the value -1:\n");

	/////////////////////////////////////////////////////////////////

	//Question 2
    //Write your program code here
	while (1)
	
	{
		scanf("%d",&n);
		if(n==-1) break;
		temp = (ListNode*)malloc(sizeof(ListNode));
		temp->item=n;
		temp->next=NULL;
		if(head==NULL)
		{
		head=temp;
		p=temp;
		}
		else
		{
			p->next=temp;
			p=temp;
		}

	}
	
	printf("current list: ");
	while(head!=NULL)
	{
		temp=head;

		printf("%d ",head->item);
		head=head->next;
		free(temp);

	}
   //////////////////////////////////////////////////////////////////
}
