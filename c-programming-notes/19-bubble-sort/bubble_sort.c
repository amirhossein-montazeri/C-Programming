/*
 * Bubble sort: repeatedly compare adjacent elements and swap them when they
 * are out of order; after pass i the i largest elements are in place.
 * Always O(n^2) comparisons. Stable, in place.
 */
#include <stdio.h>

void BubbleSort(int A[], int N) {
    int i, j, l = 0, r = N - 1;
    int temp;
    for (i = l; i < r; i++) {
        for (j = l; j < r - i + l; j++)
            if (A[j] > A[j + 1]) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
    }
    return;
}

static void printArray(const char *label, int A[], int N) {
    printf("%s", label);
    for (int i = 0; i < N; i++) printf(" %d", A[i]);
    printf("\n");
}

int main(void) {
    int A[] = {5, 2, 9, 1, 5, 6, 0};
    int N = sizeof(A) / sizeof(A[0]);

    printArray("before:", A, N);
    BubbleSort(A, N);
    printArray("after: ", A, N);
    return 0;
}
