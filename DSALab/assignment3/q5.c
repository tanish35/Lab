#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct Stack
{
    int top;
    int capacity;
    char *array;
};

struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

char peek(struct Stack *stack)
{
    return stack->array[stack->top];
}

char pop(struct Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(struct Stack *stack, char op)
{
    stack->array[++stack->top] = op;
}

int isOperand(char ch)
{
    return isalnum(ch);
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

void infixToPostfix(char *exp, char *postfix)
{
    struct Stack *stack = createStack(strlen(exp));
    int k = 0;
    int l = strlen(exp);

    for (int i = 0; i < l; i++)
    {
        if (isOperand(exp[i]))
        {
            postfix[k++] = exp[i];
        }
        else if (exp[i] == '(')
        {
            push(stack, exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
            {
                postfix[k++] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(')
            {
                return;
            }
            else
            {
                pop(stack);
            }
        }
        else
        {
            while (!isEmpty(stack) && precedence(exp[i]) <= precedence(peek(stack)))
            {
                postfix[k++] = pop(stack);
            }
            push(stack, exp[i]);
        }
    }

    while (!isEmpty(stack))
    {
        postfix[k++] = pop(stack);
    }

    postfix[k] = '\0';
}

int main()
{
    char exp[MAX];
    char postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", exp);

    infixToPostfix(exp, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
