#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
 int vertex;
 struct _listnode *next;
} ListNode;

typedef struct _weightedlistnode
{
 int vertex;
 int weight;
 struct _weightedlistnode *next;
}  WeightedListNode;

typedef ListNode StackNode;

typedef struct _graph{
 int V;
 int E;
 WeightedListNode **list;
}Graph;

typedef ListNode QueueNode;

typedef struct _queue{
 int size;
 QueueNode *head;
 QueueNode *tail;
} Queue;

typedef struct _stack
{
 int size;
 StackNode *head;
} Stack;

WeightedListNode* findAdjVertex(WeightedListNode** AdjList,int vertex);
void insertAdjVertex(WeightedListNode** AdjList,int vertex);
void removeAdjVertex(WeightedListNode** AdjList,int vertex);
int matching(Graph g);
int DFS(Graph g,int start, int end,Queue *path);
Graph copyGraph(Graph g);
void printGraphList(Graph );

void enqueue(Queue *qPtr, int item);
int dequeue(Queue *qPtr);
int getFront(Queue q);
int isEmptyQueue(Queue q);
void removeAllItemsFromQueue(Queue *qPtr);
void printQ(QueueNode *cur);
//////STACK///////////////////////////////////////////
void push(Stack *sPtr, int vertex);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);
void removeAllItemsFromStack(Stack *sPtr);

//////////////////////////////////
//GLOBAL VAR
int Prj, Std, Mtr; //Project, Student and Mentor;
/*LESSON:  
- FOR MATCHING PURPOSES WHERE ALL EDGES HAVE CAPACITY 1 AND FLOW 1 RESIDUAL GRAPH IS ALL THAT MATTERS
- since we are not concerned w finding or keeping track of max flow
-by right no need update the original graph at all, just need to keep augmenting paths and reversing edges in residual graph until no path can be found
-if non-1 flow is concerned, we need both forward and backward weighted edges for both graphs to keep track of residual capacities
-instead of reversing edges we would add and subtract the min flow found during each iteration

FOR TRIPARTITE: SHORTCOMINGS
-  once a path has been found
-  unable to differentiate paths that are trying to improve on previous matches and paths that are trying to match one student multiple times
-  a matched array to check if students have already been matched also will not work since iterative improvement can also includes visiting the same node twice to improve prev matches
-  BFS would not be better than DFS
-  edmond's karp algorithm of using BFS to look for the shortest augmenting paths would only work for maximum flow problems and not maximum matching problems
-  idea of using BFS instead of DFS, and changing graph to having both forward and backward edges to update the "capacities" would also not work
*/
int main()
{
 
 int maxMatch;
 scanf("%d %d %d", &Std, &Prj, &Mtr);
 //THIS IS NATURAL NUMBER NOT START FROM 0
 //number of projects start from 1 to Prj
 //number of students start from Prj+1 to Prj+Std
 //number of mentors start from Prj+Std+1 to Prj+Std+Mtr
 //s is at Prj+Std+Mtr+1
 //t is at Prj+Std+Mtr+2


 //build graph
 Graph g;
 g.V=Prj+Std+Mtr+2;  //last 2 is s, last one is t
 g.list=(WeightedListNode**)malloc(sizeof(WeightedListNode*)*g.V);
 //Write your code
 //default weight of 0 indicates that the path in original graph has not been confirmed
for(int i=1;i<=Std;i++){
   int np,nm; //number of projects and number of mentors
   scanf("%d %d",&np,&nm);
   for(int j=0;j<np;j++){
      int tmp;
      scanf("%d",&tmp);
      insertAdjVertex(&g.list[tmp-1],Prj+i);
      g.E++;
   }
   for(int k=0;k<nm;k++){
      int tmp;
      scanf("%d",&tmp);
      insertAdjVertex(&g.list[Prj+i-1],Prj+Std+tmp);
      g.E++;
   }
}
//add the s and t connections
for(int i=1;i<=Prj;i++){
   insertAdjVertex(&g.list[Prj+Std+Mtr+1-1],i);
   g.E++;
}
for(int i=Prj+Std+1;i<=Prj+Std+Mtr;i++){
   insertAdjVertex(&g.list[i-1],Prj+Std+Mtr+2);
   g.E++;
}



 //apply Ford Fulkerson algorithm
 // use DFS or BFS to find a path
 maxMatch = matching(g);
 printf("%d\n", maxMatch);
 return 0;
}

