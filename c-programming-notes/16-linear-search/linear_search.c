/*
 * Linear search: scan the array from the first element, comparing each
 * element with the key k. T(n) grows linearly with n.
 *
 *   Method 1: always N steps  -> returns the index of the LAST occurrence
 *   Method 2: at most N steps -> stops at the FIRST occurrence
 *
 * Both return -1 when k is not in the array.
 */
#include <stdio.h>

/* first method: always N steps */
int LinearSearch1(int v[], int N, int k) {
    int index = -1;
    for (int i = 0; i < N; i++)
        if (v[i] == k) index = i;
    return index;
}

/* second method: at most N steps */
int LinearSearch2(int v[], int N, int k) {
    int i = 0;
    int found = 0;
    while (i < N && found == 0) {
        if (k == v[i])
            found = 1;
        else
            i++;
    }
    if (found == 0)
        return -1;
    else
        return i;
}

int main(void) {
    int v[4] = {43, 12, 43, 20};
    int N = sizeof(v) / sizeof(v[0]);

    printf("array: 43 12 43 20\n");
    printf("LinearSearch1(k=43) = %d  (last occurrence)\n",  LinearSearch1(v, N, 43));
    printf("LinearSearch2(k=43) = %d  (first occurrence)\n", LinearSearch2(v, N, 43));
    printf("LinearSearch1(k=99) = %d  (not found)\n",        LinearSearch1(v, N, 99));
    printf("LinearSearch2(k=99) = %d  (not found)\n",        LinearSearch2(v, N, 99));
    return 0;
}
