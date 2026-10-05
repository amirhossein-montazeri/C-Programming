/*
 * Quick-Find (union-find / dynamic connectivity).
 *
 * Reads pairs "p q" and tells whether p and q are already connected; if not,
 * connects them. Initially every element is its own component:  id[i] = i.
 * All elements with the same id[] value are in the same component.
 *
 *   find  : id[p] == id[q]            -> O(1)
 *   union : relabel every element     -> O(N)
 *
 * scanf returns the number of values read:
 *   while (scanf("%d %d", &p, &q))        -> true when at least one is read (and
 *                                            even -1/EOF is "true"!)
 *   while (scanf("%d %d", &p, &q) == 2)   -> exactly two integers: safer
 */
#include <stdio.h>
#define N 10000

int main(void) {
    int i, t, p, q, id[N];

    for (i = 0; i < N; i++)
        id[i] = i;

    printf("Input pair p q: ");
    while (scanf("%d %d", &p, &q) == 2) {
        if (p < 0 || p >= N || q < 0 || q >= N) {
            printf("values must be in 0..%d\n", N - 1);
        } else if (id[p] == id[q]) {
            printf("pair %d %d already connected\n", p, q);
        } else {
            for (t = id[p], i = 0; i < N; i++)
                if (id[i] == t) id[i] = id[q];
            printf("pair %d %d not yet connected\n", p, q);
        }
        printf("Input pair p q: ");
    }
    printf("\n");
    return 0;
}
