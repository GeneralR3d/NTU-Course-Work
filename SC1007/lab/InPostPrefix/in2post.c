#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

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
///////////////////////////////////////////////////////////////////////////
void in2post(char* infix,char* postfix);
int precedence(char c);

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
int evaluatePostFix(char* postfix);
int eval(int a,int b, char operator);

int main(void)
{
    char infix[30];
    char postfix[30];
    printf("Enter expression(less than 30 characters and no space):\n");
    scanf("%s",infix);
    in2post(infix,postfix);
    printf("postfix expression: %s\n",postfix);
	printf("After evaluation : %d\n",evaluatePostFix(postfix));

}

void in2post(char* infix,char* postfix)
{
    Stack s;
    //initialize the stack
	s.ll.head =NULL;
    s.ll.tail=NULL;
	s.ll.size =0;
    for(int i=0,n=strlen(infix);i<n;i++)
    {
        char current=infix[i];
        if(isalnum(current))
        {
            *postfix=current;
            postfix++;
        }
        else if(current==')')
        {
            while(peek(&s)!='(')
            {
                *postfix=pop(&s);
                postfix++;
            }
            pop(&s);
        }
        else if(current=='(')
        {
            push(&s,current);
        }
        else
        {
            while(!isEmptyStack(&s) && peek(&s)!='(' && precedence(peek(&s))>=precedence(current))
            {
                *postfix=pop(&s);
                postfix++;
            }
            push(&s,current);
        }
    }
    while(!isEmptyStack(&s))
    {
            *postfix=pop(&s);
            postfix++;
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
int evaluatePostFix(char* postfix)
{
	Stack s;
	s.ll.head=NULL;
	s.ll.tail=NULL;
	s.ll.size=0;


	for(int i=0;i<strlen(postfix);i++)
	{
		if(isalnum(postfix[i])){
			//push(&s,atoi(&postfix[i]));//must use atoi to convert char to integer, atoi also wont work for single char
			push(&s, (postfix[i]-'0')) ;//this is to covert it to int?? w/o using atoi
		}
		else{
			//have to store in 2 operand variables as division is not symmetric
			//we want a something b where a is below b, b is on top
			//in this specific order
		int operand1=pop(&s);
		int operand2=pop(&s);
		int result=eval(operand2,operand1,postfix[i]);
		printf("%d\n", result);
		push(&s,(int)result);
		}
	}
	return pop(&s);
}
int eval(int a,int b, char operator){
	switch(operator)
	{
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return a/b;
		default: return 0;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////
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
