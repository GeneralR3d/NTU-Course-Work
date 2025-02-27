////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////


typedef struct _listnode{
	int num;
	struct _listnode *next;
} ListNode;
typedef struct _linkedlist{
	ListNode *head;
	int size;
} LinkedList;
typedef struct _dbllistnode{
	int num;
	struct _dbllistnode *pre;
	struct _dbllistnode *next;
} DblListNode;

////////////////////////////////////////////////////////////////////
////////////
int removeNode(ListNode **ptrHead, int index);
int removeNode2(LinkedList *ll, int index);
int split(ListNode *head, ListNode **ptrEvenList, ListNode **ptrOddList);
int duplicateReverse(ListNode *head, ListNode **ptrNewHead);

void printList(ListNode *head);
ListNode * findNode(ListNode *head, int index);
int insertNode(ListNode **ptrHead, int index, int value);


// these are for the practice questions
int moveMaxToFront(ListNode **ptrHead);
int concatenate(ListNode **ptrHead1, ListNode *head2);
int combineAlternating(ListNode **ptrHead, ListNode *head1, ListNode *head2);
int insertDbl(DblListNode **ptrHead, int index, int value);
void printDblList(DblListNode *head);

////////////////////////////////////////////////////////////////////
////////////

int main()
{
	int i;
	ListNode *head = NULL;
	ListNode *dupRevHead = NULL;
	ListNode *oddHead = NULL;
	ListNode *evenHead = NULL;
	ListNode *list1Head = NULL, *list2Head = NULL;
	ListNode *combAltHead = NULL;
	DblListNode *dblHead = NULL;
	LinkedList llist;
	int size = 0;

	//build a linked list
	if (insertNode(&head, 0, 6) == 0) size++;
	if (insertNode(&head, 0, 4) == 0) size++;
	if (insertNode(&head, 0, 2) == 0) size++;
	printf("After inserting 3 values.");
	printList(head);


	//removeNode(): question 1
	if (removeNode(&head, 3) == 0) 
	{
		size--;//this one can't be removed.
		printf("remove3rd\n");
	}
	if (removeNode(&head, 1) == 0) 
	{
		size--;
		printf("removesecond\n");
	}
	if (removeNode(&head, 0) == 0) 
	{
		size--;
		printf("removefirst\n");
	}

	printf("\nafter remove using removeNode(), ");
	printList(head);

	//insert some nodes
	if (insertNode(&head, 2, 3) == 0) size++; // this one can't be inserted.
	if (insertNode(&head, 1, 1) == 0) size++;
	if (insertNode(&head, 0, 0) == 0) size++;

	printf("\nafter insert, ");
	printList(head);

	//removeNode2(): question 2
	llist.head = head;
	llist.size = size;
	removeNode2(&llist, 2);
	removeNode2(&llist, 0);
	removeNode2(&llist, 0);
	head = llist.head;


	printf("\nafter remove using removeNode2(), ");
	printList(llist.head);
	// empty linked list now

	//split(): question 3
	for (i = 1; i <10; i++)//build a new linked list
		insertNode(&head, 0, i);
	printf("\n\ninsert 1-9 to the linked list,");
	printList(head);
	printf("split the current list, results:\n");
	split(head, &evenHead, &oddHead);
	printf("the even list");
	printList(evenHead);
	printf("the odd list");
	printList(oddHead);

	//duplicateReverse(): question 4
	printf("\n");
	for (i = 1; i <9; i++)//build a new linked list
	insertNode(&head, 0, i);
	printf("\n\ninsert 1-9 to the linked list,");
	printList(head);
	duplicateReverse(head, &dupRevHead);
	printf("After duplicateReverse(),");
	printList(dupRevHead);

	////////////////////////////////////////////////////////////////////////
	//the following are for the PRACTICE QUESTIONS

	printf("\n\nNow for the practice questions");

	//1.moveMaxToFront()
	printf("\n************** moveMaxToFront *******************\n");
	printList(dupRevHead);
	moveMaxToFront(&dupRevHead);
	printf("after moveMaxToFront()");
	printList(dupRevHead);

	//2. concatenate()
	printf("\n************** concatenate() *******************\n");
	concatenate(&head, dupRevHead);
	printf("concatenate(current list, duplicate reverse list)\n  ");
	printList(head);

	//3.combineAlternating()
	printf("\n************** combineAlternating() *******************\n");
	for (i = 3; i > 0; i--)				//build linked list 1
		insertNode(&list1Head, 0, i);
	for (i = 13; i > 10; i--)			//build linked list 2
		insertNode(&list2Head, 0, i);
	printf("List 1:");
	printList(list1Head);
	printf("List 2: ");
	printList(list2Head);
	combineAlternating(&combAltHead, list1Head, list2Head);
	printf("After combineAlternating(): ");
	printList(combAltHead);

	//4. insertDbl()
	printf("\n************** insertDbl() *******************\n");
	printf("insertDbl()\nDoubly-linked list: ");
	insertDbl(&dblHead, 0, 10);
	insertDbl(&dblHead, 0, 20);
	insertDbl(&dblHead, 1, 30);
	insertDbl(&dblHead, 2, 40);
	printDblList(dblHead);
	return 0;
}

