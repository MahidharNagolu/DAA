#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            left = mid + 1;
        }

        else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[100], n, key;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, 0, n - 1, key);
    if (result == -1) {
        printf("Element is not present in array\n");
    } else {
        printf("Element is present at index %d\n", result);
    }
    return 0;
}

