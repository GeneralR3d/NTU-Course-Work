//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//////////////////////////////////   linked list /////////////////////////////////

typedef struct _listnode{
   int item;
   struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
   ListNode *tail;
} LinkedList;

////////////////////////////////// stack    ///////////////////////////////////////////////////////

typedef struct stack{
	LinkedList ll;
} Stack;

//////////////////////////////////// queue ////////////////////////////////////////////////////////

typedef struct _queue{
	LinkedList ll;
} Queue;

///////////////////////// function prototypes ////////////////////////////////////

// You should not change the prototypes of these functions
void sortStack(Stack *s);

void push(Stack *s, int item);
int pop(Stack *s);
int peek(Stack *s);
int isEmptyStack(Stack *s);

///////////////////////////////////////////////////////////////////////////////////////////////////
void printList(LinkedList *ll);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);
void removeAllItems(LinkedList *ll);

///////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    int c, value;

    Stack s;

    //initialize the stack
	s.ll.head =NULL;
	s.ll.size =0;


    c =1;

    printf("1: Insert an integer into the stack;\n");
    printf("2: Sort the stack in ascending order ;\n");
    printf("0: Quit;\n");

    while (c != 0)
	{
		printf("Please input your choice(1/2/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Input an integer that you want to insert into the stack: ");
			scanf("%d", &value);
			push(&s, value);
			printf("The resulting stack is: ");
			printList(&(s.ll));
			break;
		case 2:
			sortStack(&s); // You need to code this function
			printf("The resulting stack after sorting it in ascending order is: ");
			printList(&(s.ll));
			removeAllItems(&(s.ll));
			break;
		case 0:
			removeAllItems(&(s.ll));
			break;
		default:
			printf("Choice unknown;\n");
			break;
		}
	}

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void sortStack(Stack *s)
{
    /* add your code here */
	//transfer the whole stack into a LL
	LinkedList LL;
	LL.head=NULL;
	LL.tail=NULL;
	LL.size=0;
	while(!isEmptyStack(s))
	{
		insertNode(&LL,0,pop(s));
	}

	//empty the LL element by element, but do it in order, ie the largest element gets removed first and goes back into the stack
	while(LL.size!=0)
	{
	ListNode* tmp=LL.head;
	int max=tmp->item;
	int index=0;
	int maxindex=index;
	//all about finding the largest element in the LL
	while(1)
	{
		if(tmp->item > max)
		{
			max=tmp->item;
			maxindex=index;
		}
		tmp=tmp->next;
		if(!tmp) break;
		index++;

	}
	push(s,max);
	removeNode(&LL,maxindex);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//suggested sol
//uses temp stack and empties original stack onto temp stack
//take out top element of temp stack into temp int
//compares temp int with top element of orig stack
//if top of orig stack is smaller keep taking out and putting in temp stack until top of orig stack is bigger than temp
//if so, then put temp
//keep doing until temp stack is empty and all elements are back onto orig stack
void sortStack(Stack *s)
{
    int temp;
    Stack ts;
    ts.ll.head = NULL;
    ts.ll.tail = NULL;
    ts.ll.size = 0;

    while(!isEmptyStack(s)){
        push(&ts,pop(s));
    }

    while(!isEmptyStack(&ts)){
        temp = pop(&ts);

       while(!isEmptyStack(s) && peek(s) < temp){
           push(&ts,pop(s));
       }
        push(s,temp);
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////

void push(Stack *s, int item){
   insertNode(&(s->ll), 0, item);
}

int pop(Stack *s){
   int item;
   if(!isEmptyStack(s)){
    item = ((s->ll).head)->item;
    removeNode(&(s->ll), 0);
    return item;
   }
    return INT_MIN;
}

int peek(Stack *s){
   return ((s->ll).head)->item;
}

int isEmptyStack(Stack *s){
   if ((s->ll).size == 0)
      return 1;
   return 0;
}

//////////////////////////////////////////////////////////////////////////////////

void printList(LinkedList *ll){

	ListNode *cur;
	if (ll == NULL)
		return;
	cur = ll->head;

	if (cur == NULL)
		printf("Empty");
	while (cur != NULL)
	{
		printf("%d ", cur->item);
		cur = cur->next;
	}
	printf("\n");
}

ListNode * findNode(LinkedList *ll, int index){

	ListNode *temp;

	if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;

	temp = ll->head;

	if (temp == NULL || index < 0)
		return NULL;

	while (index > 0){
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
}

int insertNode(LinkedList *ll, int index, int value){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	// If empty list or inserting first node, need to update head pointer
	if (ll->head == NULL || index == 0){
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}


	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	return -1;
}


int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){

		if (pre->next == NULL)
			return -1;

		cur = pre->next;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 0;
	}

	return -1;
}

void removeAllItems(LinkedList *ll)
{
	ListNode *cur = ll->head;
	ListNode *tmp;

	while (cur != NULL){
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	ll->head = NULL;
	ll->size = 0;
}
