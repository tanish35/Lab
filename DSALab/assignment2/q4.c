#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int coef;
    int exp;
    struct Node *next;
};

struct Node *createNode(int coef, int exp)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node **poly, int coef, int exp)
{
    struct Node *newNode = createNode(coef, exp);
    if (*poly == NULL)
    {
        *poly = newNode;
    }
    else
    {
        struct Node *temp = *poly;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int evaluatePolynomial(struct Node *poly, int x)
{
    int result = 0;
    while (poly != NULL)
    {
        result += poly->coef * pow(x, poly->exp);
        poly = poly->next;
    }
    return result;
}

int main()
{
    struct Node *poly = NULL;

    insertNode(&poly, 3, 2);
    insertNode(&poly, 5, 1);
    insertNode(&poly, 6, 0);

    int x = 2;
    int result = evaluatePolynomial(poly, x);

    printf("Polynomial evaluated at x = %d: %d\n", x, result);

    return 0;
}
