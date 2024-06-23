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
}

// you can actually define structs and function prototypes below main() and even inside functions
//function prototypes and structs defined inside functions are scope to inside that function and cant be called or acessed outside of the function
typedef struct _bstnode{
	int item;
	struct _bstnode *left;
	struct _bstnode *right;
} BSTNode;   // You should not change the definition of BSTNode

typedef struct _stackNode{
	BSTNode *data;
	struct _stackNode *next;
}StackNode; // You should not change the definition of StackNode

typedef struct _stack
{
	StackNode *top;
}Stack; // You should not change the definition of Stack

typedef struct _graph{
    int V;
    int E;
    BSTNode **list;
}Graph;

void insertBSTNode(BSTNode **node, int value);
void push(Stack *stack, BSTNode *node);
BSTNode *pop(Stack *s);
BSTNode *peek(Stack *s);
int isEmpty(Stack *s);
void removeAll(BSTNode **node);


int* city_population (int N, int* population, int** road, int Q, int** cities) 
{
    //init
    int count=0;
    Graph g;
    g.V=N;
    g.E=N-1;    //given exactly 1 to each city
    g.list = (BSTNode **) malloc(g.V*sizeof(BSTNode *));
    for(int i=0;i<g.V;i++){
        g.list[i] = NULL;
    }
    for(int i=0;i<g.E;i++){
        
        //undirected graph so for each edge, need 2 entries
        int city1=road[i][0];
        int city2=road[i][1];

        insertBSTNode(&g.list[city1-1],city2);
        insertBSTNode(&g.list[city2-1],city1);

    }
    
    for(int i=0;i<Q;i++){
        int start=cities[i][0];
        int end=cities[i][1];
        int threshold=cities[i][2];

    }









}

void insertBSTNode(BSTNode **node, int value){
	if (*node == NULL)
	{
		*node = malloc(sizeof(BSTNode));

		if (*node != NULL) {
			(*node)->item = value;
			(*node)->left = NULL;
			(*node)->right = NULL;
		}
	}
	else
	{
		if (value < (*node)->item)
		{
			insertBSTNode(&((*node)->left), value);
		}
		else if (value >(*node)->item)
		{
			insertBSTNode(&((*node)->right), value);
		}
		else
			return;
	}
}
void push(Stack *stack, BSTNode * node)
{
	StackNode *temp;

	temp = malloc(sizeof(StackNode));

	if (temp == NULL)
		return;
	temp->data = node;

	if (stack->top == NULL)
	{
		stack->top = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = stack->top;
		stack->top = temp;
	}
}


BSTNode * pop(Stack * s)
{
	StackNode *temp, *t;
	BSTNode * ptr;
	ptr = NULL;

	t = s->top;
	if (t != NULL)
	{
		temp = t->next;
		ptr = t->data;

		s->top = temp;
		free(t);
		t = NULL;
	}

	return ptr;
}

BSTNode * peek(Stack * s)
{
	StackNode *temp;
	temp = s->top;
	if (temp != NULL)
		return temp->data;
	else
		return NULL;
}

int isEmpty(Stack *s)
{
	if (s->top == NULL)
		return 1;
	else
		return 0;
}


void removeAll(BSTNode **node)
{
	if (*node != NULL)
	{
		removeAll(&((*node)->left));
		removeAll(&((*node)->right));
		free(*node);
		*node = NULL;
	}
}

int searchBST(BSTNode* cur,int num){
    if(!cur) return 0;
    if(num== cur->item) return 1;
    else if (num< cur->item) searchBST(cur->left,num);
    else searchBST(cur->right,num);
}

int DFS(Graph g,int* population,int start, int end,int threshold){
    /*This DFS returns the number of cities at have population of at most w*/
    if(g.V<1) return; //empty graph

    int counter=0;

    Stack s;
    s.top=NULL;

    int* visited=(int*)malloc(g.V*sizeof(int));
    for(int i=0;i<g.V;i++){
        visited[i]=0;
    }

    
    push(&s, start);
    visited[start-1]=1;
    while(!isEmptyStack(s)){
        int current=peek(&s);
        int gotNeighbours=0;
        //goal test
        if(current==end) return counter;
        BSTNode* currentNode=g.list[current-1];
        BSTNode* trav=currentNode;
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
    free(visited);
}
