// Binary Search Tree
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *node, int data)
{
    if (node == NULL)
    {
        return create(data);
    }
    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insert(node->right, data);
    }
    else
    {
        printf("Value is repeating.");
    }
    return node;
}

void inorder(struct node *node)
{
    if (node == NULL)
    {
        return;
    }
    inorder(node->left);
    printf("%d\t", node->data);
    inorder(node->right);
}

void postorder(struct node *node)
{
    if (node == NULL)
    {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    printf("%d\t", node->data);
}

void preorder(struct node *node)
{
    if (node == NULL)
    {
        return;
    }
    printf("%d\t", node->data);
    preorder(node->left);
    preorder(node->right);
}

struct node *deleteNode(struct node *node, int data)
{
    if (node == NULL)
    {
        return node;
    }
    if (data < node->data)
    {
        node->left = deleteNode(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = deleteNode(node->right, data);
    }
    // data == node->data; value is founded
    else
    {
        // case1: node has no child

        // case2: node has right child
        if (node->left == NULL)
        {
            struct node *temp = node->right;
            free(node);
            return temp;
        }

        // case3: node has left child
        else if (node->right == NULL)
        {
            struct node *temp = node->left;
            free(node);
            return temp;
        }

        // case4: node has left and right node
        else
        {
            struct node *temp = node->right;
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
    }
    return node;
}

void mirror(struct node *node)
{
    struct node *temp = node->right;
    node->right = NULL;
    node->right = node->left;
    free(temp);
}

struct node *swap(struct node *node)
{
    struct node *temp = node->right;
    node->right = swap(node->left);
    node->left = swap(temp);
    return node;
}

void main(void)
{
    struct node *root = NULL;

    root = insert(root, 7);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 20);

    // printf("\nBefore mirror:");

    printf("\nInorder:\t");
    inorder(root);

    // printf("\nPostorder:\t");
    // postorder(root);

    // printf("\nPreorder:\t");
    // preorder(root);

    // mirror(root);

    // printf("\n\nAfter mirror:");

    // printf("\nInorder:\t");
    // inorder(root);

    // printf("\nPostorder:\t");
    // postorder(root);

    // printf("\nPreorder:\t");
    // preorder(root);

    root = deleteNode(root, 6);
    root = deleteNode(root, 7);
    printf("\nInorder:\t");
    inorder(root);

    root = insert(root, 80);
    root = insert(root, 9);
    root = insert(root, 200);
    printf("\nInorder:\t");
    inorder(root);

    return;
}