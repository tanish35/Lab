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
        struct Node *prev = NULL;
        while (temp != NULL && temp->exp > exp)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp != NULL && temp->exp == exp)
        {
            temp->coef += coef;
            free(newNode);
        }
        else
        {
            newNode->next = temp;
            if (prev == NULL)
            {
                *poly = newNode;
            }
            else
            {
                prev->next = newNode;
            }
        }
    }
}

struct Node *multiplyPolynomials(struct Node *poly1, struct Node *poly2)
{
    struct Node *result = NULL;
    struct Node *p1 = poly1;
    while (p1 != NULL)
    {
        struct Node *p2 = poly2;
        while (p2 != NULL)
        {
            int coef = p1->coef * p2->coef;
            int exp = p1->exp + p2->exp;
            insertNode(&result, coef, exp);
            p2 = p2->next;
        }
        p1 = p1->next;
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
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;

    insertNode(&poly1, 3, 2);
    insertNode(&poly1, 5, 1);
    insertNode(&poly1, 6, 0);

    insertNode(&poly2, 6, 1);
    insertNode(&poly2, 8, 0);

    struct Node *result = multiplyPolynomials(poly1, poly2);

    printPolynomial(result);

    return 0;
}
