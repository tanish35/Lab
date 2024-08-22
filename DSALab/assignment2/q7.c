#include <stdio.h>

#define SIZE 3

void addSparseMatrices(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE], int result[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void printMatrix(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int mat1[SIZE][SIZE] = {
        {0, 0, 3},
        {4, 0, 0},
        {0, 5, 0}};

    int mat2[SIZE][SIZE] = {
        {0, 2, 0},
        {0, 0, 6},
        {7, 0, 0}};

    int result[SIZE][SIZE] = {0};

    addSparseMatrices(mat1, mat2, result);

    printf("Resultant Sparse Matrix:\n");
    printMatrix(result);

    return 0;
}
#include <stdio.h>

#define SIZE 3

void addSparseMatrices(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE], int result[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void printMatrix(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int mat1[SIZE][SIZE] = {
        {0, 0, 3},
        {4, 0, 0},
        {0, 5, 0}};

    int mat2[SIZE][SIZE] = {
        {0, 2, 0},
        {0, 0, 6},
        {7, 0, 0}};

    int result[SIZE][SIZE] = {0};

    addSparseMatrices(mat1, mat2, result);

    printf("Resultant Sparse Matrix:\n");
    printMatrix(result);

    return 0;
}
