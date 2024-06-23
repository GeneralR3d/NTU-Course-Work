//////////////////////////////////////////////////////////////////////////////////////////////

#include "stdio.h"
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

//////////////////////////////////   linked list //////////////////////////////////////////////

typedef struct _listnode{
	int item;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
	int size;
	ListNode *head;
	ListNode *tail;
} LinkedList;

////////////////////////////////// stack    //////////////////////////////////////////////
typedef struct stack{
	LinkedList ll;
} Stack;

//////////////////////////////////// queue ////////////////////////////////////////////

typedef struct _queue{
	LinkedList ll;
} Queue;

////////////////////////////////////////////////////////////////////////////////
void printList(ListNode *head);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);

//////////////////////////////////////////////////

void push(Stack *s, int item);
int pop(Stack *s);
int peek(Stack *s);
int isEmptyStack(Stack *s);

//////////////////////////////////////////////////

void enqueue(Queue *q, int item);
int dequeue(Queue *q);
int isEmptyQueue(Queue *s);

///////////////////////////////////////////////////////////////
// four questions
void removeUntil(Stack *s, int value);
void recursiveReverse(Queue *q);
int palindrome(char *word);
int balanced(char *expression);

//////////////////////////////////////////////////////////////////
/////

int main()
{
	Stack s;
	Queue q;
	int item[] = { 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1 };
	int i;
	char *word1 = "A man a plan a canal Panama";
	char *word2 = "Superman in the sky";

	//for question 1
	//initialize the stack
	s.ll.head = NULL;
	s.ll.size = 0;
	s.ll.tail = NULL;

	for (i = 0; i<11; i++)
		push(&s, item[i]);

	printList(s.ll.head);
	removeUntil(&s, 5);
	printList(s.ll.head);

	//for question 2
	//initialize the queue
	q.ll.head = NULL;
	q.ll.size = 0;
	q.ll.tail = NULL;

	for (i = 0; i<10; i++)
		enqueue(&q, i);
	printList(q.ll.head);
	recursiveReverse(&q);
	printList(q.ll.head);

	//for question 3
	palindrome(word1)==0?printf("%s is a Palindrome!\n",word1):printf("%s is Not a palindrome!\n",word1); //*word1="A man a plan a canal Panama";
	palindrome(word2)==0?printf("%s is a Palindrome!\n",word2):printf("%s is Not a palindrome!\n",word2);// *word2="Superman in the sky";


	//for question 4
	if (balanced("[]")) printf("not balanced!\n");
	else
		printf("balanced!\n");

	if (balanced("[()]")) printf("not balanced!\n");
	else
		printf("balanced!\n");

	if (balanced("{[]()[]}")) printf("not balanced!\n");
	else
		printf("balanced!\n");

	if (balanced("[({{)])")) printf("not balanced!\n");
	else
		printf("balanced!\n");

	return 0;
}

////////////////////////////////////////////////////////////////
//Question 1

void removeUntil(Stack *s, int value){

	// write your code here
	while (!isEmptyStack(s))
	{
		int top=peek(s);
		if(top==value)//or when top ==NULLs
		break;
		pop(s);
	}
	return;

}

////////////////////////////////////////////////////////////
//Question 2

void recursiveReverse(Queue *q){

	// write your code here
	if(isEmptyQueue(q)) return;
	int num = dequeue(q);
	recursiveReverse(q);
	enqueue(q,num);


}