int matching(Graph g)
{
   int counter=0; //the number of matches is exactly the number of times the ford-fulkerson algorithm runs, since each run will produce a new path
 //Write your code
 Graph h=copyGraph(g);// h is the residue graph
 printGraphList(h);
Queue path;
path.head=NULL;
path.tail=NULL;
path.size=0;
while(DFS(h, Prj+Std+Mtr+1, Prj+Std+Mtr+2,&path)){   //the start and end points must be the real node numbers, not those that start w 0

   int first=-1;
   int second=-1;

   while(!isEmptyQueue(path)){

      //only get value for first on the very time
      if(first==-1){
         first=getFront(path);
         dequeue(&path);
      }
      else first=second;
      
      second=getFront(path);
      dequeue(&path);
      //printf("first second is %d %d\n",first,second);
      //now theres definitely a edge from first to second in residual graph
      //then find edge of first to second in the original graph
      WeightedListNode* find= findAdjVertex(&g.list[first-1], second);
      if(find){
         find->weight++;
      }
      else{
         //if cannot find then there must be a edge from second to first in the original graph
         WeightedListNode* tmp= findAdjVertex(&g.list[second-1], first);
         if(tmp) tmp->weight--;
      }
      //reversal of connection in residual graph
      removeAdjVertex(&h.list[first-1], second);
      insertAdjVertex(&h.list[second-1],first);
   }
   
   counter++;
   //printGraphList(g);
   //printGraphList(h);
 }

 return counter;

}

void removeAdjVertex(WeightedListNode** AdjList,int vertex)
{
 WeightedListNode *temp, *preTemp;
 if(*AdjList != NULL)
 {
    if((*AdjList)->vertex ==vertex){//first node
      temp = *AdjList;
      *AdjList = (*AdjList)->next;
      free(temp);
      return;
    }
    preTemp = *AdjList;
    temp = (*AdjList)->next;
    while(temp!=NULL && temp->vertex != vertex)
    {
      preTemp= temp;
      temp = temp->next;
    }
    preTemp->next = temp->next;
    free(temp);
   }
}

void insertAdjVertex(WeightedListNode** AdjList,int vertex)
{
  WeightedListNode *temp;
  if(*AdjList==NULL)
  {
     *AdjList = (WeightedListNode *)malloc(sizeof(WeightedListNode));
     (*AdjList)->vertex = vertex;
     (*AdjList)->weight = 0;  //default weight of 0 indicates that the path in original graph has not been confirmed
     (*AdjList)->next = NULL;
  }
  else{
     temp = (WeightedListNode *)malloc(sizeof(WeightedListNode));
     temp->vertex = vertex;
     temp->weight=0;
     temp->next = *AdjList;
     *AdjList = temp;
  }
}

void enqueue(Queue *qPtr, int vertex) {
  QueueNode *newNode;
  newNode = malloc(sizeof(QueueNode));
  if(newNode==NULL) exit(0);

  newNode->vertex = vertex;
  newNode->next = NULL;

  if(isEmptyQueue(*qPtr))
     qPtr->head=newNode;
  else
     qPtr->tail->next = newNode;

     qPtr->tail = newNode;
     qPtr->size++;
}

int dequeue(Queue *qPtr) {
   if(qPtr==NULL || qPtr->head==NULL){ //Queue is empty or NULL pointer
     return 0;
   }
   else{
     QueueNode *temp = qPtr->head;
     qPtr->head = qPtr->head->next;
     if(qPtr->head == NULL) //Queue is emptied
       qPtr->tail = NULL;

     free(temp);
     qPtr->size--;
     return 1;
}
}

int getFront(Queue q){
    return q.head->vertex;
}

