/*
 * 2-way merge: merges the two SORTED sub-arrays A[l..q] and A[q+1..r] into
 * one sorted sequence, using the auxiliary array B. O(r - l + 1).
 * It is the building block of every merge sort.
 *
 * Using "<=" when the elements are equal takes the element from the left
 * half first, which keeps the merge stable.
 */
#include <stdio.h>

void merge(int A[], int B[], int l, int q, int r) {
    int i, j, k;
    i = l;
    j = q + 1;
    for (k = l; k <= r; k++) {
        if (i > q)
            B[k] = A[j++];              /* left half exhausted  */
        else if (j > r)
            B[k] = A[i++];              /* right half exhausted */
        else if (A[i] <= A[j])
            B[k] = A[i++];
        else
            B[k] = A[j++];
    }
    for (k = l; k <= r; k++)            /* copy back, after the merge loop */
        A[k] = B[k];
    return;
}

static void printArray(const char *label, int A[], int N) {
    printf("%s", label);
    for (int i = 0; i < N; i++) printf(" %d", A[i]);
    printf("\n");
}

int main(void) {
    /* A[0..3] and A[4..8] are both sorted */
    int A[] = {2, 5, 8, 11, 1, 3, 4, 9, 10};
    int B[9];
    int N = sizeof(A) / sizeof(A[0]);

    printArray("before:", A, N);
    merge(A, B, 0, 3, N - 1);
    printArray("after: ", A, N);
    return 0;
}
