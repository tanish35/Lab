#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createNode(int data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
TreeNode *insertNode(TreeNode *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Iterative insertion
TreeNode *insertNodeIterative(TreeNode *root, int data)
{
    TreeNode *newNode = createNode(data);
    TreeNode *parent = NULL;
    TreeNode *current = root;
    while (current != NULL)
    {
        parent = current;
        if (data < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    if (parent == NULL)
    {
        return newNode;
    }
    if (data < parent->data)
    {
        parent->left = newNode;
    }
    else
    {
        parent->right = newNode;
    }
    return root;
}

void inorderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

TreeNode *inorderSuccessor(TreeNode *root, int data, TreeNode **succ)
{
    if (root == NULL)
    {
        return root;
    }
    if (data >= root->data)
    {
        return inorderSuccessor(root->right, data, succ);
    }
    else if (data < root->data)
    {
        *(succ) = root;
        return inorderSuccessor(root->left, data, succ);
    }
    return root;
}

TreeNode *inorderPredecessor(TreeNode *root, int data, TreeNode **pred)
{
    if (root == NULL)
    {
        return root;
    }
    if (data <= root->data)
    {
        return inorderPredecessor(root->left, data, pred);
    }
    else if (data > root->data)
    {
        *(pred) = root;
        return inorderPredecessor(root->right, data, pred);
    }
    return root;
}

TreeNode *searchNode(TreeNode *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    if (data < root->data)
    {
        return searchNode(root->left, data);
    }
    return searchNode(root->right, data);
}

TreeNode *inorderSuccessor(TreeNode *root, int data, TreeNode **succ)
{
    if (root == NULL)
    {
        return root;
    }
    if (data >= root->data)
    {
        return inorderSuccessor(root->right, data, succ);
    }
    else if (data < root->data)
    {
        *(succ) = root;
        return inorderSuccessor(root->left, data, succ);
    }
    return root;
}

void successor(TreeNode *n, TreeNode **parent, TreeNode **successor)
{
    *parent = n;
    *successor = n->right;
    while ((*successor)->left != NULL)
    {
        *parent = *successor;
        *successor = (*successor)->left;
    }
}

TreeNode *deleteNode(TreeNode *root, TreeNode *n, TreeNode *parent)
{
    TreeNode *succ, *retVal;
}

int main()
{
    TreeNode *root = NULL;
    root = insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 8);
    insertNode(root, 9);
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 4);
    insertNode(root, 6);

    printf("In-order traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    TreeNode *succ = NULL;
    inorderSuccessor(root, 5, &succ);
    printf("Inorder successor of 5 is %d\n", succ->data);
    TreeNode *pred = NULL;
    inorderPredecessor(root, 5, &succ);
    printf("Inorder predecessor of 5 is %d\n", succ->data);

    return 0;
}