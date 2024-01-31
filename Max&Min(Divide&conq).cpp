#include <stdio.h>

struct Pair {
    int min;
    int max;
};

struct Pair findMinMax(int arr[], int low, int high) {
    struct Pair minMax, leftMinMax, rightMinMax;
    int mid;

   
    if (low == high) {
        minMax.min = arr[low];
        minMax.max = arr[low];
        return minMax;
    }

    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            minMax.min = arr[low];
            minMax.max = arr[high];
        } else {
            minMax.min = arr[high];
            minMax.max = arr[low];
        }
        return minMax;
    }

    
    mid = (low + high) / 2;
    leftMinMax = findMinMax(arr, low, mid);
    rightMinMax = findMinMax(arr, mid + 1, high);

    if (leftMinMax.min < rightMinMax.min)
        minMax.min = leftMinMax.min;
    else
        minMax.min = rightMinMax.min;

    if (leftMinMax.max > rightMinMax.max)
        minMax.max = leftMinMax.max;
    else
        minMax.max = rightMinMax.max;

    return minMax;
}

int main() {
    int arr[100], n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Pair minMax = findMinMax(arr, 0, n - 1);

    printf("Minimum element is %d\n", minMax.min);
    printf("Maximum element is %d\n", minMax.max);

    return 0;
}

