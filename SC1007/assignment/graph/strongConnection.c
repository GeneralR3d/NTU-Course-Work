#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
    int vertex;
	struct _listnode *next;
} ListNode;
typedef ListNode StackNode;

typedef struct _graph{
    int V;
    int E;
    ListNode **list;
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

int CC (Graph g);

void printGraphList(Graph );

// You should not change the prototypes of these functions
void enqueue(Queue *qPtr, int item);
int dequeue(Queue *qPtr);
int getFront(Queue q);
int isEmptyQueue(Queue q);
void removeAllItemsFromQueue(Queue *qPtr);
//////STACK///////////////////////////////////////////
void push(Stack *sPtr, int vertex);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);
void removeAllItemsFromStack(Stack *sPtr);
//////////////////////////////////

int main()
{
    Graph g;
    int i,j;
    ListNode *temp;

    printf("Enter the number of vertices:\n");
    scanf("%d",&g.V);

        g.list = (ListNode **) malloc(g.V*sizeof(ListNode *));

        for(i=0;i<g.V;i++)
            g.list[i] = NULL;

    printf("Enter two vertices which are adjacent to each other:\n");
    while(scanf("%d %d",&i,&j)==2)
    {
        i=i-1;

        if(g.list[i]==NULL){
            g.list[i] = (ListNode *)malloc(sizeof(ListNode));
            g.list[i]->vertex = j;
            g.list[i]->next = NULL;
        }
        else{
            temp = (ListNode *)malloc(sizeof(ListNode));
            temp->next = g.list[i];
            temp->vertex = j;
            g.list[i] = temp;
        }
        g.E++;
        printf("Enter two vertices which are adjacent to each other:\n");
    }
    scanf("%*c");

    int res = CC(g);
    if(res ==1)
        printf("The graph is strongly connected.\n");
    else
        printf("The graph is not strongly connected.\n");

    printGraphList(g);
    return 0;
}

void printGraphList(Graph g){
    int i;
    ListNode* temp;

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

void DFS(Graph g, int* visited,int start);
void DFS_proper(Graph g, int* visited,int start);

/*Following is Kosaraju’s DFS based simple algorithm that does two DFS traversals of graph: 

Initialize all vertices as not visited.
Do a DFS traversal of graph starting from any arbitrary vertex v. If DFS traversal doesn’t visit all vertices, then return false.
Reverse all arcs (or find transpose or reverse of graph) 
Mark all vertices as not-visited in reversed graph.
Do a DFS traversal of reversed graph starting from same vertex v (Same as step 2). If DFS traversal doesn’t visit all vertices, then return false. Otherwise return true.
*/
int CC (Graph g)
{
 // Write your code here
 if(!g.list) return 0; //sanity check
 if(g.V<1) return 0;  //empty graph
 if(g.E<g.V) return 0; //strongly connected graph edges must be at least same as vertices since each node must at least have one arrowing pointing to it, ie one way to get to that node


    int* visited =(int*)malloc(g.V *sizeof(int));
    for(int i=0;i<g.V;i++){
        visited[i]=0;
    }

    //pick any point as starting point and let it run, just pick node 1 in this case
    int start =1;
    DFS_proper(g,visited,start);
    //check through for 0s, ie no path from start to that node
    for(int i=0;i<g.V;i++){
        if(visited[i]==0) return 0;;
    }
    //reverse all connections
    ListNode** newlist = (ListNode **) malloc(g.V*sizeof(ListNode *));

    for(int i=0;i<g.V;i++)
        newlist[i] = NULL;

    for(int i=0;i<g.V;i++){
        ListNode* trav=g.list[i];
        while (trav)
        {
            ListNode* tmp= (ListNode *)malloc(sizeof(ListNode));
            tmp->vertex=i+1;
            tmp->next=newlist[trav->vertex-1];
            newlist[trav->vertex-1]=tmp;

            trav=trav->next;
        }
        
    }

    //change the graph list while temporariy storing the old one
    ListNode** storage =g.list;
    g.list=newlist;




    //reset all back to unvisted before doing another DFS
    for(int i=0;i<g.V;i++){
        visited[i]=0;
    }


    DFS_proper(g,visited,start);
    //check through for 0s, ie no path from any node to start
    for(int i=0;i<g.V;i++){
        if(visited[i]==0) return 0;;
    }
    //The idea is, if every node can be reached from a vertex v, and every node can reach v, then the graph is strongly connected. 
    //ie at this point, graph is strongly connected
    g.list=storage; //return the original graph back

    for(int i=0;i<g.V;i++){
        ListNode* trav=newlist[i];
        while(trav){
            ListNode* tmp=trav;
            trav=trav->next;
            free(tmp);
        }
    }
    free(visited);
    return 1;
}

// WRONG WRONG WRONG    
/**Edit: this is not how proper DFS is carried out. 
 Proper DFS only chooses 1 unexplored neighbour to explore at any one time, the rest of the unexplored neighbours do not get added to the frontier until that chosen path backtracks all the way.
 This also means that in actual DFS we cannot pop the element of the top of the stack since we have not fully explored it, we can only peek it and only pop once its fully explored. 
 However in this specific case we add ALL UNEXPLORED NEIGHBOURS to the frontier, therefore it is ok to directly pop the node off the stack since we will never need to access it again. 
 Functionally this also achieves the effect of finding a solution to the goal, however this is not proper DFS
*/
void DFS(Graph g, int* visited,int start){ //WRONG but functionally still allows it to check if there is a path to every node
    if(g.V<1) return; //empty graph

    Stack s;
    s.head=NULL;
    s.size=0;

    //pick any point as starting point and let it run, just pick node 1 in this case
    push(&s, start);
    visited[start-1]=1;
    while(!isEmptyStack(s)){
        int current=peek(s);
        pop(&s);
        //no need for a goal test, let it run finish
        ListNode* currentNode=g.list[current-1];
        ListNode* trav=currentNode;
        while(trav){    //finding univisted neighbours WRONG, DFS we are only supposed to choose ONE node to visit, not add every neighbour to stack
            if(visited[trav->vertex-1]==0){
                visited[trav->vertex-1]=1;
                push(&s, trav->vertex);
            }
            trav=trav->next;
        }


    }
}

void DFS_proper(Graph g, int* visited,int start){
    if(g.V<1) return; //empty graph

    Stack s;
    s.head=NULL;
    s.size=0;

    //pick any point as starting point and let it run, just pick node 1 in this case
    push(&s, start);
    visited[start-1]=1;
    while(!isEmptyStack(s)){
        int current=peek(s);
        int gotNeighbours=0;
        //no need for a goal test, let it run finish
        ListNode* currentNode=g.list[current-1];
        ListNode* trav=currentNode;
        while(trav){    //finding univisted neighbours WRONG, DFS we are only supposed to choose ONE node to visit, not add every neighbour to stack
            if(visited[trav->vertex-1]==0){
                visited[trav->vertex-1]=1;
                push(&s, trav->vertex);
                gotNeighbours=1;
                break;
            }
            trav=trav->next;
        }
        if(!gotNeighbours) pop(&s);


    }
}