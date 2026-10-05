/*
 * Greatest Common Divisor (GCD / GCF) with the Euclidean algorithm.
 *
 * Exit codes:
 *   return 0 -> the program completed successfully
 *   return 1 -> the program ended with an error
 */
#include <stdio.h>

int main(void) {
    int num1, num2;

    printf("Enter num1: ");
    if (scanf("%d", &num1) != 1) {
        printf("Error! Invalid input.\n");
        return 1;
    }
    printf("Enter num2: ");
    if (scanf("%d", &num2) != 1) {
        printf("Error! Invalid input.\n");
        return 1;
    }

    if (num1 < 0 || num2 < 0) {
        printf("Error! Negative numbers are NOT valid.\n");
        return 1;
    }
    if (num1 == 0 && num2 == 0) {
        printf("Error! GCD(0, 0) is undefined.\n");
        return 1;
    }

    /* A = larger number, B = smaller number */
    int A, B;
    if (num1 >= num2) {
        A = num1;
        B = num2;
    } else {
        A = num2;
        B = num1;
    }

    /* Repeat: (A, B) -> (B, A mod B) until the remainder is 0 */
    while (B != 0) {
        int result = A % B;
        A = B;
        B = result;
    }

    printf("The GCF of %d and %d is %d\n", num1, num2, A);
    return 0;
}
