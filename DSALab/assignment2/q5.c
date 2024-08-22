#include <stdio.h>

#define MAX_DEGREE 10

void multiplyPolynomials(int poly1[], int poly2[], int result[], int size1, int size2)
{
    for (int i = 0; i < MAX_DEGREE; i++)
    {
        result[i] = 0;
    }

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            result[i + j] += poly1[i] * poly2[j];
        }
    }
}

void printPolynomial(int poly[], int size)
{
    int first = 1;
    for (int i = 0; i < size; i++)
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
    int poly1[MAX_DEGREE] = {0};
    int poly2[MAX_DEGREE] = {0};
    int result[2 * MAX_DEGREE] = {0};

    poly1[2] = 3;
    poly1[1] = 5;
    poly1[0] = 6;

    poly2[1] = 6;
    poly2[0] = 8;

    int size1 = 3;
    int size2 = 2;

    multiplyPolynomials(poly1, poly2, result, size1, size2);

    printf("Resultant Polynomial:\n");
    printPolynomial(result, size1 + size2 - 1);

    return 0;
}
