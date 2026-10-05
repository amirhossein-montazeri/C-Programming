/*
 * Pointers - basics.
 * A pointer is a variable that stores the memory address of another variable.
 *
 *   &x  -> address of x          *p -> value stored at the address p
 */
#include <stdio.h>
#include <string.h>

/* 1. Declaring a pointer, printing the address and dereferencing it */
static void example1(void) {
    int a = 20;
    int *b = &a;
    printf("number: %d\n", a);
    printf("pointer (address of a): %p\n", (void *)b);  /* %p, not %d */
    printf("*b - 1 = %d\n", *b - 1);                     /* *b == a    */
}

/* 2. Pointer arithmetic: between two pointers only subtraction is valid
 *    (and only when both point inside the SAME array). No +, * or /.   */
static void example2(void) {
    int arr[4] = {43, 23, 10, 32};
    int *first = &arr[0], *last = &arr[3];
    printf("last - first = %td elements\n", last - first);
}

/* 3a. Reading through a pointer / pointer + integer */
static void example3a(void) {
    int arr[4] = {43, 23, 10, 32}, *d = &arr[0];
    printf("*d + 1     = %d\n", *d + 1);   /* 43 + 1 */
    printf("*(d + 1)   = %d\n", *(d + 1)); /* 23     */
}

/* 3b. Writing through a pointer modifies the original variable */
static void example3b(void) {
    int arr[4] = {43, 23, 10, 32}, *d = &arr[0];
    int *c = d + 1;
    *c = 5;
    printf("arr[1] after *c = 5: %d\n", arr[1]); /* 23 became 5 */
}

/* 4. Swap two integers through their addresses */
static void swapInt(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

static void example4(void) {
    int a = 10, b = 43;
    printf("before swap -> a: %d, b: %d\n", a, b);
    swapInt(&a, &b);
    printf("after  swap -> a: %d, b: %d\n", a, b);
}

/* 5. scanf needs the ADDRESS of a variable, not its value.
 *    scanf("%s", string) works because an array name is already a pointer
 *    to its first element. For a pointer p: scanf("%d", p) == scanf("%d", &*p) */
static void example5(void) {
    int data[4], *p = &data[0], i;
    int len = sizeof(data) / sizeof(data[0]);

    printf("Enter %d integers: ", len);
    for (i = 0; i < len; i++, p++) {
        if (scanf("%d", p) != 1) {   /* p already is an address */
            printf("Error! Invalid input.\n");
            return;
        }
    }
    /* scanf("%d", data[i]) would be WRONG: it passes the value, not the address */
    printf("You entered:");
    for (i = 0; i < len; i++)
        printf(" %d", data[i]);
    printf("\n");
}

/* 6. 2D array walked with one pointer.
 *    1D: int *p = &arr[0];     2D: int *p = *arr;
 *    arr[i][j] == *(p + i * numberOfColumns + j)                         */
static void example6(void) {
    int array[3][4] = {{4, 5, 2, 6}, {65, 3, 12, 2}, {90, 65, 89, 22}};
    int *p = *array;
    int row = sizeof(array) / sizeof(array[0]);
    int col = sizeof(array[0]) / sizeof(array[0][0]);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            printf("%d ", *(p + i * col + j));
        printf("\n");
    }
}

/* 7. strlen needs <string.h>; it counts characters before '\0' (not the buffer size) */
static void example7(void) {
    char answer[100] = "YES";
    printf("strlen(answer) = %zu, sizeof(answer) = %zu\n", strlen(answer), sizeof(answer));
}

int main(void) {
    printf("--- 1. address and dereference ---\n");  example1();
    printf("\n--- 2. pointer subtraction ---\n");    example2();
    printf("\n--- 3a. pointer + integer ---\n");     example3a();
    printf("\n--- 3b. write through pointer ---\n"); example3b();
    printf("\n--- 4. swap ---\n");                   example4();
    printf("\n--- 5. scanf with a pointer ---\n");   example5();
    printf("\n--- 6. 2D array with a pointer ---\n");example6();
    printf("\n--- 7. strlen ---\n");                 example7();
    return 0;
}
