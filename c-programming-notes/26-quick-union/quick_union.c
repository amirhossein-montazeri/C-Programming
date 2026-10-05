/*
 * Quick-Union (union-find).
 *
 * Each element points to a "parent": id[i] is the parent of i, and a root is
 * an element with id[i] == i. Two elements are connected when they have the
 * same root.
 *
 *   find  : follow the parents up to the root     -> O(depth)
 *   union : make the root of p point to the root of q -> O(depth)
 *
 * Trees can become tall (worst case O(N) per operation) - see the weighted
 * version for the fix.
 */
#include <stdio.h>
#define N 10000

int main(void) {
    int i, j, p, q, id[N];

    for (i = 0; i < N; i++)
        id[i] = i;

    printf("Input pair p q: ");
    while (scanf("%d %d", &p, &q) == 2) {
        if (p < 0 || p >= N || q < 0 || q >= N) {
            printf("values must be in 0..%d\n", N - 1);
        } else {
            for (i = p; i != id[i]; i = id[i]);   /* root of p */
            for (j = q; j != id[j]; j = id[j]);   /* root of q */
            if (i == j) {
                printf("pair %d %d already connected\n", p, q);
            } else {
                id[i] = j;                        /* link the two trees */
                printf("pair %d %d not yet connected\n", p, q);
            }
        }
        printf("Input pair p q: ");
    }
    printf("\n");
    return 0;
}
