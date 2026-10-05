/*
 * Bottom-up (iterative) merge sort, no recursion.
 * m = 1, 2, 4, 8, ... : merge every pair of adjacent sorted blocks of length m.
 * O(n log n) time, O(n) extra space (the auxiliary array B).
 */
#include <stdio.h>

void merge(int A[], int B[], int l, int q, int r) {
    int i = l, j = q + 1, k;
    for (k = l; k <= r; k++) {
        if (i > q)
            B[k] = A[j++];
        else if (j > r)
            B[k] = A[i++];
        else if (A[i] <= A[j])
            B[k] = A[i++];
        else
            B[k] = A[j++];
    }
    for (k = l; k <= r; k++)
        A[k] = B[k];
}

static int min(int a, int b) { return a < b ? a : b; }

void BottomUpMergeSort(int A[], int B[], int N) {
    int i, q, m, l = 0, r = N - 1;
    for (m = 1; m <= r - l; m = m + m) {
        for (i = l; i <= r - m; i += m + m) {
            q = i + m - 1;
            /* the last block may be shorter: right end = min(i + 2m - 1, r) */
            merge(A, B, i, q, min(i + m + m - 1, r));
        }
    }
}

static void printArray(const char *label, int A[], int N) {
    printf("%s", label);
    for (int i = 0; i < N; i++) printf(" %d", A[i]);
    printf("\n");
}

int main(void) {
    int A[] = {38, 27, 43, 3, 9, 82, 10, 5, 1, 64, 7};
    int N = sizeof(A) / sizeof(A[0]);
    int B[sizeof(A) / sizeof(A[0])];

    printArray("before:", A, N);
    BottomUpMergeSort(A, B, N);
    printArray("after: ", A, N);
    return 0;
}
