#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void createBoth(Node **head, int **arr, int n)
{
    *head = NULL;
    *arr = (int *)malloc(n * sizeof(int));
    Node *tail = NULL;
    for (int i = 0; i < n; i++)
    {
        int data;
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &data);
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->data = data;
        temp->next = NULL;
        if (*head == NULL)
        {
            *head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        (*arr)[i] = data;
    }
}

Node *insertAtPosition(Node *head, int data, int position)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if (position == 1)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        Node *temp1 = head;
        for (int i = 0; i < position - 2; i++)
        {
            temp1 = temp1->next;
            if (temp1 == NULL)
            {
                printf("Invalid position\n");
                return head;
            }
        }
        temp->next = temp1->next;
        temp1->next = temp;
    }
    return head;
}

Node *deleteAtPosition(Node *head, int position)
{
    Node *temp = head;
    if (head == NULL)
    {
        printf("Underflow\n");
        return head;
    }
    if (position == 1)
    {
        head = temp->next;
        free(temp);
    }
    else
    {
        for (int i = 0; i < position - 2; i++)
        {
            temp = temp->next;
            if (temp == NULL || temp->next == NULL)
            {
                printf("Invalid position\n");
                return head;
            }
        }
        Node *temp1 = temp->next;
        temp->next = temp1->next;
        free(temp1);
    }
    return head;
}

void display(Node *head)
{
    Node *temp = head;
    int c = 0;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        c++;
        temp = temp->next;
    }
    printf("\n");
    printf("Number of nodes: %d\n", c);
}

// int *createArray(int *n)
// {
//     printf("Enter the number of elements: ");
//     scanf("%d", n);
//     int *arr = (int *)malloc((*n) * sizeof(int));
//     for (int i = 0; i < *n; i++)
//     {
//         printf("Enter the element %d: ", i + 1);
//         scanf("%d", &arr[i]);
//     }
//     return arr;
// }

int *insertInArray(int *arr, int data, int position, int *n)
{
    arr = (int *)realloc(arr, (*n + 1) * sizeof(int));
    for (int i = *n; i >= position; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = data;
    (*n)++;
    return arr;
}

int *deleteInArray(int *arr, int position, int *n)
{
    if (position > *n)
    {
        printf("Underflow\n");
        return arr;
    }
    for (int i = position - 1; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr = (int *)realloc(arr, (*n - 1) * sizeof(int));
    (*n)--;
    return arr;
}

void displayArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    Node *head = NULL;
    int *arr = NULL;
    int arrSize = 0;
    int c = 1;

    while (c)
    {
        int choice;
        printf("Enter your choice: \n");
        printf("1.) Create a List\n2.) Insert at Position\n3.) Delete at Position\n4.) Display List\n5.) Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number of elements: ");
            scanf("%d", &arrSize);
            createBoth(&head, &arr, arrSize);
            break;

        case 2:
        {
            int data, position;
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            printf("Enter the position to be inserted: ");
            scanf("%d", &position);
            head = insertAtPosition(head, data, position);
            arr = insertInArray(arr, data, position, &arrSize);
            break;
        }

        case 3:
        {
            int position;
            printf("Enter the position to be deleted: ");
            scanf("%d", &position);
            head = deleteAtPosition(head, position);
            arr = deleteInArray(arr, position, &arrSize);
            break;
        }

        case 4:
            display(head);
            displayArray(arr, arrSize);
            break;

        case 5:
            c = 0;
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
    return 0;
}