////////////////////////////////////////////////////////////////////
////////////

void printList(ListNode *head){
	ListNode *cur = head;

	if (cur == NULL)
		return;

	printf("the current linked list is:\n");
	while (cur != NULL){
		printf("%d ", cur->num);
		cur = cur->next;
	}
	printf("\n");
}

void printDblList(DblListNode *head){
	if (head == NULL) return;
	while (head != NULL){
		printf("%d ", head->num);
		head = head->next;
	}
	printf("\n");
}

ListNode * findNode(ListNode *head, int index){
	if (head == NULL || index < 0) return NULL;
	while (index > 0){
		head = head->next;
		if (head == NULL)
			return NULL;
		index--;
	}
	return head;
}


int insertNode(ListNode **ptrHead, int index, int value){
	ListNode *pre, *cur;
	// If empty list or inserting first node, need to update head pointer
	if (*ptrHead == NULL || index == 0){
		cur = *ptrHead;
		*ptrHead = (ListNode* )malloc(sizeof(ListNode));
		(*ptrHead)->num = value;
		(*ptrHead)->next = cur;
		return 0;
	}
	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(*ptrHead, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->num = value;
		pre->next->next = cur;
		return 0;
	}
	return -1;
}

////////////////////////////////////////////////////////////////////
////////////

int removeNode(ListNode **ptrHead, int index){

	// write your code here
	ListNode* trav=*ptrHead;
	if(index<0) return 1;
	if(!trav) return 1; //error when there is no list
	if(index==0)
	{
		*ptrHead=trav->next;
		free(trav);
		return 0;
	}

	ListNode* prev=trav;
	while(index!=0)
	{
		if(trav->next==NULL) break;
		prev=trav;
		trav=trav->next;
		index--;
	}
	prev->next=trav->next;
	free(trav);
	return 0;

	

}

////////////////////////////////////////////////////////////////////////////////
////////////

int removeNode2(LinkedList *ll, int index) {

	// write your code here

	ListNode* trav=ll->head;
	if(index<0) return 1;
	if(!trav) return 1; //error when there is no list
	if(index==0)
	{
		ll->head=trav->next;
		free(trav);
		return 0;
	}

	ListNode* prev=trav;
	while(index!=0)
	{
		prev=trav;
		trav=trav->next;
		index--;
	}
	prev->next=trav->next;
	free(trav);
	return 0;
}	



