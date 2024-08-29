#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void print(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertAtPosition(struct node **head_ref, int position, int data)
{
    struct node *temp = *head_ref;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    if (position == 1)
    {
        newNode->next = *head_ref;
        *head_ref = newNode;
        return;
    }
    int i = 1;
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtPosition(struct node **head_ref, int position)
{
    struct node *temp = *head_ref;
    if (position == 1)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    int i = 1;
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    struct node *temp2 = temp->next;
    temp->next = temp2->next;
}

void countNodes(struct node *head)
{
    struct node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("Number of nodes: %d\n", count);
}

void reversePrint(struct node *head)
{
    if (head == NULL)
    {
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

struct node *reverse(struct node *head)
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

int main()
{
    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    node1->data = 10;
    struct node *head = node1;
    struct node *tail = node1;
    print(head);

    return 0;
}