// AVL (Adelson-Velsky and Landis) Tree
// Preorder traversal of the AVL tree

#include <stdio.h>  // Include the standard input/output library for I/O operations
#include <stdlib.h>  // Include the standard library for memory allocation functions

// Define a structure for a node in the AVL tree
struct Node {
    int key;  // Store the key value
    struct Node *left;  // Pointer to the left child
    struct Node *right;  // Pointer to the right child
    int height;  // Height of the node in the tree
};

// Function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to get the height of a node (NULL nodes have height 0)
int height(struct Node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to get the balance factor of a node (difference in heights of left and right subtrees)
int getBalance(struct Node *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to create a new node with a given key
struct Node *newNode(int key) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));  // Allocate memory for a new node
    node->key = key;  // Set the key
    node->left = NULL;  // Initialize left and right children to NULL
    node->right = NULL;
    node->height = 1;  // Initialize the height to 1 (leaf node)
    return node;
}

// Function to perform a right rotation on a node (used for balancing the tree)
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Function to perform a left rotation on a node (used for balancing the tree)
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Function to insert a new node with a key into the AVL tree
struct Node *insert(struct Node *node, int key) {
    if (node == NULL)
        return newNode(key);  // If the node is NULL, create a new node with the key

    if (key < node->key)
        node->left = insert(node->left, key);  // Recursively insert into the left subtree
    else if (key > node->key)
        node->right = insert(node->right, key);  // Recursively insert into the right subtree
    else
        return node; // Duplicate keys are not allowed

    node->height = 1 + max(height(node->left), height(node->right));  // Update the height of the current node

    int balance = getBalance(node);  // Get the balance factor of the node

    // Left Heavy
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Heavy
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to perform a preorder traversal of the AVL tree and print the keys
void preOrder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Preorder traversal of the AVL tree:\n");
    preOrder(root);  // Perform a preorder traversal and print the keys

    return 0;  // Return 0 to indicate successful program execution
}