////////////////////////////////////////////////////////////
//Question 3
//USING ARRAY BASED STRING AND STRCASECMP TO COMPARE FIRST HALF AND SECOND HALF OF STRING,
//very tedius and hard to remove spaces from a string in c
//also very inefficient due to the use of multiple loops
//also this doesnt work
int palindromeString(char *word){

	
    Stack s1;
    s1.ll.head=NULL;
    s1.ll.tail=NULL;
    s1.ll.size=0;


	char* copy=(char*)malloc(strlen(word)+1);
	strcpy(copy,word);
	char* trv=copy;

    for(int i=0,n=strlen(word);i<n;i++)
    {
		if(*trv==' ')
		{
		*trv=*(trv+1);
		*(trv+1)=' ';
		}

		trv++;
    }

	int middle=strlen(word)/2;
    
    for(int i=0,n=strlen(word);i<n;i++)
    {
		if(word[i]!=' ')
        push(&s1,word[i]);
    }
    char* final=(char*)malloc(strlen(word)+1);
    char* trav=final;
    while(!isEmptyStack(&s1))
    {
        *trav=pop(&s1);
        trav++;
    }
    *trav='\0';
    printf("%s\n",copy);
    printf("%s",final);
    int result=strcasecmp(final,copy);
	free(copy);
    free(final);
    return result;

	
}
//THIS IS DIFFERENT METHOD AS IT REQUIRES RECURSIVE REVERSE TO WORK
//TAKES 2 IDENTICAL QUEUE, REVERSES ONE AND CHECKS IF BOTH ARE THE SAME
//IF AFTER REVERSING IS STILL THE SAME THEN ITS A PALINDROME
int palindromeReverse(char*word)
{

    Queue q,k;
	q.ll.head=NULL;
	q.ll.tail=NULL;
	q.ll.size=0;
    k.ll.head=NULL;
	k.ll.tail=NULL;
	k.ll.size=0;
	for(int i=0,n=strlen(word);i<n;i++)
    {
        if(word[i]!=' ')
        {
        enqueue(&q,word[i]);
        enqueue(&k,word[i]);
        }

    }

    recursiveReverse(&q);
    while(!isEmptyQueue(&q)&&!isEmptyQueue(&k))
    {
        int qq=tolower(dequeue(&q));
        int kk =tolower(dequeue(&k));
        //printf("qq is %c, kk is %c\n",qq,kk);
        if(qq!=kk)
            return -1;
    }
    return 0;
}

//USES 1 STACK 1 QUEUE
//SIMULTANEOUSLY ENQUEUE AND PUSH after removing spaces
//since stack is naturally reversed order, we just need to compare both, char by char
//if its a palindrome, it will be same
int palindrome(char*word)
{
	Stack s; Queue q;
     s.ll.head = NULL;
     s.ll.tail = NULL;
     s.ll.size = 0;
     q.ll.head = NULL;
     q.ll.tail = NULL;
     q.ll.size = 0;

	 while(*word)
	 {
		if(*word!=' ')
		{
			enqueue(&q,toupper(*word));//converts all the upper and strips out spaces
			push(&s,toupper(*word));
		}
		word++;
	 }

	 while(!isEmptyQueue(&q)&&!isEmptyStack(&s))
	 {
		if(pop(&s)!=dequeue(&q))
		return -1;
	 }
	 return 0;

}

//SUGGESTED SOL
//USES 1 STACK 1 QUEUE, SIMILAR TO ONE ABOVE
int palindromeSQ(char *word){

	int i;
	Stack s;
	Queue q;

	s.ll.head = NULL;
	s.ll.tail = NULL;
	s.ll.size = 0;
	q.ll.head = NULL;
	q.ll.tail = NULL;
	q.ll.size = 0;

	// Put the whole string in a stack and a queue, stripping out spaces
	// Pop first half of stripped string off the stack letter by letter, comparing with second half

	printf("%s\n", word);

	while (*word){

		if (*word != ' '){
			push(&s, toupper(*word));
			enqueue(&q, toupper(*word));
		}
		word++;
	 }

	// Integer division by 2, ignores the middle character in an odd-length string

	 i = s.ll.size / 2;

	while (i > 0){
		if (pop(&s) != dequeue(&q)){
			printf("The string is not a palindrome\n");
			return -1;
		}
		i--;
	 }

	printf("The string is a palindrome\n");
}

//SUGGESTED SOL
//USES 2 STACKS
int palindrome2S(char *word){
	int i, odd;
	Stack s1, s2;
	s1.ll.head=NULL;
	//s1.ll.tail =NULL;
	s1.ll.size =0;

	s2.ll.head =NULL;
	//s2.ll.tail =NULL;
	s2.ll.size=0;

	// Put the whole string in a stack and a queue, stripping out spaces
	printf("%s\n", word);
	while (*word){
		if (*word != ' '){
			push(&s1, toupper(*word));
		}
		word++;
	 }

	//pop half of the chars and push into s2;
	i= s1.ll.size /2;
	odd = s1.ll.size %2 ;
	while (i > 0){
		push(&s2, pop(&s1));
		i--;
	 }

	//if the string has odd chars, pop the middle one because we don't need to compare it.
	if (odd)
		pop(&s1);

	//compare two stacks
	while (!isEmptyStack(&s1))
		if (pop(&s1)!=pop(&s2))
		{   printf("The string is not a palindrome\n");
			return -1;
		}

	printf("The string is a palindrome\n");
	return 0;
}




