#include<stdio.h>
#include <stdlib.h>

  
int* city_population (int N, int* population, int** road, int Q, int** cities) ;


int main() {
    int N;
    scanf("%d", &N);
    int i_population;
    int *population = (int *)malloc(sizeof(int)*(N));
    for(i_population = 0; i_population < N; i_population++)
    	scanf("%d", &population[i_population]);
    int i_road, j_road;
    int **road = (int **)malloc((N-1)*sizeof(int *));
    for(i_road = 0; i_road < N-1; i_road++)
    {
    	road[i_road] = (int *)malloc((2)*sizeof(int));
    }
    for(i_road = 0; i_road < N-1; i_road++)
    {
    	for(j_road = 0; j_road < 2; j_road++)
    	{
    		scanf("%d", &road[i_road][j_road]);
    	}
    }
    int Q;
    scanf("%d", &Q);
    int i_cities, j_cities;
    int **cities = (int **)malloc((Q)*sizeof(int *));
    for(i_cities = 0; i_cities < Q; i_cities++)
    {
    	cities[i_cities] = (int *)malloc((3)*sizeof(int));
    }
    for(i_cities = 0; i_cities < Q; i_cities++)
    {
    	for(j_cities = 0; j_cities < 3; j_cities++)
    	{
    		scanf("%d", &cities[i_cities][j_cities]);
    	}
    }

    int* out_ = city_population(N, population, road, Q, cities);
    printf("%d", out_[0]);
    int i_out_;
    for(i_out_ = 1; i_out_ < Q; i_out_++)
    	printf("\n%d", out_[i_out_]);
    //free everything
    for(i_cities = 0; i_cities < Q; i_cities++)
    {
    	free(cities[i_cities]);
    }
    free(cities);
    for(i_road = 0; i_road < N-1; i_road++)
    {
    	free(road[i_road]);
    }
    free(road);
    free(population);
    free(out_);

}
// you can actually define structs and function prototypes below main() and even inside functions
//function prototypes and structs defined inside functions are scope to inside that function and cant be called or acessed outside of the function
typedef struct _listnode
{
    int vertex;
	struct _listnode *next;
} ListNode;
typedef ListNode StackNode;

typedef struct _linkedlist{
    int size;
    ListNode *head;
    ListNode *tail;
} LinkedList;

typedef struct _graph{
    int V;
    int E;
    LinkedList *list;
}Graph;
typedef struct _stack
{
	int size;
	StackNode *head;
} Stack;

void push(Stack *sPtr, int vertex);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);
void removeAllItemsFromStack(Stack *sPtr);
int insertNode(LinkedList *ll, int value);
void removeAllItems(LinkedList *ll);
void HLD(Graph g,int* chainHead,int* position,int* subtreeSize,int* parent,int root, int head);
void DFS_once(Graph g,int* Parent, int* Depth,int* subtreeSize,int root);
int queryTree(int start, int end,int threshold,int* chainHead,int* depth,int* position,int* population,int* parent);
int query(int start,int end,int threshold,int* population,int* position);


