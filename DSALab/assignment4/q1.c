#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createTree()
{
    int data;
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);
    if (data == -1)
    {
        return NULL;
    }
    newNode->data = data;
    printf("Enter left child of %d\n", data);
    newNode->left = createTree();
    printf("Enter right child of %d\n", data);
    newNode->right = createTree();
    return newNode;
}

void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    TreeNode *root = createTree();

    return 0;
}