int split(ListNode *head, ListNode **ptrEvenList, ListNode **ptrOddList)
{

	// write your code here
	if(!head) return 1;
	while(head)
	{
		ListNode* current=head;
		head=head->next;
		current->next=*ptrEvenList;
		*ptrEvenList=current;
		if(!head) break;

		current=head;
		head=head->next;
		current->next=*ptrOddList;
		*ptrOddList=current;

	}
	return 0;
}

int duplicateReverse(ListNode *head, ListNode **ptrNewHead){

	// write your code here
	if(!head) return 1;
	while(head)
	{
		ListNode* new=(ListNode*)malloc(sizeof(ListNode));
		new->num=head->num;
		head=head->next;
		new->next=*ptrNewHead;
		*ptrNewHead=new;
	}
	return 0;
}	

////////////////////////////////////////////////////////////////////
////////////

int moveMaxToFront(ListNode **ptrHead){


	// write your code here
	if(*ptrHead==NULL)
	return -1;

	int maxindex,index;
	ListNode* maxnode;
	ListNode* behindmax;
	ListNode *trav;
	ListNode* travbehind;

	trav= travbehind= *ptrHead;
	maxnode=behindmax= trav;
	index=maxindex=0;

	while(trav!=NULL)
	{
		if(trav->num > maxnode->num)
		{
			maxnode=trav;
			behindmax=travbehind;
			maxindex=index;
		}
		index++;
		travbehind=trav;
		trav=trav->next;
	}
	behindmax->next= maxnode->next;
	maxnode->next=(*ptrHead)->next;
	*ptrHead=maxnode;
	return maxindex;


}


int concatenate(ListNode **ptrHead1, ListNode *head2){

	// write your code here
	if(!*ptrHead1 && !head2)
	return -1;
	else if(!*ptrHead1)
	{
		*ptrHead1=head2;
		return 0;
	}
	else if(!head2)
	return 0;
	else
	{
		ListNode* trav=*ptrHead1;
		while(trav->next != NULL)
		{
			trav=trav->next;
		}
		trav->next=head2;
		return 0;

	}
	

}


int combineAlternating(ListNode **ptrHead, ListNode *head1, ListNode *head2){

	// write your code here
	if(*ptrHead) return -1;
	if(!head1 && !head2) return -1;
	else if (!head1)
	{
		*ptrHead=head2;
		return 0;
	}
	else if(!head2)
	{
		*ptrHead=head1;
		return 0;
	}
	else
	{
		ListNode* end;
		while(head1!=NULL && head2!=NULL)
		{
			
			if(*ptrHead==NULL)
			{
			*ptrHead=head1;
			end= *ptrHead;
			head1=head1->next;
			}
			else
			{
				end->next=head1;
				end=end->next;
				head1=head1->next;

			}
				end->next=head2;
				end=end->next;
				head2=head2->next;
		}
		if(!head1)
		{
			end->next=head2;
			return 0;
		}
		else
		{
			end->next=head1;
			return 0;
		}
	}

}


int insertDbl(DblListNode **ptrHead, int index, int value){

	// write your code here
	if(index<0) return 1;
	if(*ptrHead==NULL)
	{
		DblListNode* new=(DblListNode*)malloc(sizeof(DblListNode));
		new->num=value;
		new->next=NULL;
		new->pre=NULL;
		*ptrHead=new;
		return 0;
	}
	if(index==0)
	{
		DblListNode* new=(DblListNode*)malloc(sizeof(DblListNode));
		new->num=value;
		new->next=*ptrHead;
		new->next->pre=new;
		new->pre=NULL;
		*ptrHead=new;
		return 0;
	}
	DblListNode* trav=*ptrHead;
	while(index!=0)
	{
		if(trav->next==NULL)break;
		trav=trav->next;
		index--;

	}
	DblListNode* new=(DblListNode*)malloc(sizeof(DblListNode));
	new->num=value;
	new->next=trav;
	new->pre=trav->pre;
	(new->pre)->next=new;
	trav->pre=new;
	return 0;


}


////////////////////////////////////////////////////////////////////
