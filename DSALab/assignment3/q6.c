#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    int top;
    int capacity;
    int *array;
} Stack;

void evaulatePostfix(char str[100])
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = strlen(str);
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            stack->top++;
            stack->array[stack->top] = str[i] - '0';
        }
        else
        {
            int a = stack->array[stack->top];
            stack->top--;
            int b = stack->array[stack->top];
            stack->top--;
            switch (str[i])
            {
            case '+':
                stack->top++;
                stack->array[stack->top] = a + b;
                break;
            case '-':
                stack->top++;
                stack->array[stack->top] = b - a;
                break;
            case '*':
                stack->top++;
                stack->array[stack->top] = a * b;
                break;
            case '/':
                stack->top++;
                stack->array[stack->top] = b / a;
                break;
            }
        }
    }
    printf("Result: %d\n", stack->array[stack->top]);
}

int main()
{
    char str[100] = "231*+9-";
    evaulatePostfix(str);
    return 0;
}