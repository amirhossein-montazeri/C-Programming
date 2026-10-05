/*
 * while vs do-while
 * -----------------
 * while    : checks the condition BEFORE every iteration (may run 0 times).
 * do-while : checks the condition AFTER every iteration (runs at least once).
 */
#include <stdio.h>

int main(void) {
    int i = 0;

    printf("while loop (i < 5):\n");
    while (i < 5) {
        printf("%d\n", i);
        i++;
    }

    printf("\ndo-while loop (i < 4):\n");
    i = 0;
    do {
        printf("%d\n", i);
        i++;
    } while (i < 4);

    /* The condition is false from the start: the difference becomes visible. */
    int n = 10;

    printf("\nwhile with a false condition (n < 5):\n");
    while (n < 5) {
        printf("n = %d (never printed)\n", n);
    }
    printf("(body skipped)\n");

    printf("\ndo-while with a false condition (n < 5):\n");
    do {
        printf("n = %d (printed once)\n", n);
    } while (n < 5);

    return 0;
}
