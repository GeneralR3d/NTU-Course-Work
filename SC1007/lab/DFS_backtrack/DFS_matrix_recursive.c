#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
    int vertex;
	struct _listnode *next;
} ListNode;

typedef struct _graph{
    int V;
    int E;
    int *visited;
    int **matrix;
}Graph_DFS;

////GRAPH////////////////////////////////////////////
void printGraphMatrix(Graph_DFS );
////////////////////////////////////////////

void DFS_R (Graph_DFS , int );

int main()
{
    Graph_DFS g;
    int i,j;

    printf("Enter the number of vertices:\n");
    scanf("%d",&g.V);

    g.E = 0;
    g.matrix = (int **)malloc(g.V*sizeof(int *));
    for(i=0;i<g.V;i++)
        g.matrix[i] = (int *)malloc(g.V*sizeof(int));

    for(i=0;i<g.V;i++)
       for(j=0;j<g.V;j++)
           g.matrix[i][j] = 0;

    g.visited = (int *) malloc(sizeof(int)*g.V);
    for(i=0;i<g.V;i++) g.visited[i] = 0;

    int V1, V2;
    printf("Enter two vertices which are adjacent to each other:\n");
    while(scanf("%d %d",&V1,&V2)==2)
    {
        if(V1>0 && V1<=g.V && V2>0 && V2<=g.V)
        {
            g.matrix[V1-1][V2-1] = 1;
            g.matrix[V2-1][V1-1] = 1;
            g.E++;
        }
        else
            break;
        printf("Enter two vertices which are adjacent to each other:\n");
    }
    scanf("%*c");
    printf("Enter a start vertex for DFS:\n");
    scanf("%d", &i);
    printGraphMatrix(g);
    DFS_R(g,i);

    return 0;
}

//for recursive DFS u either need a global visted array, or pass the array as a parameter into every recusive call, or just embed the visted array into the graph struct/object
void DFS_R (Graph_DFS g, int v)
{
//Write your code here
if(g.V<1) return; //empty graph
g.visited[v-1]=1; //set starting point as visited

//goal test would be done here, after setting current node as visited, if current node is the goal, then dont need to further search its neighbours

//for every neighbour if that neighbour is unvisted, call DFS on it
for(int i=0;i<g.V;i++){
        if(g.matrix[v-1][i]==1 && g.visited[i]==0){
            DFS_R(g,i+1);
        }
}
//after visiting every neighbour ie fully explored, print it
printf("%d ",v);

}

void printGraphMatrix(Graph_DFS g)
{
    int i,j;

    for(i=0;i<g.V;i++){
        for(j=0;j<g.V;j++)
            printf("%d\t",g.matrix[i][j]);
        printf("\n");
    }

}
