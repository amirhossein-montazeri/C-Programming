/*
 * Optimized bubble sort: a flag records whether a pass performed any swap.
 * If a whole pass makes no swap the array is already sorted, so the sort
 * stops early. Best case (already sorted) O(n), worst case O(n^2).
 */
#include <stdio.h>

void optBubbleSort(int A[], int N) {
    int i, j, l = 0, r = N - 1, flag = 1;
    int temp;

    for (i = l; i < r && flag == 1; i++) {
        flag = 0;
        for (j = l; j < r - i + l; j++) {
            if (A[j] > A[j + 1]) {
                flag = 1;
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
    return;   /* after the loops - not inside the outer loop */
}

static void printArray(const char *label, int A[], int N) {
    printf("%s", label);
    for (int i = 0; i < N; i++) printf(" %d", A[i]);
    printf("\n");
}

int main(void) {
    int A[] = {5, 2, 9, 1, 5, 6, 0};
    int B[] = {1, 2, 3, 4, 5};              /* already sorted: one pass only */
    int N = sizeof(A) / sizeof(A[0]);
    int M = sizeof(B) / sizeof(B[0]);

    printArray("before:", A, N);
    optBubbleSort(A, N);
    printArray("after: ", A, N);

    printArray("\nsorted input:", B, M);
    optBubbleSort(B, M);
    printArray("after:       ", B, M);
    return 0;
}
