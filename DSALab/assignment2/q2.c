#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **head, int ndata)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = ndata;
    new_node->next = (*head);
    (*head) = new_node;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    int n, value;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        push(&head, value);
    }

    printf("Reversed list of integers:");
    printList(head);

    return 0;
}