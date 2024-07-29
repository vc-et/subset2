#include <stdio.h>
#include <stdbool.h>

void findSubsets(int set[], int n, int sum, int subset[], int size) {
    if (sum == 0) {
        printf("subset :");
        for (int i = 0; i < size; i++) 
        printf("%d ", subset[i]);
        printf("\n");
        return;
    }
    if (n == 0 || sum < 0) return;
    subset[size] = set[n - 1];
    findSubsets(set, n - 1, sum - set[n - 1], subset, size + 1);
    findSubsets(set, n - 1, sum, subset, size);
}

void findSubsetsWithSum(int set[], int n, int sum) 
{
    int subset[n];
    printf("Subsets with sum %d:\n", sum);
    findSubsets(set, n, sum, subset, 0);
}
int main() {
    int set[] = {3,4,2,12,5,34};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    findSubsetsWithSum(set, n, sum);
    return 0;
}
