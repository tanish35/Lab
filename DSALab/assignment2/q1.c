#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void deleteNode(struct Node **head, int position)
{
    if (*head == NULL)
        return;

    struct Node *temp = *head;

    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
        return;

    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}
void printFifthElement(struct Node *head)
{
    for (int i = 0; i < 4; i++)
    {
        if (head == NULL)
            return;
        head = head->next;
    }
    if (head != NULL)
        printf("5th element: %d\n", head->data);
    else
        printf("The list has fewer than 5 elements.\n");
}

int main()
{
    struct Node *head = NULL;
    struct Node *temp = NULL;

    printf("Enter 10 elements: ");
    for (int i = 0; i < 10; i++)
    {
        int value;
        scanf("%d", &value);
        struct Node *newNode = createNode(value);
        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    deleteNode(&head, 2);
    deleteNode(&head, 4);
    printFifthElement(head);

    return 0;
}
