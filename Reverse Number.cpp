#include <stdio.h>

int reverse(int num, int reversedNum) {
    if (num == 0) {
        return reversedNum;
    } else {
        int remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        return reverse(num / 10, reversedNum);
    }
}

int main() {
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    int reversedNum = reverse(num, 0);

    printf("Reversed number: %d\n", reversedNum);

    return 0;
}
