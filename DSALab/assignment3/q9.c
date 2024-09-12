#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *arr;
    int top;
    int size;
} Stack;

typedef struct Queue
{
    Stack *s1;
    Stack *s2;
} Queue;

Stack *createStack(int size)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (int *)malloc(stack->size * sizeof(int));
    return stack;
}

int isFull(Stack *stack)
{
    return stack->top == stack->size - 1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, int data)
{
    if (!isFull(stack))
    {
        stack->arr[++stack->top] = data;
    }
}

int pop(Stack *stack)
{
    if (!isEmpty(stack))
    {
        return stack->arr[stack->top--];
    }
    return -1;
}

Queue *createQueue(int size)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->s1 = createStack(size);
    queue->s2 = createStack(size);
    return queue;
}

void enqueue(Queue *queue, int data)
{
    push(queue->s1, data);
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue->s2))
    {
        while (!isEmpty(queue->s1))
        {
            push(queue->s2, pop(queue->s1));
        }
    }
    return pop(queue->s2);
}

void inputQueue(Queue *queue, int n)
{
    int data;
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        enqueue(queue, data);
    }
}

void displayQueue(Queue *queue)
{
    if (isEmpty(queue->s2))
    {
        while (!isEmpty(queue->s1))
        {
            push(queue->s2, pop(queue->s1));
        }
    }
    for (int i = queue->s2->top; i >= 0; i--)
    {
        printf("%d ", queue->s2->arr[i]);
    }
    printf("\n");
}

int main()
{
    int size, n;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    Queue *queue = createQueue(size);

    printf("Enter the number of elements to enqueue: ");
    scanf("%d", &n);

    inputQueue(queue, n);

    printf("Queue contents: ");
    displayQueue(queue);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Queue contents after dequeue: ");
    displayQueue(queue);

    return 0;
}
