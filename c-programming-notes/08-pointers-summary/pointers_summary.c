/*
 * Pointers summary
 *
 * A) SIMPLE ARRAYS (1D and 2D)           ->  *(p + i)      or  *(p + i*col + j)
 * B) ARRAYS OF POINTERS (1D and 2D)      ->  *(values[i]+j) or  names[i]
 *
 * Arrays of pointers were written with "void main(void)" in the original
 * notes; here everything uses the standard "int main(void)".
 */
#include <stdio.h>
#include <string.h>

/* ---------- A) simple arrays ---------- */

/* A1. 1D array: attach a pointer to the array and read through it */
static void A1(void) {
    int arr[3] = {23, 234, 12};
    int *p = &arr[0];
    for (int i = 0; i < 3; i++)
        printf("%d ", *(p + i));
    printf("\n");
}

/* A2. 1D array: fill the array through a pointer */
static void A2(void) {
    int arr[3];
    int *p = &arr[0];
    printf("Enter 3 integers: ");
    for (int i = 0; i < 3; i++, p++) {
        if (scanf("%d", p) != 1) {
            printf("Error! Invalid input.\n");
            return;
        }
    }
    for (int i = 0; i < 3; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* A3. 2D array read through a pointer: arr[i][j] = *(p + i*col + j) */
static void A3(void) {
    int arr[2][2] = {{2, 4}, {5, 0}};
    int *p = *arr;
    int row = sizeof(arr) / sizeof(arr[0]);
    int col = sizeof(arr[0]) / sizeof(arr[0][0]);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            printf("%d ", *(p + i * col + j));
        printf("\n");
    }
}

/* ---------- B) arrays of pointers ---------- */

/* B1. 1D array of pointers (strings): print the j-th character of each string */
static void B1(void) {
    char *day[2] = {"lunedi", "martedi"};
    int j;
    printf("Enter an integer number: ");
    if (scanf("%d", &j) != 1 || j < 0) {   /* scanf needs &j, the address of j */
        printf("Error! Invalid input.\n");
        return;
    }
    int len = sizeof(day) / sizeof(day[0]);
    for (int i = 0; i < len; i++) {
        if ((size_t)j < strlen(day[i]))
            printf("%c", day[i][j]);
        else
            printf(" ");
        printf("\n");
    }
}

/* B2. "2D" array through an array of pointers to int arrays */
static void B2(void) {
    int mat1[2] = {4, 5};
    int mat2[2] = {9, 2};
    int *values[2] = {mat1, mat2};
    int row = sizeof(values) / sizeof(values[0]);
    int col = 2;   /* each pointed-to array has 2 elements (sizeof(values[0]) would be the pointer size) */
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            printf("%d ", *(values[i] + j));   /* == values[i][j] */
        printf("\n");
    }
}

/* B3. 1D array of pointers: print whole strings */
static void B3(void) {
    char *names[2] = {"mahasti", "hayedeh"};
    for (int i = 0; i < 2; i++)
        printf("%d.name: %s\n", i, names[i]);
}

int main(void) {
    printf("A1 - 1D array read with a pointer:\n");   A1();
    printf("\nA2 - 1D array filled with a pointer:\n"); A2();
    printf("\nA3 - 2D array read with a pointer:\n");   A3();
    printf("\nB1 - 1D array of pointers (characters):\n"); B1();
    printf("\nB2 - array of pointers to int arrays:\n");   B2();
    printf("\nB3 - 1D array of pointers (strings):\n");    B3();
    return 0;
}
