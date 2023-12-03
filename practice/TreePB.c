// Binary Tree
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
struct node *T2root = NULL;


struct node * create(struct node *node){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    int data;
    printf("Enter a value to insert in tree OR press -1 to exit: ");
    scanf("%d", &data);

    if (data == -1){
        return 0;
    }

    newnode->data = data;

    printf("For Left child of %d, ", newnode->data);
    newnode->left = create(newnode->left);

    printf("For right child of %d, ", newnode->data);
    newnode->right = create(newnode->right);

    return newnode;
}

void preorder(struct node *node)
{
    if (node != NULL)
    {
        printf("\t%d", node->data);
    	preorder(node->left);
    	preorder(node->right);
    }   
}

int equality(struct node *node, struct node*node2){
	if(node == NULL && node2 == NULL){
		return 1;
	}
	
	if(node != NULL && node2 != NULL){
		int match = node->data==node2->data;  //if equal, match store 1, otherwise 0
		int subLeftTree = equality(node->left, node2->left);
		int subRightTree = equality(node->right, node2->right);
		return (match && subLeftTree && subRightTree);
	}
	else{
		return 0; //one tree is empty
	}	
}

int stucture(struct node *node, struct node*node2){
	if(node == NULL && node2 == NULL){
		return 1;
	}
	
	if(node != NULL && node2 != NULL){
//		checking no of left subtrees and no of right subTrees
		int subLeftTree = stucture(node->left, node2->left);
		int subRightTree = stucture(node->right, node2->right);
		return (subLeftTree && subRightTree);
	}
	else{
		return 0; //one tree is empty
	}	
}

int mirror(struct node *node, struct node*node2){
	if(node == NULL && node2 == NULL){
		return 1;
	}
	
	if(node != NULL && node2 != NULL){
		int match = node->data==node2->data;  //if equal, match store 1, otherwise 0
		int subLeftTree = mirror(node->left, node2->right);
		int subRightTree = mirror(node->right, node2->left);
		return (match && subLeftTree && subRightTree);
	}
	else{
		return 0; //one tree is empty
	}	
}

int main(void){
    
	printf("Tree#01:\n");
	root = create(root);
	printf("\nTree#01:\n");
	T2root = create(T2root);
	
	printf("\nTree#01:");
	preorder(root);
    printf("\nTree#02:");
	preorder(T2root);
	
	int result = equality(root, T2root);
	if(result){
		printf("\nTree#1 and Tree#02 are equal.");
	}
	else{
		printf("\nTree#1 and Tree#02 are not equal.");
	}
	
	int sameStucture = stucture(root, T2root);
	if(sameStucture){
		printf("\nTree#1 and Tree#02 have same stucture.");
	}
	else{
		printf("\nTree#1 and Tree#02 have not same stucture.");
	}
	
	int Mirror = mirror(root, T2root);
	if(Mirror){
		printf("\nTree#1 and Tree#02 are mirror.");
	}
	else{
		printf("\nTree#1 and Tree#02 are not mirror.");
	}
	
	return 0;
}
