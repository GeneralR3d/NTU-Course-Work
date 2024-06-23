////////////////////////////////////////////////////////////

//#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

////////////////////////////////////////////////////////////

typedef struct _listnode{
	int item;
	struct _listnode *next;
} ListNode;

//////////////////////////////////////////////////////

int searchList(ListNode *head, int value);

//////////////////////////////////////////////////////

void main()
{
	ListNode *head, *p, *temp;
	int n;


	head=NULL;
	p=NULL;		// pointing to the last node in the list
	printf("Enter a list of numbers, terminated by the value -1:\n");

 ////////////////////////////////////////////////////////////////////

 // Question 2
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

//////////////////////////////////////////////////////////////////////

//search for a value in the list. Q3

	printf("Enter value to search for:");
	scanf("%d", &n);
	
	int index=searchList(head,n);
	if(index==-1)
	printf("not found\n");
	else
	printf("Value %d found at index %d \n",n,index);

//freelist
	while(head!=NULL)
	{
		temp=head;
		head=head->next;
		free(temp);

	}

//////////////////////////////////////////

}

////////////////////////////////////////////////////////////

int searchList(ListNode *head, int value)
{

////////////////////////////////////////////////////////////////////

 // Question 3
 //Write your program code here
 int index=0;
 ListNode* trav=head;
 while(trav!=NULL)
 {
	if(trav->item==value)
	return index;

	index++;
	trav=trav->next;
 }
 return -1;

//////////////////////////////////////////////////////////////////////
}
