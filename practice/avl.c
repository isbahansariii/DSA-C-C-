// AVL
// Preorder traversal of the AVL tree

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalance(struct Node *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct Node *newNode(int key) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

struct Node *insert(struct Node *node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicate keys not allowed

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

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

struct Node *deleteNode(struct Node *node, int data)
{
    if (node == NULL)
    {
        return node;
    }
    if (data < node->key)
    {
        node->left = deleteNode(node->left, data);
    }
    else if (data > node->key)
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
            struct Node *temp = node->right;
            free(node);
            return temp;
        }

        // case3: node has left child
        else if (node->right == NULL)
        {
            struct Node *temp = node->left;
            free(node);
            return temp;
        }

        // case4: node has left and right node
        else
        {
            struct Node *temp = node->right;
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }
    }
    return node;
}


void preOrder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct Node *root = NULL;

    root = insert(root, 23);
    root = insert(root, 75);
    root = insert(root, 87);
    root = insert(root, 111);
    root = insert(root, 175);
    int h = height(root);
    printf("Height of tree: %d", h);

    printf("\nPreorder traversal of the AVL tree:\n");
    preOrder(root);

    root = deleteNode(root, 75);
    printf("\nPreorder traversal of the AVL tree:\n");
    preOrder(root);

    return 0;
}