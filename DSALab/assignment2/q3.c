#include <stdio.h>
#include <stdlib.h>

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

void insertNode(struct Node **result, int coef, int exp)
{
    struct Node *newNode = createNode(coef, exp);
    if (*result == NULL)
    {
        *result = newNode;
    }
    else
    {
        struct Node *temp = *result;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct Node *addPolynomials(struct Node *poly1, struct Node *poly2)
{
    struct Node *result = NULL;
    struct Node *p1 = poly1;
    struct Node *p2 = poly2;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp > p2->exp)
        {
            insertNode(&result, p1->coef, p1->exp);
            p1 = p1->next;
        }
        else if (p1->exp < p2->exp)
        {
            insertNode(&result, p2->coef, p2->exp);
            p2 = p2->next;
        }
        else
        {
            int sumCoef = p1->coef + p2->coef;
            if (sumCoef != 0)
            {
                insertNode(&result, sumCoef, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        insertNode(&result, p1->coef, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        insertNode(&result, p2->coef, p2->exp);
        p2 = p2->next;
    }

    return result;
}

void printPolynomial(struct Node *poly)
{
    while (poly != NULL)
    {
        printf("%dx^%d", poly->coef, poly->exp);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

int main()
{
    struct Node *poly1 = createNode(5, 2);
    poly1->next = createNode(4, 1);
    poly1->next->next = createNode(2, 0);

    struct Node *poly2 = createNode(5, 1);
    poly2->next = createNode(5, 0);

    struct Node *result = addPolynomials(poly1, poly2);

    printPolynomial(result);

    return 0;
}
