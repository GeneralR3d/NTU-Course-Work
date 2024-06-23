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

typedef struct _listnode
{
    int vertex;
	struct _listnode *next;
} ListNode;

typedef ListNode StackNode;
typedef struct _stack
{
	int size;
	StackNode *head;
} Stack;


//////STACK///////////////////////////////////////////
void push(Stack *sPtr, int vertex);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);
void removeAllItemsFromStack(Stack *sPtr);
/////////////////////////////////

void push(Stack *val, int vertex)
{
	StackNode *cur;
    cur= malloc(sizeof(StackNode));
    cur->vertex = vertex;
    cur->next = val->head;
    val->head = cur;
    val->size++;
}

int pop(Stack *val)
{
    if(val==NULL || val->head==NULL){
        return 0;
    }
    else{
       StackNode *cur = val->head;
       val->head = val->head->next;
       
       val->size--;
       free(cur);
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

int *parList, *dList, *heavyList, *headList, *positionList, *poplistg;
int cur_pos, max_g;

int dfs_search (int root, ListNode **adjList){
    int s = 1;
    int max_size = 0;

    ListNode *cur;

    cur = adjList[root];

    while (cur != NULL){
        if (((cur->vertex) - 1) != parList[root]){
            parList[(cur->vertex) - 1] = root;  //parList stores every node's parent
            dList[(cur->vertex) - 1] = dList[root] + 1; //dList stores every node's depth
            int curSize = dfs_search((cur->vertex) - 1, adjList);   //recursively do it
            s += curSize;   //the total number of nodes under you is the sum of the number of nodes under each of your direct children

            if (curSize > max_size){
                max_size = curSize;
                heavyList[root] = cur->vertex - 1;  //heavyList stores the child w the largest subtree, ie the heaviest child of every node ie the child with the most TOTAL num of nodes under it
            }
        }
        cur = cur->next;
    }

    return s;   //this function returns the TOTAL number of nodes under it, ie its subtree size
}

void decompose_tree(int root, int h, ListNode **adjList){
    
    ListNode *cur;

    headList[root] = h; //the current node is the start of a new head
    positionList[root] = cur_pos++; //?????

    if (heavyList[root] != -1){ //if current node has a heavy child, decompose the heavy child, but the heavy child should still belong in the same chain as me, so the head is still h
        decompose_tree(heavyList[root], h, adjList);
    }

    cur = adjList[root];

    while (cur != NULL){    //decompose each of the light child of current node, each light child should be a new head of node
        if ((((cur->vertex) - 1) != parList[root]) && (((cur->vertex)-1) != heavyList[root])){  //ignore if neighbour node is parent or if it is the heavy child
            decompose_tree((cur->vertex)-1, (cur->vertex) - 1, adjList);
        }
        cur = cur->next;
    }    
}



void precalc (ListNode **adjList, int N){
    int i;
    parList = malloc(N*sizeof(int));
    dList = malloc(N*sizeof(int));
    heavyList = malloc(N*sizeof(int));
    headList = malloc(N*sizeof(int));
    positionList = malloc(N*sizeof(int));
    poplistg = malloc(N*sizeof(int));

    for (i = 0; i < N; i++){
        parList[i] = 0;
        dList[i] = 0;
        heavyList[i] = -1;
        headList[i] = 0;
        positionList[i] = 0;
        poplistg[i] = 0;
        //printf("print ");
    }

    

    cur_pos = 0;

    dfs_search(0, adjList);
    decompose_tree(0,0, adjList);


    /*for (i = 0; i < N; i++){
        //printf("%d ", positionList[i]);
        //printf("\n");
        printf("%d ", parList[i]);
    }*/

}

int segTre(int c, int d){   //this is querying segment tree, poplist IS the segment tree
    int count = 0, val, temp;

    //printf("\n %d %d ",c, parList[c]);
    //printf("\n %d %d ",d, parList[d]);

    if (d>c){
        temp = c;
        c = d;
        d = temp;
    }


    while (c != d) {
        //printf("%d %d \n", head, point);
        if (poplistg[c] <= max_g){
            count++;
        }

        c--;
        //printf("\npopulation : %d", poplistg[c]);



        //head = positionList[parList[head]];
    }

    if (poplistg[c] <= max_g){
        count++;
    }

    /*if (flag == 1){
        if (poplistg[c] <= max_g){
            count++;
        }
    }*/

    /*if (poplistg[c] <= max_g){
        count++;
    }*/

    /*while (point != head){
        if (poplistg[c] <= max_g){
            count++;
        }
        c = parList[c];
        head = positionList[c];
        printf("%d %d", head, point);
    }*/

    /*while (point != head){
        if (poplistg[] <= max_g){
            count++;
        }
        d = parList[d];
        point = positionList[d];
        printf("%d %d", he
    }*/

    /*while (a != b){

       // b = positionList[parList]
    }*/

    //printf("\ncount : %d ", count);

    return count;
}



int findVal (int begin, int end){
    int result = 0, temp;

    for (;headList[begin -1] != headList[end - 1]; end = parList[headList[end - 1]]+1){ //while begin and end are not in the same chain, traverse the end node up its parent
        if (dList[headList[begin - 1]] > dList[headList[end - 1]]){
            temp = begin;   //swap begin and end so that the begin is always in the chain that has less depth ie the end is in the deeper chain
            begin = end;
            end = temp;
        }
        int cur_count = segTre(positionList[headList[end - 1]], positionList[end - 1]);
        result = result + cur_count;

    }

    if (dList[begin-1] > dList[end-1]){
        temp = begin;
        begin = end;
        end = temp;
    }

    int last_sum = segTre(positionList[begin - 1], positionList[end - 1]);
    result = result + last_sum;

    return result;
}

int* city_population (int N, int* population, int** road, int Q, int** cities) 
{
    int i, parent, child;

    ListNode *cur, *cur2, *temp;

    int *resArr = malloc(sizeof(int)*Q);

    for (i = 0; i < Q; i++){
        resArr[i] = 0;
    }

    ListNode **adjList;
    adjList = malloc(N*sizeof(ListNode));
    for (i = 0; i < N; i++){
        adjList[i] = NULL;
    }

    for (i = 0; i < N - 1; i++){
        parent = road[i][0];
        child = road[i][1];
        cur = malloc(sizeof(ListNode));
        cur->vertex = child;
        cur->next = adjList[parent - 1];
        adjList[parent - 1] = cur;

        cur2 = malloc(sizeof(ListNode));
        cur2->vertex = parent;
        cur2->next = adjList[child - 1];
        adjList[child - 1] = cur2;
    }

    precalc(adjList, N);

    for (i = 0; i < N; i++){
        poplistg[positionList[i]] = population[i];  
    }
    
    /*for (i = 0; i < N; i++){
        printf("%d ", poplistg[i]);  
    }*/

    int begin, end, max;
    for (i = 0; i < Q; i++){
        begin = cities[i][0];
        end = cities[i][1];
        max_g = cities[i][2];

        resArr[i] = findVal(begin, end);

    }

    return resArr;

    /*for(i=0;i<N;i++)
    {
        printf("%d:\t",i+1);
        temp = adjList[i];
        while(temp!=NULL){
            printf("%d -> ",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }*/
}