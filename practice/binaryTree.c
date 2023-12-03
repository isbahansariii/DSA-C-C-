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

struct node * create(){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    int data;
    printf("Enter a value to insert in tree OR press -1 to exit: ");
    scanf("%d", &data);

    if (data == -1){
        return 0;
    }

    newnode->data = data;

    printf("\nFor Left child of %d, ", newnode->data);
    newnode->left = create();

    printf("\nFor right child of %d, ", newnode->data);
    newnode->right = create();

    return newnode;
}

void main(){
    root = create();
}