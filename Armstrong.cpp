#include <stdio.h>
#include <math.h>

int countDigits(int num) {
    if (num == 0) {
        return 0;
    } else {
        return 1 + countDigits(num / 10);
    }
}

int isArmstrong(int num, int n) {
    if (num == 0) {
        return 0;
    } else {
        int digit = num % 10;
        return pow(digit, n) + isArmstrong(num / 10, n);
    }
}

int main() {
    int num, sum = 0, temp;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;
    int n = countDigits(num);

    sum = isArmstrong(num, n);

    if (sum == temp) {
        printf("%d is an Armstrong number.\n", temp);
    } else {
        printf("%d is not an Armstrong number.\n", temp);
    }

    return 0;
}
