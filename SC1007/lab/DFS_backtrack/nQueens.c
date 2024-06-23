#include <stdio.h>
#include <stdlib.h>

int nQueens(int** board, int N, int col);
int nQueens_count(int** board, int BSize, int col);
int isSafe(int** board,int N, int row, int col);
void printSolution(int** board, int N);

int main()
{
    int **board;
    int BSize;

    int i,j;

    printf("Enter the size of chessBoard:\n");
    scanf("%d",&BSize);

    board = (int **)malloc(BSize*sizeof(int *));
    for(i=0;i<BSize;i++)
        board[i] = (int *)malloc(BSize*sizeof(int));

    for(i=0;i<BSize;i++)
       for(j=0;j<BSize;j++)
           board[i][j] = 0;
    int result=nQueens_count(board, BSize, 0);
    if(result) {
        printf("yes\n");
        printf("no. of solutions: %d\n",result);
    }
    else printf("no\n");
    printSolution(board,BSize);
    for(i=0;i<BSize;i++)
        free(board[i]);
    free(board);
    

    return 0;
}

int nQueens(int** board, int BSize, int col)
{
 //Write your code here
 //Safe Place checking is provide below, you are free to use it.
    if(!board) return 0;
    if(BSize<2) return 0;
    

    //in this scenario the base case ie the stopping case is actually the end when we have found our target
    if(col<0||col>BSize-1) {
        return 1;
    }

    int solution =0; //this can also be inside the for loop it makes no difference since once this var becomes 1 it will return in the same iteration, else it will just stay at 0 which is what we want anyways
    for(int i=0;i<BSize;i++){   //because of how the isSafe function is defined, cannot put queen first then check
       
        if(isSafe(board,BSize,i,col)){  //this is basically checking if a path exists, ie if theres a connection, but even if there is connection it doesnt mean taking that path is correct
             board[i][col]=1;
            solution= nQueens(board,BSize,col+1);
        }
        //this block can be placed inside or outside the if block its the same
        if(solution) return solution;   //once A solution is found just return, no need waste time finding other possible solutions
        else board[i][col]=0;       //else backtrack
    }
    return 0;
}

int nQueens_count(int** board, int BSize, int col)
{
 //Write your code here
 //Safe Place checking is provide below, you are free to use it.
    if(!board) return 0;
    if(BSize<2) return 0;
    

    //in this scenario the base case ie the stopping case is actually the end when we have found our target
    if(col<0||col>BSize-1) {
        return 1;
    }

    int solution =0; //this cannot be inside for loop since this is acting as the accumulator
    for(int i=0;i<BSize;i++){ 
       int found=0;
        if(isSafe(board,BSize,i,col)){  
             board[i][col]=1;
            printf("path found at col %d slot %d\n",col,i);
            printSolution(board,BSize);
            found= nQueens_count(board,BSize,col+1);
        }
        //this block can be placed inside or outside the if block its the same
        if(found) {
            solution+=found;  
            if(col==BSize-1){
                printf("success! one possible solution is:\n");
                printSolution(board,BSize);
            }
            

        } 
        //needs to backtrack no matter what,so that it can continue to explore other solutions
        // this if block does not do anything functional, purely for printing purposes, 
        //if its 1 change it to 0, if 0 dont do anything, so in the end it will always be 0 after this block
        if(board[i][col]==1){ 
            board[i][col]=0;  
            printf("removing at col %d slot %d\n",col,i);
            printSolution(board,BSize);
        }
        else{
            printf("no path at col %d slot %d\n",col,i);
            printSolution(board,BSize);
        }
            
    }
    return solution;
}


//Safe checking
int isSafe(int** board,int BSize, int row, int col)
{
    int i, j;

    // Horicatal check
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    // Upper left diagonal check
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Lower left diagonal check
    for (i = row, j = col; j >= 0 && i < BSize; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

void printSolution(int** board, int BSize)
{
    int i,j;
    for (i = 0; i < BSize; i++) {
        for (j = 0; j < BSize; j++){
            if(board[i][j]==1)
                printf(" Q ");
            else
                printf(" + ");
        }
        printf("\n");
    }
    printf("\n");
}
