////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#define min(i, j) (((i) < (j)) ? (i) : (j))
#define max(i, j) (((i) > (j)) ? (i) : (j))

////////////////////////////////////////////////////////////////////


typedef struct _btnode{
	int item;
	struct _btnode *left;
	struct _btnode *right;

} BTNode;

////////////////////////////////////////////////////////////////////


void mirrorTree(BTNode *node);

void printSmallerValues(BTNode *node, int m);
int smallestValue(BTNode *node);
int hasGreatGrandchild(BTNode *node);

void printTree_InOrder(BTNode *node);

////////////////////////////////////////////////////////////////////

int main(int argc, const char * argv[]){

	int i;
	BTNode *root, *root2;
	BTNode btn[15];

	// Create the tree in Q1
	// Using manual dynamic allocation of memory for BTNodes

	root = malloc(sizeof(BTNode));
	root->item = 4;

	root->left = malloc(sizeof(BTNode));
	root->left->item = 5;

	root->right = malloc(sizeof(BTNode));
	root->right->item = 2;

	root->left->left = NULL;

	root->left->right = malloc(sizeof(BTNode));
	root->left->right->item = 6;

	root->left->right->left = NULL;
	root->left->right->right = NULL;

	root->right->left = malloc(sizeof(BTNode));
	root->right->left->item = 3;

	root->right->right = malloc(sizeof(BTNode));
	root->right->right->item = 1;

	root->right->left->left = NULL;

	root->right->left->right = NULL;

	root->right->right->left = NULL;

	root->right->right->right = NULL;

	printTree_InOrder(root);
	printf("\n");
	mirrorTree(root);
	printTree_InOrder(root);
	printf("\n\n");
	printf("expected %d",NULL<1000);//PRINTF prints NULL as 0

	//question 2
	printf("\n input m for question 2:");
	scanf("%d", &i);
	printf("the values smaller than %d are:", i);
	printSmallerValues(root, i);
	printf("\n\n");


	//question 3
	printf("The smallest value in the tree is %d:\n", smallestValue(root));

	//question 4
	// Create a tree for Q4: Tall enough so some nodes have great-grandchildren
	// Use array of BTNodes, create tree by linking nodes together
	for (i = 0; i <= 6; i++){
		btn[i].item = i;
		btn[i].left = &(btn[i * 2 + 1]);
		btn[i].right = &(btn[i * 2 + 2]);
	}

	for (i = 7; i <= 14; i++){
		btn[i].item = i;
		btn[i].left = NULL;
		btn[i].right = NULL;
	}
	root2 = &btn[0];

	printf("The tree for question 4 visited by in-order is \n");
	printTree_InOrder(root2);
	printf("\nthe values stored in all nodes of the tree that have at least one great-grandchild are: ");

	hasGreatGrandchild(root2);

	return 0;
}

void mirrorTree(BTNode *node){

	// write your code here
	if(!node)return;

	//actually dont need to check if left or right node is NULL or not
	//if one is null or both is null or both not NULL doesnt matter because we can just swap the null value regardless
	if(!node->left||!node->right)
        return;
    else if(!node->left)
    {
        node->left=node->right;
        node->right==NULL;
    }
    else if(!node->right)
    {
        node->right=node->left;
        node->left==NULL;
    }
    else
    {
        BTNode* tmp=node->left;
        node->left=node->right;
        node->right=tmp;

    }
    mirrorTree(node->left);
    mirrorTree(node->right);



}
//SUGGESTED SOL
//void mirrorTree(BTNode *node){

//if(!node) return;
//BTNode* temp=node->left;
//node->left=node->right;
//node->right=temp;
//mirrorTree(node->left);
//mirrorTree(node->right);



}

int hasGreatGrandchild(BTNode *node){

	// write your code here
	if(!node) return 0;
	int l=hasGreatGrandchild(node->left);
	int r=hasGreatGrandchild(node->right);

	int higher=max(l,r);
	if(higher>=3)
        printf("%d ",node->item);
    return higher+1;



}



void printSmallerValues(BTNode *node, int m){

	// write your code here
	if(!node)
        return;
    if((node->item)<m)
        printf("%d ",node->item);
    printSmallerValues(node->left,m);
    printSmallerValues(node->right,m);

}

int smallestValue(BTNode *node) {
	int l, r;

	//write your code here
	if(!node)return 100000;//in this case NULL CANNOT, 100000 serves as the arbitrary largest number to compare to, ideally use math.h and find the biggest number
	if(!node->left&&!node->right)
        return node->item;
    l= smallestValue(node->left);
    r=smallestValue(node->right);
    return min(l,min(r,node->item));


}

/////////////////////////////////////////////////////////////////
//sugested
// int smallestValue(BTNode *node) {
// 	int l, r;
// 	if(!node) return 10000000;
// 	l=smallestValue(node->left);
// 	r=smallestValue(node->right);
// 	if(l<node->item && l<r)
// 	{
// 	    //printf("smaller one %d",1);
// 	    return l;
// 	}
// 	else if(r<node->item && r<l)
//     {
//         //printf("smaller one %d",r);
//         return r;
//     }
//     else
//     {
//         //printf("smaller one %d",node->item);
//         return node->item;
//     }

// }
//////////////////////////////////////////////////////////////////

void printTree_InOrder(BTNode *node){

	if (node == NULL) return;
	printTree_InOrder(node->left);
	printf("%d, ", node->item);
	printTree_InOrder(node->right);
	return;
}
