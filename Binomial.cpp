#include <stdio.h>

unsigned long long binomialCoeff(int n, int k) {
    unsigned long long C[n + 1][k + 1];
    int i, j;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= i && j <= k; j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    return C[n][k];
}

int main() {
    int n, k;
    printf("Enter the value of n and k for calculating binomial coefficient (n choose k): ");
    scanf("%d %d", &n, &k);

    if (n < 0 || k < 0) {
        printf("Invalid input! n and k must be non-negative.\n");
    } else if (k > n) {
        printf("Invalid input! k must be less than or equal to n.\n");
    } else {
        unsigned long long result = binomialCoeff(n, k);
        printf("Binomial coefficient (%d choose %d) is: %llu\n", n, k, result);
    }

    return 0;
}
