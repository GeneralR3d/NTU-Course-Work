#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//////////////////////////////////   linked list /////////////////////////////////

typedef struct _listnode{
   char item;
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
///////////////////////////////////////////////////////////////////////////
void in2pre(char* infix,char* prefix);
int precedence(char c);

void push(Stack *s, char item);
int pop(Stack *s);
char peek(Stack *s);
int isEmptyStack(Stack *s);

///////////////////////////////////////////////////////////////////////////////////////////////////
void printList(LinkedList *ll);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, char value);
int removeNode(LinkedList *ll, int index);
void removeAllItems(LinkedList *ll);

int main(void)
{
    char infix[30];
    char prefix[30];
    printf("Enter expression(less than 30 characters and no space):\n");
    scanf("%s",infix);
    in2pre(infix,prefix);
    printf("prefix expression: %s\n",prefix);

}

void in2pre(char* infix,char* prefix)
{
    Stack s;
    //initialize the stack
	s.ll.head =NULL;
    s.ll.tail=NULL;
	s.ll.size =0;
    for(int n=strlen(infix),i=n;i>1;i--) prefix++;

    for(int n=strlen(infix),i=n;i>0;i--)
    {
        char current=infix[i];
        if(isalnum(current))
        {
            *prefix=current;
            prefix--;
        }
        else if(current=='(')
        {
            while(peek(&s)!=')')
            {
                *prefix=pop(&s);
                prefix--;
            }
            pop(&s);
        }
        else if(current==')')
        {
            push(&s,current);
        }
        else
        {
            while(!isEmptyStack(&s) && peek(&s)!=')' && precedence(peek(&s))>=precedence(current))
            {
                *prefix=pop(&s);
                prefix--;
            }
            push(&s,current);
        }
    }
    while(!isEmptyStack(&s))
    {
            *prefix=pop(&s);
            prefix--;
    }
    removeAllItems(&(s.ll));
    return;
}

int precedence(char c)
{
    switch(c)
    {
        case '*':
        case '/':
        case '%':
            return 5;
        case '+':
        case '-':
            return 4;
        case '>':
        case '<':
            return 3;
        case '&':
            return 2;
        case '=':
            return 1;
        default:
            return 0;
    }
}


void push(Stack *s, char item){
   insertNode(&(s->ll), 0, item);
}

int pop(Stack *s){
   char item;
   if(!isEmptyStack(s)){
    item = ((s->ll).head)->item;
    removeNode(&(s->ll), 0);
    return item;
   }
    return INT_MIN;
}

char peek(Stack *s){
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
		printf("%c ", cur->item);
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

int insertNode(LinkedList *ll, int index, char value){

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
