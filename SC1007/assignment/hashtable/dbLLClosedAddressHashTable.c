#include <stdio.h>
#include <stdlib.h>

#define LOAD_FACTOR 3

typedef struct _listnode{
    int key;
    struct _listnode *next;
    struct _listnode *pre;
} ListNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
} HashTableNode;

typedef struct _hashTable{
   int hSize;
   int nSize;
   HashTableNode *Table;
} HashTable;

int Hash(int key,int hSize);

ListNode* HashSearch(HashTable, int);
int HashInsert(HashTable *, int);
int HashDelete(HashTable *, int);

//In Practice, we will not do it
void HashPrint(HashTable);

int main()
{
    int opt;
    int size;

    int i;
    int key;

    //Create a HashTable
    HashTable Q1;

    printf("============= Hash Table ============\n");
    printf("|1. Create a hash table             |\n");
    printf("|2. Insert a key to the hash table  |\n");
    printf("|3. Search a key in the hash table  |\n");
    printf("|4. Delete a key from the hash table|\n");
    printf("|5. Print the hash table            |\n");
    printf("|6. Quit                            |\n");
    printf("=====================================\n");

    printf("Enter selection: ");
    scanf("%d",&opt);
    while(opt>=1 && opt <=5){
        switch(opt){
        case 1:
            printf("Enter number of data to be inserted:\n");
            scanf("%d",&size);

            //instead of flexibily inserting data into hashtable
            //this method obtains the total number of elements first, then calculates the size of hashtable based on total elements and load factor
            //which is not how hash table data is inserted normally
            //this is not realistic
            //if total num of elements is known beforehand then there would perhaps be no point in even using hashtable, just use array.
            Q1.hSize = (int)size/ LOAD_FACTOR;
            Q1.nSize = 0;//n is just the number of elements in the hash table

            Q1.Table = (HashTableNode *) malloc(sizeof(HashTableNode)*(Q1.hSize));

            for(i=0;i<Q1.hSize;i++){
                Q1.Table[i].head = NULL;
                Q1.Table[i].size = 0;
            }
            printf("HashTable is created.\n");
            break;
        case 2: //Insertion
            printf("Enter a key to be inserted:\n");
            scanf("%d",&key);
            if(HashInsert(&Q1,key))
                printf("%d is inserted.\n",key);
            else
                printf("%d is a duplicate. No key is inserted.\n",key);
            break;
        case 3: //Search
            printf("Enter a key for searching in the HashTable:\n");
            scanf("%d",&key);
            ListNode* node = HashSearch(Q1, key);

            if(node!=NULL)
                printf("%d is found.\n",key);
            else
                printf("%d is not found.\n",key);
            break;
        case 4: //Deletion
            printf("Enter a key to be deleted:\n");
            scanf("%d",&key);
            if(HashDelete(&Q1,key))
                printf("%d is deleted.\n",key);
            else
                printf("%d is not existing.\n",key);
            break;
        case 5:
            HashPrint(Q1);
            break;
        }

    printf("Enter selection: ");
    scanf("%d",&opt);
    }

    for(i=0;i<Q1.hSize;i++)
    {
        while(Q1.Table[i].head)
        {
            ListNode *temp;
            temp = Q1.Table[i].head;
            Q1.Table[i].head = Q1.Table[i].head->next;
            free(temp);
        }
    }
    free(Q1.Table);

    return 0;
}
/*HashTable Closed Addressing Pseudocode Insert
1. check if the hashtable is valid ie not null and the size of the hashtable not <1
2. Hash and visit the slot
3. If slot is empty just create a LL node and let the head point to that node
4. If slot is not empty, it means a LL alr exists, traverse through the whole list to look for duplicates, returning invalid anywhere a duplicate is found
5. create a LL node and insert that new node at the front of the list and ensure the rest of the list is not isolated
*/


int HashInsert(HashTable* Q1Ptr, int key)
{
    //Write your code here
    if(!Q1Ptr || !Q1Ptr->Table || Q1Ptr->hSize <1) return 0;
    ListNode* result = HashSearch(*Q1Ptr, key);
    if(result) return 0;
    //search returned NULL so go ahead and insert into the hashtable
    int index=Hash(key, Q1Ptr->hSize);
    
    if(Q1Ptr->Table[index].head==NULL)
    {
        ListNode* tmp=malloc(sizeof(ListNode));
        tmp->key=key;
        tmp->next=NULL;
        tmp->pre=NULL;
        Q1Ptr->Table[index].head=tmp;
    }
    else 
    {
        ListNode* tmp=malloc(sizeof(ListNode));
        tmp->key=key;
        tmp->next=Q1Ptr->Table[index].head;
        tmp->next->pre=tmp;
        tmp->pre=NULL;
        Q1Ptr->Table[index].head=tmp;
    }
    Q1Ptr->nSize++;
    return 1;

}

/*HashTable Closed Addressing Pseudocode Delete
1. check if the hashtable is valid ie not null and the size of the hashtable not <1
2. Hash and visit the slot
3. If slot is empty just theres nothing to delete, just return
4. If slot is not empty, it means a LL alr exists, traverse through the whole list to look for that target node, saving its address
5. handle 3 cases for delete
target node to delete is at front of LL
target node to delete is in the middle of LL
target node to delete is at end of LL (similar to middle)
*/

int HashDelete(HashTable* Q1Ptr, int key)
{
    //Write your code here
    if(!Q1Ptr || !Q1Ptr->Table || Q1Ptr->hSize <1) return 0;
    ListNode* result = HashSearch(*Q1Ptr, key);
    if(!result) return 0;
    //search returned not NULL so go ahead and delete
    int index=Hash(key, Q1Ptr->hSize);

    if(Q1Ptr->Table[index].head==NULL) return 0;
    if(!result->pre)
    {
        result->next->pre=NULL;
        Q1Ptr->Table[index].head=result->next;
        free(result);
    }
    else if(!result->next)
    {
        result->pre->next=NULL;
        free(result);
    }
    else 
    {
        result->pre->next=result->next;
        result->next->pre=result->pre;
        free(result);
    }
    return 1;


}

int Hash(int key,int hSize)
{
    return key%hSize;
}

ListNode* HashSearch(HashTable Q1, int key)
{
    int index;

    ListNode *temp;

    if(Q1.hSize != 0)
      index = Hash(key,Q1.hSize);
    else
      return NULL;

    temp = Q1.Table[index].head;
    while(temp !=NULL){
        if(temp->key == key)
            return temp;
        temp = temp->next;
    }

    return NULL;
}

void HashPrint(HashTable Q1)
{
    int i;
    ListNode *temp;
    for(i=0;i<Q1.hSize;i++)
    {
        temp =Q1.Table[i].head;
        printf("%d:  ",i);
        while(temp !=NULL)
        {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("\n");
    }
}