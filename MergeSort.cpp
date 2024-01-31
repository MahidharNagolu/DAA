#include <stdio.h>
#include <stdlib.h>

int* mergeSortedArrays(int nums1[], int m, int nums2[], int n, int *mergedSize) {
    int* merged = (int*)malloc((m + n) * sizeof(int));
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (nums1[i] >= nums2[j]) {
            merged[k++] = nums1[i++];
        } else {
            merged[k++] = nums2[j++];
        }
    }

    while (i < m) {
        merged[k++] = nums1[i++];
    }

    while (j < n) {
        merged[k++] = nums2[j++];
    }

    *mergedSize = k;
    return merged;
}

void sortArray(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int m, n;

    printf("Enter the number of elements in the first array (nums1): ");
    scanf("%d", &m);
    int nums1[m];
    printf("Enter %d elements for nums1:\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    printf("Enter the number of elements in the second array (nums2): ");
    scanf("%d", &n);
    int nums2[n];
    printf("Enter %d elements for nums2:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    sortArray(nums1, m);
    sortArray(nums2, n);

    int mergedSize;
    int* merged = mergeSortedArrays(nums1, m, nums2, n, &mergedSize);

    printf("Merged and sorted array: ");
    printArray(merged, mergedSize);

    free(merged); 

    return 0;
}
