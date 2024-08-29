#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createCircularLinkedList(int n)
{
    struct node *head = NULL, *temp = NULL, *newNode = NULL;
    for (int i = 1; i <= n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = i;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    temp->next = head;
    return head;
}

int josephus(struct node *head, int k)
{
    struct node *ptr1 = head, *ptr2 = head;
    while (ptr1->next != ptr1)
    {
        int count = 1;
        while (count != k)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
            count++;
        }
        ptr2->next = ptr1->next;
        ptr1 = ptr2->next;
    }
    int result = ptr1->data;
    return result;
}

int main()
{
    int n = 7;
    int k = 3;
    struct node *head = createCircularLinkedList(n);
    int survivor = josephus(head, k);
    printf("The survivor is person %d\n", survivor);
    return 0;
}