#include <stdio.h>

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int maxSumOfDigits(int nums[], int size) {
    int maxSum = -1;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (sumOfDigits(nums[i]) == sumOfDigits(nums[j])) {
                int currentSum = nums[i] + nums[j];
                if (currentSum > maxSum) {
                    maxSum = currentSum;
                }
            }
        }
    }

    return maxSum;
}

int main() {
    int nums[100], size;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    printf("Enter %d positive integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }

    int result = maxSumOfDigits(nums, size);

    printf("Maximum sum of digits from two numbers: %d\n", result);

    return 0;
}
