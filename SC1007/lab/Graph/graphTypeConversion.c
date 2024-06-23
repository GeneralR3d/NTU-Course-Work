#include <stdio.h>
#include <stdlib.h>

enum GraphType {ADJ_MATRIX, ADJ_LIST}; // Types of Graph Representation

typedef struct _listnode
{
    int vertex;
	struct _listnode *next;
} ListNode;

union GraphForm{
    int **matrix;
    ListNode **list;
};

typedef struct _graph{
    int V;
    int E;
    enum GraphType type;
    union GraphForm adj;
}Graph;

void printGraphMatrix(Graph );
void adjM2adjL(Graph *);
void adjL2adjM(Graph *);
void printGraphList(Graph );
void calDegreeV(Graph,int *);
void printDegreeV(int *,int );

int main()
{
    Graph g;
    int i,j;

    int* degreeV;

    printf("Enter the number of vertices:\n");
    scanf("%d",&g.V);

    g.E = 0;
    g.adj.matrix = (int **)malloc(g.V*sizeof(int *));
    for(i=0;i<g.V;i++)
        g.adj.matrix[i] = (int *)malloc(g.V*sizeof(int));

    for(i=0;i<g.V;i++)
        for(j=0;j<g.V;j++)
            g.adj.matrix[i][j] = 0;
    g.type = ADJ_MATRIX;

    degreeV = (int *) malloc(g.V*sizeof(int));
    for(i=0;i<g.V;i++)
        degreeV[i]=0;

    int V1, V2;
    printf("Enter two vertices which are adjacent to each other:\n");
    while(scanf("%d %d",&V1,&V2)==2)
    {
        //in this case its an undirected graph
        if(V1>0 && V1<=g.V && V2>0 && V2<=g.V)
        {
            g.adj.matrix[V1-1][V2-1] = 1;
            g.adj.matrix[V2-1][V1-1] = 1;
            g.E++;
        }
        else
            break;
        printf("Enter two vertices which are adjacent to each other:\n");
    }

    calDegreeV(g,degreeV);

    printGraphMatrix(g);
    printDegreeV(degreeV,g.V);

    adjM2adjL(&g);

    calDegreeV(g,degreeV);

    printGraphList(g);
    printDegreeV(degreeV,g.V);

    adjL2adjM(&g);
    printGraphMatrix(g);

    free(degreeV);
    for(i=0;i<g.V;i++) free(g.adj.matrix[i]);
    free(g.adj.matrix);
    

    return 0;
}

void printGraphMatrix(Graph g)
{
    int i,j;
    if(g.type == ADJ_LIST) {printf("Error"); return;}

    printf("Printing the matrix:\n");
    for(i=0;i<g.V;i++){
        for(j=0;j<g.V;j++)
            printf("%d\t",g.adj.matrix[i][j]);
        printf("\n");
    }

}

void printDegreeV(int *degreeV,int V)
{
    int i;
    for(i=0;i<V;i++)
        printf("%d: %d degree\n",i+1,degreeV[i]);
}

void printGraphList(Graph g){
    int i;
    ListNode* temp;

    if(g.type == ADJ_MATRIX) {printf("Error"); return;}

    printf("Printing the list:\n");
    for(i=0;i<g.V;i++)
    {
        printf("%d:\t",i+1);
        temp = g.adj.list[i];
        while(temp!=NULL){
            printf("%d -> ",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

/*
QUESTIONS
1)WHY when passing graph object by value without pointers, it is still able the change the orignal graph in main()?? Does it not create a local copy of the graph in the other function??
2)Why when creating list or matrix, have to use tmp list/mat variable to hold everything, only assigning it to the actual graph object at the very end?
-why cannot just use the struct elements in the graph directly for this
-why will using the graph elements directly lead to seg fault
*/

/*
 LESSONS LEARNT
 1)when creating 2d array, the first malloc to create the initial array, must rmb to allocate space for array of POINTERS NOT ACTUAL types
 2)for adj matrix must initialize all values to 0, for adj list must initialize to NULL
 3)not neccessary to insert nodes at the rear of LL by using rear pointer, can also just insert in front
 4)rmb to initialize variables, espc for counters, to 0 before starting to add to prevent garbage values
 5)there is no difference in calling the vertices starting from 1 or 0, ie calling vertex numbers in adj list from 1-7 instead of 0-6
 */

void adjM2adjL(Graph *g)
{
 // Question 1
 // Write your code here
 

 
 if(!g) return; //sanity check
 if(g->type==ADJ_LIST || g->adj.matrix==NULL)return; //if alr a list, return
 if(g->V <1) return; //if less than 1 node return

ListNode** list =(ListNode**)malloc(g->V * sizeof(ListNode*));

 //init with all NULL
 for(int i=0;i<g->V;i++){
    list[i]=NULL;
 }
 //translating each edge into the adjacency list
 for(int i=0;i<g->V;i++){
    for(int j=0;j<g->V;j++){
        if((g->adj.matrix)[i][j]==1){
            //creating a listnode and connecting it
            ListNode* tmp=(ListNode*)malloc(sizeof(ListNode));
            tmp->vertex=j;
            tmp->next=list[i];
            list[i]=tmp;
        }
    }
 }
 //deleting the matrix
 for(int i=0;i<g->V;i++){
    free(g->adj.matrix[i]);
 }
 free(g->adj.matrix);
 g->adj.matrix=NULL;
 //change the type
 g->type=ADJ_LIST;
g->adj.list=list;
 return;

}

void adjL2adjM(Graph *g){
	// Question 2
    // Write your code here
    if(!g) return; //sanity check
    if(g->type==ADJ_MATRIX || g->adj.list==NULL)return; //if alr a matrix, return
    if(g->V <1) return; //if less than 1 node return

    //creating matrix
    int** mat=(int**)malloc(g->V* sizeof(int*));
    for(int i=0;i<g->V;i++){
        mat[i]=(int*)malloc(g->V * sizeof(int));
    }

    //init w all 0s
    for(int i=0;i<g->V;i++){
        for(int j=0;j<g->V;j++){
            mat[i][j]=0;
        }
    }

    //translating each edge into matrix at the same time freeing the nodes in each LL
    for(int i=0;i<g->V;i++){
        ListNode* trav=g->adj.list[i];
        while(trav){
            mat[i][trav->vertex]=1;
            ListNode* tmp=trav;
            g->adj.list[i]=trav->next;
            trav=trav->next;
            free(tmp);
        }
    }
    //deleting the array
    free(g->adj.list);
    g->adj.list=NULL;
    //change the type
    g->type=ADJ_MATRIX;
    g->adj.matrix=mat;
    return;




}

void calDegreeV(Graph g, int *degreeV)
{
	// Question 3
    // Write your code here
    if(g.V<1)return;
    if(g.type==ADJ_LIST){
        
        if(!g.adj.list) return; //more sanity check
        for(int i=0;i<g.V;i++){
            int count=0;
            // while(g.adj.list[i]){
            //     count++;
            //     g.adj.list[i]=g.adj.list[i]->next;
            //     //destroying the list but its ok its declared on the stack and we are never using it again
            // }
            ListNode* tmp=g.adj.list[i];
            while(tmp){
                count++;
                tmp=tmp->next;
                //destroying the list but its ok its declared on the stack and we are never using it again
            }
            degreeV[i]=count;
        }

    }
    else{

        if(!g.adj.matrix) return; //more sanity check
        for(int i=0;i<g.V;i++){
            degreeV[i]=0; //init to zero before
            for(int j=0;j<g.V;j++){
                degreeV[i]= degreeV[i] + g.adj.matrix[i][j];
            }
        }

    }
}

