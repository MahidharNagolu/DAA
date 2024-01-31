#include <stdio.h>

int isPerfect(int num) {
    int sum = 1; 

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;
            if (i * i != num) {
                sum += num / i;
            }
        }
    }

    return (sum == num);
}


void printPerfectNumbers(int n) {
    printf("First %d perfect numbers:\n", n);

    int count = 0;
    int num = 1;

    while (count < n) {
        if (isPerfect(num)) {
            printf("%d\n", num);
            count++;
        }
        num++;
    }
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printPerfectNumbers(n);

    return 0;
}
