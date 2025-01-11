/* Implementing Binary Search Tree and its operation */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *right, *left;
} Node;

Node *createNode(int val)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    new_node->right = NULL;
    new_node->left = NULL;
    new_node->val = val;

    return new_node;
}

Node *insertNode(Node *root, int val)
{
    if (root == NULL)
    {
        return createNode(val);
    }

    if (root->val == val)
    {
        return root;
    }

    if (root->val < val)
        root->right = insertNode(root->right, val);
    else
        root->left = insertNode(root->left, val);

    return root;
}

void inOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    printf("%d ", root->val);
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->val);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->val);
}

Node *getSuccessor(Node *root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return root;

    if (root->val < key)
        root->right = deleteNode(root->right, key);
    else if (root->val > key)
        root->left = deleteNode(root->left, key);
    else
    {
        // if leaf node or it has one right child
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }

        // if it has only left child
        if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // if it has two childs
        Node *succ = getSuccessor(root->right);
        root->val = succ->val;
        root->right = deleteNode(root->right, succ->val);
    }

    return root;
}

int main()
{
    Node *root = NULL;
    root = insertNode(root, 20);
    root = insertNode(root, 25);
    root = insertNode(root, 15);
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 30);
    root = insertNode(root, 22);
    root = insertNode(root, 35);

    printf("InOrder: ");
    inOrderTraversal(root);
    printf("\n");

    printf("PreOrder: ");
    preOrderTraversal(root);
    printf("\n");

    printf("PostOrder: ");
    postOrderTraversal(root);
    printf("\n");

    // delete leaf node
    root = deleteNode(root, 5);
    printf("Deleted 5!\n");
    inOrderTraversal(root);
    printf("\n");

    // delete node having one child
    root = deleteNode(root, 30);
    printf("Deleted 30!\n");
    inOrderTraversal(root);
    printf("\n");

    // delete node having two child
    root = deleteNode(root, 20);
    printf("Deleted 20!\n");
    inOrderTraversal(root);
    printf("\n");
    return 0;
}