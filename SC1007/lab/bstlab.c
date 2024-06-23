//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////

typedef struct _btnode{
int item;
struct _btnode *left;
struct _btnode *right;
} BTNode;

///////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value);
void printBSTInOrder(BTNode *node);
int isBST(BTNode *node, int min, int max);
BTNode *removeBSTNode(BTNode *node, int value);
BTNode *findInOrderSuccessor(BTNode *p);

///////////////////////////////////////////////////////////////////////

int main(){
	int i=0;

	BTNode *root=NULL;

	//question 1
	do{
		printf("input a value you want to insert(-1 to quit):\n");

		scanf("%d",&i);
		if (i!=-1)
			insertBSTNode(&root,i);
	}while(i!=-1);

	//question 2
	printf("the tree is:\n");
	printBSTInOrder(root);
	printf("\n");

	//question 3
	if ( isBST(root,-1000000, 1000000)==1)
		printf("It is a BST!\n");
	else
		printf("It is not a BST!\n");

	//question 4
	do{
		printf("\ninput a value you want to remove(-1 to quit):");
		scanf("%d",&i);
		if (i!=-1)
		{
			root=removeBSTNode(root,i);
			printBSTInOrder(root);
		}
	}while(i!=-1);


	return 0;
}

//////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value)
{
	// write your code here
	//general idea: if root is empty malloc space for the node
	//else if the number you are trying to insert is smaller, call this same function on your left child
	//else if the number you are trying to insert is bigger, call this same function on your right child
	//else if the number you are trying to insert is same as current node, then quit since by defnition a BST should not have any duplicates
	if(!*node || !node){
        BTNode* tmp=malloc(sizeof(BTNode));
        tmp->item=value;
        tmp->left=NULL;
        tmp->right=NULL;
        *node=tmp;
        return;
	}
	if(value<((*node)->item)) {insertBSTNode((&(*node)->left),value);}
	else if (value>((*node)->item)) {insertBSTNode((&(*node)->right),value);}
	else printf("Node alr exists\n");
}

//////////////////////////////////////////////////////////////////////

void printBSTInOrder(BTNode *node)
{
	// write your code here
	//just a simple printing in order
	if(!node)return;
	printBSTInOrder(node->left);
	printf("%d ",node->item);
	printBSTInOrder(node->right);


}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int isBST(BTNode *node, int min, int max) // the item stored in node has to be smaller than max and larger than min
{
	// write your code here
	//general idea: info flows upwards, from children to parent
	//base case, if encounter a null node return true, which is 1, since a tree with null is a BST
	//else check if left child is a BST, and check if rigt child is a BST, then check if current node is within range, ie bigger than min and smaller than max
	//adjust parameters for left child, left child max must be current
	//adjust parameters for right child, right child min must be current
	//since function is called recursively on left and right subtrees, the max and min parameters do not stay at 10000000 and -1000000,
	//it follows the values in the parents
	//thus this ensures that for left, all grandchildren, not just children has to be smaller, vice versa for right, bigger
	//thus it ensures the rules of BST is obeyed for every node
	if(!node) return 1;
	//if(node->item>max||node->item<min) return 0;
	return isBST(node->left,min,node->item) && isBST(node->right,node->item,max) && node->item<max && node->item>min;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//this function returns the root node instead of using double pointer
BTNode *removeBSTNode(BTNode *node, int value)
{
	// write your code here
	//instead of using double pointer, this function returns the root node of the edited tree
	//so if its NULL, return NULL
	//if target is smaller, remove from left subtree and replace left subtree with the edited version of the left subtree
	//if target is larger, remove from right subtree and replace right subtree with the edited version of the right subtree
	//if target == current means this is the node we want to remove, here got 4 cases
	if(!node) return NULL;
	if(value < node->item) node->left= removeBSTNode(node->left,value);
	else if(value > node->item) node->right= removeBSTNode(node->right,value);
	else if (node->left && node->right){
		//the node has 2 children
        //finding the inorder successor, can also find predecessor
		//successor is definitely located on the right subtree since its bigger than current
		//once found, copy the successor value over to current node,
		//now we have effectively "removed" the current node, but now the tree has 2 succesor
		//so we remove the successor that is inside the right subtree we found it from
		//if the successor also has 2 child, just keep doing recursively
        BTNode* p=findInOrderSuccessor(node->right);
        node->item=p->item;
        node->right=removeBSTNode(node->right,p->item);



	}
	else{//no children or 1 children, since one function call of removeBSTNode on its left and right children returned NULL
        //3 cases here, either it has only left child, which means its left child can replace it
        //or it only has right child, which means its right child can replace it
        //or it has no child, which means just free it
        BTNode* tmp=node;
        if(!node->right){
		node=node->left;
		free(tmp);
		}
        else if (!node->left){
			node=node->right;
			free(tmp);
		}
		else{
        free(tmp);
		}

}
return node;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode * findInOrderSuccessor(BTNode *p)
{
	// write your code here
	if(p->left)
        return findInOrderSuccessor(p->left);
    else
        return p;

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
