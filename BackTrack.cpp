#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

void printSubset(int subset[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

void generateSubsets(int set[], int subset[], int n, int subsetSize, int sum, int targetSum, int index) {
    if (index == n) {
        
        if (sum == targetSum) {
            printSubset(subset, subsetSize);
        }
        return;
    }

    subset[subsetSize] = set[index];
    generateSubsets(set, subset, n, subsetSize + 1, sum + set[index], targetSum, index + 1);

    generateSubsets(set, subset, n, subsetSize, sum, targetSum, index + 1);
}

void findSubsets(int set[], int n, int targetSum) {
    int subset[MAX_SIZE]; 
    generateSubsets(set, subset, n, 0, 0, targetSum, 0);
}

int main() {
    int n;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int set[MAX_SIZE];
    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    int targetSum;
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    printf("Subsets with sum equal to %d:\n", targetSum);
    findSubsets(set, n, targetSum);

    return 0;
}
