/*
 * Insertion sort: take each element x = A[i] and shift the larger elements
 * of the sorted part A[l..i-1] one position to the right, then insert x.
 * Worst case O(n^2), best case (already sorted) O(n). Stable, in place.
 */
#include <stdio.h>

void InsertionSort(int A[], int N) {
    int i, j, l = 0, r = N - 1, x;
    for (i = l + 1; i <= r; i++) {
        x = A[i];
        j = i - 1;
        while (j >= l && x < A[j]) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
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
    InsertionSort(A, N);
    printArray("after: ", A, N);
    return 0;
}
