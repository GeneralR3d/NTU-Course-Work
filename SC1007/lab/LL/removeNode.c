
#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode{
    int item;
    struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
    ListNode* head;
    int size;
}LinkedList;


void printList(ListNode *cur);
ListNode * findNode(ListNode *cur, int index);
int insertNode(ListNode **ptrHead, int index, int item);
int removeNode(ListNode **ptrHead,int index);

/////////////////////////////////////////////////////////////////////////////////////////////
void printListLL(LinkedList *LL);
ListNode * findNodeLL(LinkedList *LL, int index);
int insertNodeLL(LinkedList *LL, int index, int item);
int removeNodeLL(LinkedList *LL,int index);

int main()
{
    ListNode *head=NULL;
    int size =0;
    int item;
    int index;

    printf("Enter a list of numbers, terminated by any non-digit character: \n");
    while(scanf("%d",&item))
        if(insertNode(&head,size, item)) size++;
    scanf("%*s");

    printList(head);

    while(1){
        printf("Enter the index of the node to be removed: ");
        scanf("%d",&index);

        if(!removeNode(&head,index))
            size--;
        else{
            printf("The node cannot be removed.\n");
            break;
        }

        printf("After the removal operation,\n");
        printList(head);
    }

    printList(head);
    return 0;
}

void printList(ListNode *cur){
    printf("Current List: ");
    while (cur != NULL){
        printf("%d ", cur->item);
        cur = cur->next;
    }
    printf("\n");
}

ListNode *findNode(ListNode* cur, int index)
{
   if (cur==NULL || index<0)
      return NULL;
   while(index>0){
      cur=cur->next;
      if (cur==NULL)
         return NULL;
      index--;
   }
   return cur;
}

int insertNode(ListNode **ptrHead, int index, int item){
    ListNode  *pre, *newNode;
    // If empty list or inserting first node, update head pointer
    if (index == 0){
        newNode = malloc(sizeof(ListNode));
        newNode->item = item;
        newNode->next = *ptrHead;
        *ptrHead = newNode;
        return 1;
    }
    // Find the nodes before and at the target position
    // Create a new node and reconnect the links
    else if ((pre = findNode(*ptrHead, index-1)) != NULL){
        newNode = malloc(sizeof(ListNode));
        newNode->item = item;
        newNode->next = pre->next;
        pre->next = newNode;
        return 1;
    }
    return 0;
}

int removeNode(ListNode **ptrHead,int index)
{
/* Write your program code here */
    ListNode* trav=*ptrHead;
    if(index<0||!trav) return -1;
    if(index==0){
        trav=trav->next;
        free(*ptrHead);
        *ptrHead=trav;
    }
    else{
        for(int i=0;i<index-1;i++){
            trav=trav->next;
            if(!trav||!trav->next)return -1;
        }
        ListNode* tmp=trav->next;
        trav->next=trav->next->next;
        free(tmp);
    }
    return 0;

}

void printListLL(LinkedList *LL)
{
    printf("Current List: ");
    ListNode* cur=LL->head;
    while (cur != NULL){
        printf("%d ", cur->item);
        cur = cur->next;
    }
    printf("\n");
}
ListNode * findNodeLL(LinkedList *LL, int index)
{
    ListNode*cur=LL->head;
    if (cur==NULL || index<0)
      return NULL;
   while(index>0){
      cur=cur->next;
      if (cur==NULL)
         return NULL;
      index--;
   }
   return cur;
}
int insertNodeLL(LinkedList *LL, int index, int item)
{
    ListNode  *pre, *newNode;
    // If empty list or inserting first node, update head pointer
    if (index == 0){
        newNode = malloc(sizeof(ListNode));
        newNode->item = item;
        newNode->next = LL->head;
        LL->head = newNode;
        LL->size++;
        return 1;
    }
    // Find the nodes before and at the target position
    // Create a new node and reconnect the links
    else if ((pre = findNodeLL(&LL, index-1)) != NULL){
        newNode = malloc(sizeof(ListNode));
        newNode->item = item;
        newNode->next = pre->next;
        pre->next = newNode;
        LL->size++;
        return 1;
    }
    return 0;

}
int removeNodeLL(LinkedList *LL,int index)
{
    ListNode* trav=LL->head;
    if(index<0 || !(LL->head)) return -1;
    if(index==0){
        trav=trav->next;
        free(LL->head);
        LL->head=trav;
    }
    else{
        for(int i=0;i<index-1;i++){
            trav=trav->next;
            if(!trav||!trav->next)return -1;
        }
        ListNode* tmp=trav->next;
        trav->next=trav->next->next;
        free(tmp);
    }
    LL->size--;
    return 0;
}
