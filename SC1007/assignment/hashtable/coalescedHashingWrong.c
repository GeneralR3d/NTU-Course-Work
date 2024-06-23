#include <stdio.h>
#include <stdlib.h>

#define TABLESIZE 37
#define PRIME     13

enum Marker {EMPTY,USED};

typedef struct _slot{
    int key;
    enum Marker indicator;
    int next;
} HashSlot;

int HashInsert(int key, HashSlot hashTable[]);
int HashFind(int key, HashSlot hashTable[]);

int hash(int key)
{
    return (key % TABLESIZE);
}

int main()
{
    int opt;
    int i;
    int key;
    int index;
    HashSlot hashTable[TABLESIZE];

    for(i=0;i<TABLESIZE;i++){
        hashTable[i].next = -1;
        hashTable[i].key = 0;
        hashTable[i].indicator = EMPTY;
    }

    printf("============= Hash Table ============\n");
    printf("|1. Insert a key to the hash table  |\n");
    printf("|2. Search a key in the hash table  |\n");
    printf("|3. Print the hash table            |\n");
    printf("|4. Quit                            |\n");
    printf("=====================================\n");

    printf("Enter selection: ");
    scanf("%d",&opt);
    while(opt>=1 && opt <=3){
        switch(opt){
        case 1:
            printf("Enter a key to be inserted:\n");
            scanf("%d",&key);
            int tmp=key;
            index = HashInsert(key,hashTable);
            if(index <0)
                printf("Duplicate key\n");
            else if(index < TABLESIZE){
                key=tmp;
                printf("Insert %d at index %d\n",key, index);
            }
                
            else
                printf("Table is full.\n");
            break;
        case 2:
            printf("Enter a key for searching in the HashTable:\n");
            scanf("%d",&key);
            index = HashFind(key, hashTable);

            if(index!=-1)
                printf("%d is found at index %d.\n",key,index);
            else
                printf("%d is not found.\n",key);
            break;

        case 3:
            printf("index:\t key \t next\n");
            for(i=0;i<TABLESIZE;i++) printf("%d\t%d\t%d\n",i, hashTable[i].key,hashTable[i].next);
            break;
        }
        printf("Enter selection: ");
        scanf("%d",&opt);
    }
    return 0;
}



int HashInsert(int key, HashSlot hashTable[])
{
 // Write your code here
    if(!hashTable) return -1;
    if(HashFind(key, hashTable)!=-1) return -1;
    int index=hash(key);
    int trav=index;
    /*This whole idea is wrong and wont work. We should not be checking if the slot is empty then we check if theres a next.
    We should really be checking if theres a next first, if there is means we have alr been here before and we should just follow the next
    until there is no more next. Then we can think about inserting.
    When there is no more next, there are 2 possibilities
    1) Slot is empty, good, just insert
    2) Slot is not empty, ie the prev insertion was case(1), in this case then we need to do the probing until we find a empty one, then we insert there and update here*/
    while(1){
        //this if block gets wrongly triggered when we progress trav until we find a empty slot. We insert new value w/o ever updating the guy who sent us here, what is our new address location
        if(hashTable[trav].indicator==EMPTY){
            hashTable[trav].key=key;
            hashTable[trav].indicator=USED;
            return trav;
        }
        //not empty means theres a key there, we need to continue probing to see where we can insert
        else{
            if((hashTable[trav].next=-1)){
                int empty=-1;
                int i=trav+1;
                while(1){
                
                if(hashTable[i].indicator==EMPTY){
                    hashTable[i].key=key;
                    hashTable[i].indicator=USED;
                    empty=i;
                    break;
                }
                i=(i+1)%TABLESIZE;
                if(i==trav) break;//means we have come full circle

            }

                if(empty==-1) return 999999;
                //means the for loop did not find a empty slot and thus the entire hastable is full
                else{
                    hashTable[trav].next=empty;
                    return empty;
                }

            }
            //if not -1 means theres a next element in another index, just follow it until we reach the end
            else{
                trav=hashTable[trav].next;
            }
        }
    }
}

int HashFind(int key, HashSlot hashTable[])
{
 // Write your code here
 if(!hashTable) return -1;
 int index=hash(key);
 if(hashTable[index].indicator==EMPTY) return -1;
 int trav=index;
while(1)
{
    if(hashTable[trav].key==key) return trav;
    else if((hashTable[trav].next== -1) || (hashTable[trav].indicator==EMPTY)) break;
    else trav=hashTable[trav].next;
}
return -1;


 
}