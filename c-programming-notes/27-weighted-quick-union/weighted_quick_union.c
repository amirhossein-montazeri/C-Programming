/*
 * Weighted Quick-Union (union by size) - an optimization of Quick-Union.
 *
 * sz[i] = number of elements in the tree rooted at i. When two trees are
 * joined, the SMALLER tree is attached under the root of the LARGER one, so
 * the trees stay shallow: depth <= log2(N)  ->  find/union are O(log N).
 */
#include <stdio.h>
#define N 10000

int main(void) {
    int i, j, p, q, id[N], sz[N];

    for (i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }

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
                printf("pair %d %d not yet connected\n", p, q);
                if (sz[i] <= sz[j]) {             /* attach the smaller tree */
                    id[i] = j;
                    sz[j] += sz[i];
                } else {
                    id[j] = i;
                    sz[i] += sz[j];
                }
            }
        }
        printf("Input pair p q: ");
    }
    printf("\n");
    return 0;
}
