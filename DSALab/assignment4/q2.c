#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

int preIndex = 0;

int search(int inorder[], int start, int end, int data)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == data)
        {
            return i;
        }
    }
    return -1;
}

TreeNode *createTree(TreeNode *root, int preorder[], int inorder[], int start, int end)
{

    if (start > end)
    {
        return NULL;
    }
    root = (TreeNode *)malloc(sizeof(TreeNode));
    root->data = preorder[preIndex++];
    if (start == end)
    {
        return root;
    }
    int inIndex = search(inorder, start, end, root->data);
    root->left = createTree(root->left, preorder, inorder, start, inIndex - 1);
    root->right = createTree(root->right, preorder, inorder, inIndex + 1, end);
    return root;
}

void inorderTraverse(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraverse(root->left);
    printf("%d ", root->data);
    inorderTraverse(root->right);
}

void preorderTraverse(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorderTraverse(root->left);
    preorderTraverse(root->right);
}

int main()
{
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    TreeNode *root = NULL;
    root = createTree(root, preorder, inorder, 0, 6);
    inorderTraverse(root);
    printf("\n");
    preorderTraverse(root);
    printf("\n");
    return 0;
}