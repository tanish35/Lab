#include <stdio.h>
#include <math.h>

#define MAX_EXP 100

int main()
{
    int poly[MAX_EXP] = {0};
    int x = 2;
    int maxExp = 2;
    int result = 0;

    poly[2] = 3;
    poly[1] = 5;
    poly[0] = 6;

    for (int i = 0; i <= maxExp; i++)
    {
        result += poly[i] * pow(x, i);
    }

    printf("Polynomial evaluated at x = %d: %d\n", x, result);

    return 0;
}
