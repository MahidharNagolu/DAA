#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int array[100], n, m;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size of the array.\n");
        return 1;
    }
    
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &array[i]);
    }

    printf("Enter the value of M: ");
    scanf("%d", &m);

    printf("Enter the value of N: ");
    int N;
    scanf("%d", &N);

    if (m > n || N > n || m <= 0 || N <= 0) {
        printf("Invalid value of M or N.\n");
        return 1;
    }

    qsort(array, n, sizeof(int), compare);

    int mth_max = array[n - m];

    int nth_min = array[N - 1];

    int sum = mth_max + nth_min;
    int diff = mth_max - nth_min;

    printf("M-th maximum number: %d\n", mth_max);
    printf("N-th minimum number: %d\n", nth_min);
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", diff);

    return 0;
}
