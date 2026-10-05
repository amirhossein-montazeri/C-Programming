/*
 * Fibonacci sequence and a "modified" Fibonacci sequence.
 *
 *   Fibonacci : x2 = x1 + x0, starting from 0, 1  -> 0 1 1 2 3 5 ...
 *   Modified  : x2 = x1 * x0, starting from 1, 2  -> 1 2 2 4 8 32 ...
 *
 * Sliding window:   x0, x1, x2
 *                        x0, x1, x2   (x0 <- x1, x1 <- x2)
 */
#include <stdio.h>

#define MAX_FIB 93  /* F(92) is the last Fibonacci number fitting 64 bits   */
#define MAX_MOD 11  /* the modified sequence grows like 2^Fib(n): 64-bit limit */

static void fibonacci(int n) {
    unsigned long long x0 = 0, x1 = 1, x2;
    for (int i = 0; i < n; i++) {
        printf("%llu ", x0);
        x2 = x0 + x1;
        x0 = x1;
        x1 = x2;
    }
    printf("\n");
}

static void modified(int n) {
    unsigned long long x0 = 1, x1 = 2, x2;
    for (int i = 0; i < n; i++) {
        printf("%llu ", x0);
        x2 = x0 * x1;
        x0 = x1;
        x1 = x2;
    }
    printf("\n");
}

int main(void) {
    int N;

    printf("Enter a number: ");
    if (scanf("%d", &N) != 1 || N < 1) {
        printf("Error! Enter a positive integer.\n");
        return 1;
    }

    int nFib = N > MAX_FIB ? MAX_FIB : N;
    int nMod = N > MAX_MOD ? MAX_MOD : N;

    printf("The Fibonacci sequence (%d terms):\n", nFib);
    fibonacci(nFib);

    printf("The modified sequence (%d terms):\n", nMod);
    modified(nMod);

    if (nFib < N || nMod < N)
        printf("(output limited to avoid 64-bit overflow)\n");

    return 0;
}