int pos=0;//the only global variable here for every call of the HLD
int* city_population (int N, int* population, int** road, int Q, int** cities){

    //init
    int result=0;
    Graph g;
    g.V=N;
    g.E=N-1;    //given exactly 1 to each city

    g.list = (LinkedList *) malloc(g.V*sizeof(LinkedList));
    for(int i=0;i<g.V;i++){
        g.list[i].head=NULL;
        g.list[i].tail=NULL;
        g.list[i].size=0;
    }

    int* results=(int*)malloc(sizeof(int)*Q);
    for(int i=0;i<Q;i++) results[i] =0;

    int* Parent=(int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++) results[i] =0;
    int ROOT=1;//1st node is defined as the root
    Parent[ROOT-1]=-1;//only the root has no parent

    int* Depth=(int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++) Depth[i]=0;
    Depth[ROOT-1]=0;//root has 0 depth

    int* subtreeSize=(int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++) subtreeSize[i] =0;

    int* chainHead=(int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++) chainHead[i] =0;

    int* position=(int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++) position[i] =0;


    for(int i=0;i<g.E;i++){
        
        //undirected graph so for each edge, need 2 entries
        int city1=road[i][0];
        int city2=road[i][1];

        insertNode(&g.list[city1-1], city2);
        insertNode(&g.list[city2-1],city1);

    }

    DFS_once(g,Parent,Depth,subtreeSize,ROOT);
    pos=0;//init to 0 just in case
    HLD(g,chainHead,position,subtreeSize,Parent,1,1);//the root node is its own head of the chain and in fact the very first chain

    //start
    for(int i=0;i<Q;i++){

        int start=cities[i][0];
        int end=cities[i][1];
        int threshold=cities[i][2];
        result=queryTree(start,end,threshold,chainHead,Depth,position,population,Parent);
        results[i]=result;
        


    }

    //free everything
    for(int i=0;i<g.V;i++){
        removeAllItems(&g.list[i]);
    }
    free(g.list);
    free(Parent);
    free(Depth);
    free(subtreeSize);
    free(chainHead);
    free(position);
    return results;
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
void removeAllItems(LinkedList *ll)
{
    if(!ll)return;
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

//custom insertnode which always inserts at the front
int insertNode(LinkedList *ll, int value){
    if(!ll) return 0;
    if(!ll->head){
            ll->head = (ListNode *)malloc(sizeof(ListNode));
            ll->tail=ll->head;
            ll->head->vertex=value;
            ll->head->next=NULL;
        }
        else{
            ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
            temp->next = ll->head;
            temp->vertex = value;
            ll->head = temp;
        }
    ll->size++;
    return 1;

    }



void DFS_once(Graph g,int* Parent, int* Depth,int* subtreeSize,int root){

    if(g.V<1) return; //empty graph

    Stack s;
    s.head=NULL;
    s.size=0;

    int* visited=(int*)malloc(g.V*sizeof(int));
    for(int i=0;i<g.V;i++){
        visited[i]=0;
    }

    
    push(&s, root);
    visited[root-1]=1;
    int subtree=0;
    while(!isEmptyStack(s)){
        int current=peek(s);
        subtreeSize[current-1]+=subtree;
        subtree=0;
        int gotNeighbours=0;
        //no goal test
        ListNode* currentNode=g.list[current-1].head;
        while(currentNode){    //finding univisted neighbours WRONG, DFS we are only supposed to choose ONE node to visit, not add every neighbour to stack
            if(visited[currentNode->vertex-1]==0){
                visited[currentNode->vertex-1]=1;
                push(&s, currentNode->vertex);
                gotNeighbours=1;
                Depth[currentNode->vertex-1]= Depth[current-1]+1;
                Parent[currentNode->vertex-1]= current;
                break;
            }
            currentNode=currentNode->next;
        }
        if(!gotNeighbours) {
            subtree=subtreeSize[current-1]+1;//save before backtrack to return value to parent
            pop(&s);
        }


    }
    free(visited);
    removeAllItemsFromStack(&s);
    return;

}
void HLD(Graph g,int* chainHead,int* position,int* subtreeSize,int* parent,int root, int head){
    int heavyChild=-1;
    int maxSubtreeSize=0;
    chainHead[root-1]=head;
    position[root-1]=pos;
    pos++;
    ListNode* trav=g.list[root-1].head;
    while(trav){
        if(trav->vertex==parent[root-1]) {
            trav=trav->next;
            continue;
        }
        if(subtreeSize[trav->vertex-1]>maxSubtreeSize){
            maxSubtreeSize=subtreeSize[trav->vertex-1];
            heavyChild=trav->vertex;
        }
        trav=trav->next;
    }
    if(heavyChild!=-1){
        HLD(g,chainHead,position,subtreeSize,parent,heavyChild,head);
    }
    ListNode* trav=g.list[root-1].head;
    while(trav){
        if(trav->vertex==parent[root-1] || trav->vertex==heavyChild) {
            trav=trav->next;
            continue;
        }
        HLD(g,chainHead,position,subtreeSize,parent,trav->vertex,trav->vertex);
        trav=trav->next;
    }
    return;



}


int queryTree(int start, int end,int threshold,int* chainHead,int* depth,int* position,int* population,int* parent){
    /*Queries across the tree that has been decomposed into heavy and light chains.
    End point will be the LCA*/
    int counter=0;

    while(chainHead[start-1]!=chainHead[end-1]){
        if(depth[chainHead[start-1]]>depth[chainHead[end-1]]){
            int tmp=start;
            start=end;
            end=tmp;
        }
        counter+=query(chainHead[end-1],end,threshold,population,position);
        end=parent[chainHead[end-1]] +1;
    }

    if(depth[start-1]>depth[end-1]){
            int tmp=start;
            start=end;
            end=tmp;
        }
        counter+=query(start,end,threshold,population,position);

    return counter;

}

int query(int start,int end,int threshold,int* population,int* position){
    int counter=0;
    if(end>start){
        int tmp=start;
        start=end;
        end=tmp;
    }
    while(start!=end){
        if(population[position[start]]<=threshold) counter++;
        start--;
    }
    if(population[position[start]]<=threshold) counter++;//add in the final one

    return counter;
}


/*
void makeSegmentTree(int* input, int* segtree, int start, int end, int root){
    if(start==end){
        segtree[root]=input[low];
        return;
    }
    int mid=(start+end)/2;
    makeSegmentTree(input,segtree,start,mid,root*2 +1);
    makeSegmentTree(input,segtree,mid+1,end,root*2 +2);
    segtree[root]=segtree[root*2+1] + segtree[root*2+2];
}

int sumInRange(int* segtree,int arrayStart, int arrayEnd, int qStart, int qEnd, int root){
    //complete overlap
    if(qStart<= arrayStart && qEnd>=arrayEnd){
        return segtree[root];
    }
    //no overlap
    if(qStart>arrayEnd || qEnd< arrayStart){
        return 0;
    }
    int mid=(arrayStart+arrayEnd)/2;
    return sumInRange(segtree,arrayStart,mid,qStart,qEnd,root*2+1)+ sumInRange(segtree,mid+1,arrayEnd,qStart,qEnd,root*2+2);

}

int findLCA(int root,int x,int y){
    

}
*/