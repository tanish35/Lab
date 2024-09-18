#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *array;
    int top;
} Stack;

void enqueue(int data, Stack **stack1, Stack **stack2)
{
    while ((*stack1)->top != -1)
    {
        (*stack2)->top++;
        (*stack2)->array[(*stack2)->top] = (*stack1)->array[(*stack1)->top];
        (*stack1)->top--;
    }
    (*stack1)->top++;
    (*stack1)->array[(*stack1)->top] = data;
    while ((*stack2)->top != -1)
    {
        (*stack1)->top++;
        (*stack1)->array[(*stack1)->top] = (*stack2)->array[(*stack2)->top];
        (*stack2)->top--;
    }
}

void dequeue(Stack **stack1)
{
    if ((*stack1)->top == -1)
    {
        printf("UnderFlow\n");
        return;
    }
    printf("%d\n", (*stack1)->array[(*stack1)->top]);
    (*stack1)->top--;
}

void print(Stack *stack1)
{
    for (int i = 0; i <= stack1->top; i++)
    {
        printf("%d ", stack1->array[i]);
    }
    printf("\n");
}

int main()
{
    Stack *stack1 = (Stack *)malloc(sizeof(Stack));
    stack1->array = (int *)malloc(100 * sizeof(int));
    stack1->top = -1;
    Stack *stack2 = (Stack *)malloc(sizeof(Stack));
    stack2->array = (int *)malloc(100 * sizeof(int));
    stack2->top = -1;
    enqueue(1, &stack1, &stack2);
    enqueue(2, &stack1, &stack2);
    enqueue(3, &stack1, &stack2);
    enqueue(4, &stack1, &stack2);
    print(stack1);
    dequeue(&stack1);
    print(stack1);

    return 0;
}