////////////////////////////////////////////////////////////
//Question 4
//USES 2 queue, USES RECURSIVEREVERSE() TO REVERSE ONE OF THEM
//THEN COMPARE
//BUT IT FUNDAMENTALLY DOESNT WORK SINCE THIS IS NOT LIKE A PALINDROME
//OPEN AND CLOSED BRACKETS when reversed, are still not equal
int balanced2Q(char *expression){

	// write your code here
	Queue q,k;
	q.ll.head=NULL;
	q.ll.tail=NULL;
	q.ll.size=0;
    k.ll.head=NULL;
	k.ll.tail=NULL;
	k.ll.size=0;
	for(int i=0,n=strlen(expression);i<n;i++)
    {
        enqueue(&q,expression[i]);
        enqueue(&k,expression[i]);
    }

    recursiveReverse(&q);
    //while(!isEmptyQueue(&q)) printf("The element in q is %c\n",dequeue(&q));
    while(!isEmptyQueue(&q)&&!isEmptyQueue(&k))
    {
        int qq=dequeue(&q);
        int kk =dequeue(&k);
        printf("qq is %c, kk is %c\n",qq,kk);
        //if(qq!=kk)
            //return -1;
    }
    return 0;

	;

}
//no choice have to hard code the 3 types of brackets
int balanced(char *expression){
	Stack s;
	s.ll.head=NULL;
	s.ll.tail=NULL;
	s.ll.size=0;

	while(*expression)
	{
		if(*expression=='('||*expression=='['||*expression=='{')//if its any of the opening brackets then push to stack
		push(&s,*expression);
		/*each of the closing brackets have to check individually for 2 conditions
		1) The stack must not be empty, if its empty means there is no corresponding opening bracket for this closing bracket
		2) The item popped off from the stack is the partner bracket to this closing bracket, if not then its not balanced
		*/
		else if(*expression==')')
		{
			if(isEmptyStack(&s)) return -1;
			if(pop(&s)!='(')return -1;
			//if(pop(&s)!='(' || isEmptyStack(&s))
			//^ this is misleading and should not be used
			//isemptystack() must be called before pop, since if pop empties the last element which is balanced and correct, it will trigger isemptystack() and return -1
		}
		else if(*expression==']')
		{
			if(isEmptyStack(&s)) return -1;
			if(pop(&s)!='[')return -1;
			//if(pop(&s)!='[' || isEmptyStack(&s))
			//^ this is misleading and should not be used
			//isemptystack() must be called before pop, since if pop empties the last element which is balanced and correct, it will trigger isemptystack() and return -1
		}
		else if(*expression=='}')
		{
			if(isEmptyStack(&s)) return -1;
			if(pop(&s)!='{')return -1;
			//if(pop(&s)!='{' || isEmptyStack(&s))
			//^ this is misleading and should not be used
			//isemptystack() must be called before pop, since if pop empties the last element which is balanced and correct, it will trigger isemptystack() and return -1
		}
		expression++;
	}
	//at the very end, the stack must be empty, if not it means there are leftover characters in the stack, ie some characters have no partner, so its not balanced
	if(isEmptyStack(&s))
	return 0;
	else
	return -1;

}

////////////////////////////////////////////////////////////////////////////////

void push(Stack *s, int item){
	insertNode(&(s->ll), 0, item);
}

int pop(Stack *s){
	int item;

	item = ((s->ll).head)->item;
	removeNode(&(s->ll), 0);
	return item;
}

int peek(Stack *s){
	return ((s->ll).head)->item;
}

int isEmptyStack(Stack *s){
	if ((s->ll).size == 0)
		return 1;
	return 0;
}


////////////////////////////////////////////////////////////////////////////////

void enqueue(Queue *q, int item){
	insertNode(&(q->ll), q->ll.size, item);
}

int dequeue(Queue *q){
	int item;
	item = ((q->ll).head)->item;
	removeNode(&(q->ll), 0);
	return item;
}

int isEmptyQueue(Queue *q){
	if ((q->ll).size == 0)
		return 1;
	return 0;
}



////////////////////////////////////////////////////////////////////////////////

void printList(ListNode *head){

	ListNode *temp = head;

	if (temp == NULL)
		return;

	while (temp != NULL){
		printf("%d ", temp->item);
		temp = temp->next;
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
		ll->tail = ll->head;
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}

	// Inserting as new last node
	if (index == ll->size){
		pre = ll->tail;
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		ll->tail = pre->next;
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));

		if (index == ll->size)
			ll->tail = pre->next;

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

		if (ll->size == 0)
			ll->tail = 0;

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){

		// Removing the last node, update the tail pointer
		if (index == ll->size - 1){
			ll->tail = pre;
			free(pre->next);
			pre->next = NULL;
		}
		else{
			cur = pre->next->next;
			free(pre->next);
			pre->next = cur;
		}
		ll->size--;
		return 0;
	}

	return -1;
}
