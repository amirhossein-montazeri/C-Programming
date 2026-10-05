/*
 * Counting sort for integers in the range [0, K-1].
 *
 *   C[v]  = how many times the value v occurs, then the running total,
 *           i.e. the final (1-based) position of the last v.
 *   B     = output array, A = input array (overwritten with the result).
 *
 * Going from right to left keeps the sort stable. O(N + K) time.
 */
#include <stdio.h>

void CountingSort(int A[], int B[], int C[], int N, int K) {
    int i, l = 0, r = N - 1;

    for (i = 0; i < K; i++)
        C[i] = 0;
    for (i = l; i <= r; i++)
        C[A[i]]++;
    for (i = 1; i < K; i++)
        C[i] += C[i - 1];
    for (i = r; i >= l; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
    for (i = l; i <= r; i++)
        A[i] = B[i];
}

static void printArray(const char *label, int A[], int N) {
    printf("%s", label);
    for (int i = 0; i < N; i++) printf(" %d", A[i]);
    printf("\n");
}

int main(void) {
    int A[] = {4, 2, 2, 8, 3, 3, 1};
    int N = sizeof(A) / sizeof(A[0]);
    enum { K = 9 };                    /* values are in 0..8 */
    int B[sizeof(A) / sizeof(A[0])];
    int C[K];

    printArray("before:", A, N);
    CountingSort(A, B, C, N, K);
    printArray("after: ", A, N);
    return 0;
}
