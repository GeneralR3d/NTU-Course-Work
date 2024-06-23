#include <stdio.h>
#include <stdlib.h>

#define TABLESIZE 37
#define PRIME     13
enum Marker {EMPTY,USED,DELETED};

typedef struct _slot{
    int key;
    enum Marker indicator;
} HashSlot;

int HashInsert(int key, HashSlot hashTable[]);
int HashDelete(int key, HashSlot hashTable[]);


int hash1(int key);
int hash2(int key);

int main()
{
    int opt;
    int i;
    int key;
    int comparison;
    HashSlot hashTable[TABLESIZE];

    for(i=0;i<TABLESIZE;i++){
        hashTable[i].indicator = EMPTY;
        hashTable[i].key = 0;
    }

    printf("============= Hash Table ============\n");
    printf("|1. Insert a key to the hash table  |\n");
    printf("|2. Delete a key from the hash table|\n");
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
            comparison = HashInsert(key,hashTable);
            if(comparison <0)
                printf("Duplicate key\n");
            else if(comparison < TABLESIZE)
                printf("Insert: %d Key Comparisons: %d\n",key, comparison);
            else
                printf("Key Comparisons: %d. Table is full.\n",comparison);
            break;
        case 2:
            printf("Enter a key to be deleted:\n");
            scanf("%d",&key);
            comparison = HashDelete(key,hashTable);
            if(comparison <0)
                printf("%d does not exist.\n", key);
            else if(comparison <= TABLESIZE)
                printf("Delete: %d Key Comparisons: %d\n",key, comparison);
            else
                printf("Error\n");
            break;
        case 3:
            for(i=0;i<TABLESIZE;i++) printf("%d: %d %c\n",i, hashTable[i].key,hashTable[i].indicator==DELETED?'*':' ');
            break;
        }
        printf("Enter selection: ");
        scanf("%d",&opt);
    }
    return 0;
}

int hash1(int key)
{
    return (key % TABLESIZE);
}

int hash2(int key)
{
    return (key % PRIME) + 1;
}

/*HashTable Open Addressing Double Hashing Pseudocode Insert
1) index= hash1(key + k*hash2(key))
2) if slot is empty, check if deleted slot has been encountered
3)      if yes, insert at deleted slot and exit
4)      if not, insert at current empty slot and exit
5) else if slot is deleted, save the deleted index if deleted slot has not already been encountered(means this deleted slot is the first deleted slot we encounter), else do nothing
6) else if slot is used, check if the key equals to the target insert key
7)      if yes, return fail status if no duplicates allowed
8)      if no, increment k by 1
9) before repeating the start, check if k has reached tablesize, if yes it means we have visited every slot in the whole table
10) if a deleted slot has been found insert at the deleted slot, if no means the whole table is completely full, return error
11) continue with step 1

 */

int HashInsert(int key, HashSlot hashTable[])
{
   //Write your code here
   if(!hashTable) return -1;
   int k=0;
   int comparisons=0;
   int deletedSlot=-1;
   while(1){
    //means checked through the whole table alr
    if(k>=TABLESIZE){
        if(deletedSlot==-1) return comparisons;
        else{
            hashTable[deletedSlot].key=key;
            hashTable[deletedSlot].indicator=USED;
            return comparisons;
        }
    }

    int index= hash1(key + k*hash2(key));

    if(hashTable[index].indicator==EMPTY){
        if(deletedSlot==-1){
            hashTable[index].key=key;
            hashTable[index].indicator=USED;
            return comparisons;
        }
        else{
            hashTable[deletedSlot].key=key;
            hashTable[deletedSlot].indicator=USED;
            return comparisons;
        }
    }
    else if(hashTable[index].indicator==DELETED && deletedSlot==-1){
        deletedSlot=index;

        
    }
    else if(hashTable[index].indicator==USED){
        if(hashTable[index].key==key){
        return -1;
        }
        else comparisons++;
    }
    
    k++;
    

}

}

/*HashTable Open Addressing Double Hashing Pseudocode Delete
1) index= hash1(key + k*hash2(key))
2) if slot is empty, the target to delete does not exist in the hashtable, return error
3) else if slot is deleted, do nothing since we are not concerned with deleted slots
4) else if slot is used, check if the key equals to the target insert key
5)      if yes, mark the slot as deleted
6)      if no, increment k by 1
7) before repeating the start, check if number of comparisons with a valid key has reached tablesize, if yes it means we have visited every slot in the whole table
and that the target value to delete does not exist in hashtable, return error
8) continue with step 1

 */

int HashDelete(int key, HashSlot hashTable[])
{
   //Write your code here
   if(!hashTable) return -1;
   int k=0;
   int comparisons=0;
   while(1){
    int index= hash1(key + k*hash2(key));
    if(hashTable[index].indicator==EMPTY){
        return -1;
    } 
    else if(hashTable[index].indicator==USED){
        comparisons++;
        if(hashTable[index].key==key){
            hashTable[index].indicator=DELETED;
            return comparisons;
    }
   }
   if(comparisons>=TABLESIZE) return -1;
   k++;
}

}