#include <stdio.h>

void print(int *B, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int k = i * n + j;
            printf("%d ", B[k]);
        }
        printf("\n");
    }
}

int main() {
    int B[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int m = 3;
    int n = 4;
    
    print(B, m, n);
    
    return 0;
}
