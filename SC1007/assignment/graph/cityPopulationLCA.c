#include<stdio.h>
#include <stdlib.h>
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
int LCA(int* population,int start, int end,int threshold,int* Parent,int* Depth);
void DFS_once(Graph g,int* Parent, int* Depth,int root);
  
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


    for(int i=0;i<g.E;i++){
        
        //undirected graph so for each edge, need 2 entries
        int city1=road[i][0];
        int city2=road[i][1];

        insertNode(&g.list[city1-1], city2);
        insertNode(&g.list[city2-1],city1);

    }

    DFS_once(g,Parent,Depth,ROOT);

    //start
    for(int i=0;i<Q;i++){

        int start=cities[i][0];
        int end=cities[i][1];
        int threshold=cities[i][2];
        result=LCA(population,start,end,threshold,Parent,Depth);
        results[i]=result;
        


    }

    //free everything
    for(int i=0;i<g.V;i++){
        removeAllItems(&g.list[i]);
    }
    free(g.list);
    free(Parent);
    free(Depth);
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

int LCA(int* population,int start, int end,int threshold,int* Parent,int* Depth){
    /*This returns the number of cities at have population of at most w*/
    //dont even need the graph, all the connections are stored in Parent array

    Stack s;
    s.head=NULL;
    s.size=0;
    int counter=0;
    int u=start;
    int v=end;
    while(Depth[u-1]!=Depth[v-1]){ //continuously move the nodes up to their parent until they are at the same depth


        if(Depth[u-1]>Depth[v-1]){//before moving up to parent, add current node to stack
            push(&s,u);
            u=Parent[u-1];
        }
        else {
            push(&s,v);
            v=Parent[v-1];
        }
    }

    while(u!=v){
        push(&s,u);
        push(&s,v);
        u=Parent[u-1];
        v=Parent[v-1];
    }
    //add LCA to stack also since its part of the path
    push(&s,u);

    while(!isEmptyStack(s)){
        int tmp=peek(s);
        pop(&s);
        if(population[tmp-1]<=threshold) counter++;
    } 
    return counter;

}

void DFS_once(Graph g,int* Parent, int* Depth,int root){

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
    while(!isEmptyStack(s)){
        int current=peek(s);
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
        if(!gotNeighbours) pop(&s);


    }
    free(visited);
    removeAllItemsFromStack(&s);
    return;

}
