#include <stdio.h>

#define ROWS 3
#define COLS 3

void countNonZeroInRows(int matrix[ROWS][COLS], int nonZeroCount[ROWS])
{
    for (int i = 0; i < ROWS; i++)
    {
        int count = 0;
        for (int j = 0; j < COLS; j++)
        {
            if (matrix[i][j] != 0)
            {
                count++;
            }
        }
        nonZeroCount[i] = count;
    }
}

void printNonZeroCount(int nonZeroCount[ROWS])
{
    for (int i = 0; i < ROWS; i++)
    {
        printf("Row %d has %d non-zero elements\n", i, nonZeroCount[i]);
    }
}

int main()
{
    int matrix[ROWS][COLS] = {
        {0, 0, 3},
        {4, 0, 0},
        {0, 5, 6}};

    int nonZeroCount[ROWS] = {0};

    countNonZeroInRows(matrix, nonZeroCount);

    printf("Non-zero element counts per row:\n");
    printNonZeroCount(nonZeroCount);

    return 0;
}
