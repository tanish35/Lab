#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void push(struct node **top, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode)
    {
        printf("Heap overflow\n");
        return;
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed to stack\n", data);
}

int pop(struct node **top)
{
    if (*top == NULL)
    {
        printf("Stack underflow\n");
        return -1;
    }
    struct node *temp = *top;
    *top = (*top)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int peek(struct node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

void display(struct node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = top;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *top = NULL;
    int choice, value;

    while (1)
    {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(&top, value);
            break;
        case 2:
            value = pop(&top);
            if (value != -1)
                printf("Popped value: %d\n", value);
            break;
        case 3:
            value = peek(top);
            if (value != -1)
                printf("Top value: %d\n", value);
            break;
        case 4:
            display(top);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}