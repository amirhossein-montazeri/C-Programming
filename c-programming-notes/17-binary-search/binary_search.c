/*
 * Binary search.
 * Let v[N] be a SORTED array of N distinct elements and let k be a key.
 * Each step halves the search interval -> O(log N).
 */
#include <stdio.h>

int BinarySearch(int v[], int N, int k) {
    int found = 0, l = 0, r = N - 1, m = -1;
    while (l <= r && found == 0) {
        m = (l + r) / 2;
        if (v[m] == k)
            found = 1;
        else if (v[m] < k)
            l = m + 1;
        else
            r = m - 1;
    }
    if (found == 0)
        return -1;
    else
        return m;
}

int main(void) {
    int v[6] = {0, 6, 8, 9, 15, 21};      /* must be sorted */
    int N = sizeof(v) / sizeof(v[0]);

    printf("array: 0 6 8 9 15 21\n");
    printf("BinarySearch(k=9)  = %d\n", BinarySearch(v, N, 9));
    printf("BinarySearch(k=21) = %d\n", BinarySearch(v, N, 21));
    printf("BinarySearch(k=4)  = %d  (not found)\n", BinarySearch(v, N, 4));
    return 0;
}
