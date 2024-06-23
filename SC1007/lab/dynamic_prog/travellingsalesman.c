#include <stdio.h>
#include <stdlib.h>
#define MIN(a,b) ((a)<(b)?a:b)
int travellingSalesman(int** cost,int start);

void main ()
{
    int**cost=(int**)malloc(sizeof(int*)*4);
    for(int i=0;i<4;i++) cost[i]=(int*)malloc(sizeof(int)*4);
    cost[0][0]=0;
    cost[0][1]=10;
    cost[0][2]=15;
    cost[0][3]=20;
    cost[1][0]=5;
    cost[1][1]=0;
    cost[1][2]=9;
    cost[1][3]=10;
    cost[2][0]=6;
    cost[2][1]=13;
    cost[2][2]=0;
    cost[2][3]=12;
    cost[3][0]=8;
    cost[3][1]=8;
    cost[3][2]=9;
    cost[3][3]=0;

    printf("The least cost of hamilton circuit is %d",travellingSalesman(cost,1));
}

int travellingSalesman(int** cost,int start){

}