int isEmptyQueue(Queue q) {
   if(q.size==0) return 1;
   else return 0;
}

void removeAllItemsFromQueue(Queue *qPtr)
{
  while(dequeue(qPtr));
}

void printQ(QueueNode *cur){
 if(cur==NULL) printf("Empty");

 while (cur != NULL){
    printf("%d ", cur->vertex);
    cur = cur->next;
  }
 printf("\n");
}

void push(Stack *sPtr, int vertex)
{
  StackNode *newNode;
  newNode= malloc(sizeof(StackNode));
  newNode->vertex = vertex;
  newNode->next = sPtr->head;
  sPtr->head = newNode;
  sPtr->size++;
}

int pop(Stack *sPtr)
{
  if(sPtr==NULL || sPtr->head==NULL){
     return 0;
  }
  else{
     StackNode *temp = sPtr->head;
     sPtr->head = sPtr->head->next;
     free(temp);
     sPtr->size--;
     return 1;
   }
}

int isEmptyStack(Stack s)
{
    if(s.size==0) return 1;
    else return 0;
}

int peek(Stack s){
   return s.head->vertex;
}

void removeAllItemsFromStack(Stack *sPtr)
{
   while(pop(sPtr));
}
void printGraphList(Graph g){
    int i;
    WeightedListNode* temp;


    printf("Printing the list:\n");
    for(i=0;i<g.V;i++)
    {
        printf("%d:\t",i+1);
        temp = g.list[i];
        while(temp!=NULL){
            printf("%d -> ",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
WeightedListNode* findAdjVertex(WeightedListNode** AdjList,int vertex){
   /*check if vertex is in ONE linked list*/
   if(!*AdjList) return 0;
   WeightedListNode* trav=*AdjList;
   while(trav){
      if(trav->vertex==vertex) return trav;
      else trav=trav->next;
   }

   return 0;
}
int DFS(Graph g,int start, int end,Queue *path){
    /*This DFS returns the path between start and end in the path array, it returns path in the correct order in the path array which is a queue*/
    if(g.V<1) return 0; //empty graph

    Stack s;
    s.head=NULL;
    s.size=0;

    int* visited=(int*)malloc(g.V*sizeof(int));
    for(int i=0;i<g.V;i++){
        visited[i]=0;
    }

    
    push(&s, start);
    visited[start-1]=1;
    printf("start\n");
    while(!isEmptyStack(s)){
        int current=peek(s);
        printf("current is %d\n",current);
        int gotNeighbours=0;
        //goal test
        if(current==end) break;
        WeightedListNode* currentNode=g.list[current-1];
        while(currentNode){    //finding univisted neighbours WRONG, DFS we are only supposed to choose ONE node to visit, not add every neighbour to stack
            if(visited[currentNode->vertex-1]==0){
                visited[currentNode->vertex-1]=1;
                push(&s, currentNode->vertex);
                gotNeighbours=1;
                break;
            }
            currentNode=currentNode->next;
        }
        if(!gotNeighbours) pop(&s);


    }

    //if the stack is empty at this point means theres no path from start to end, just quit
    if(isEmptyStack(s)) {
      free(visited);
      return 0;
      }


    Stack s2;  //used for reversing the path
    s2.head=NULL;
    s2.size=0;
    while(!isEmptyStack(s)){
        int tmp=peek(s);
        pop(&s);
        push(&s2, tmp);
    }
   while(!isEmptyStack(s2)){
        int tmp=peek(s2);
        pop(&s2);
        enqueue(&path, tmp);
    }
    free(visited);

    return 1;
}

Graph copyGraph(Graph g){
   Graph h;
   h.V=g.V;
   h.E=g.E;
   
   h.list=(WeightedListNode**)malloc(sizeof(WeightedListNode*)*h.V);
   for(int i=0;i<h.V;i++){
      WeightedListNode* trav=g.list[i];
      while (trav){
         insertAdjVertex(&h.list[i],trav->vertex);
         trav=trav->next;
      }
   }
   return h;

}