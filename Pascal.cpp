#include <stdio.h>

long long factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

long long binomialCoeff(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

void printPascalTriangle(int n) {
    for (int line = 0; line < n; line++) {
     
        for (int j = 0; j < n - line - 1; j++) {
            printf(" ");
        }

     
        for (int i = 0; i <= line; i++) {
            printf("%lld ", binomialCoeff(line, i));
        }

        printf("\n");
    }
}

int main() {
    int numRows;
    printf("Enter the number of rows for Pascal's triangle: ");
    scanf("%d", &numRows);

    printPascalTriangle(numRows);

    return 0;
}
