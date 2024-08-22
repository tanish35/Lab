#include <stdio.h>

#define MAX_EXP 100

void addPolynomials(int poly1[], int poly2[], int result[], int maxExp1, int maxExp2)
{
    int i;

    for (i = 0; i < MAX_EXP; i++)
    {
        result[i] = 0;
    }

    for (i = 0; i <= maxExp1; i++)
    {
        result[i] += poly1[i];
    }

    for (i = 0; i <= maxExp2; i++)
    {
        result[i] += poly2[i];
    }
}

void printPolynomial(int poly[], int maxExp)
{
    int i;
    int first = 1;

    for (i = maxExp; i >= 0; i--)
    {
        if (poly[i] != 0)
        {
            if (!first)
            {
                printf(" + ");
            }
            printf("%dx^%d", poly[i], i);
            first = 0;
        }
    }

    if (first)
    {
        printf("0");
    }
    printf("\n");
}

int main()
{
    int poly1[MAX_EXP] = {0};
    int poly2[MAX_EXP] = {0};
    int result[MAX_EXP] = {0};
    int maxExp1 = 2, maxExp2 = 1;

    poly1[2] = 5;
    poly1[1] = 4;
    poly1[0] = 2;

    poly2[1] = 5;
    poly2[0] = 5;

    addPolynomials(poly1, poly2, result, maxExp1, maxExp2);

    printPolynomial(result, maxExp1 > maxExp2 ? maxExp1 : maxExp2);

    return 0;
}
