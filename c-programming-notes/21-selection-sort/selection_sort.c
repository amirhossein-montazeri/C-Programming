/*
 * Selection sort: for each position i find the minimum of A[i..r] and swap
 * it into place. O(n^2) comparisons but at most n-1 swaps. Not stable.
 */
#include <stdio.h>

void SelectionSort(int A[], int N) {
    int i, j, l = 0, r = N - 1, min, temp;
    for (i = l; i < r; i++) {
        min = i;
        for (j = i + 1; j <= r; j++) {
            if (A[j] < A[min])
                min = j;
        }
        if (min != i) {
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
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
    SelectionSort(A, N);
    printArray("after: ", A, N);
    return 0;
}
