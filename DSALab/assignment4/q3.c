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

void inorderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

TreeNode *findInorderSuccessor(TreeNode *root)
{
    TreeNode *current = root;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

TreeNode *deleteNode(TreeNode *root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL)
        {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        TreeNode *successor = findInorderSuccessor(root->right);
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }
    return root;
}

TreeNode *findInorderSuccessorWithTracking(TreeNode *root, int data, TreeNode **succ)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (data < root->data)
    {
        *succ = root;
        return findInorderSuccessorWithTracking(root->left, data, succ);
    }
    else if (data > root->data)
    {
        return findInorderSuccessorWithTracking(root->right, data, succ);
    }
    return root;
}

TreeNode *findInorderPredecessorWithTracking(TreeNode *root, int data, TreeNode **pred)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (data > root->data)
    {
        *pred = root;
        return findInorderPredecessorWithTracking(root->right, data, pred);
    }
    else if (data < root->data)
    {
        return findInorderPredecessorWithTracking(root->left, data, pred);
    }
    return root;
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
    findInorderSuccessorWithTracking(root, 5, &succ);
    if (succ != NULL)
    {
        printf("Inorder successor of 5 is %d\n", succ->data);
    }
    else
    {
        printf("No inorder successor for 5\n");
    }

    TreeNode *pred = NULL;
    findInorderPredecessorWithTracking(root, 5, &pred);
    if (pred != NULL)
    {
        printf("Inorder predecessor of 5 is %d\n", pred->data);
    }
    else
    {
        printf("No inorder predecessor for 5\n");
    }

    root = deleteNode(root, 5);

    printf("In-order traversal after deleting 5: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
