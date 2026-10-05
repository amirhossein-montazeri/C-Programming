/*
 * Arrays of pointers.
 *
 * Standard C uses "int main(void)" (returns an exit status); "void main(void)"
 * is non-standard. Examples 1 and 2 pick the k-th character of each string.
 */
#include <stdio.h>
#include <string.h>

/* 1. 1D array of strings: print the k-th character of every element */
static void example1(int k) {
    char *name[3] = {"Robert", "Carlos", "Tomson"};
    int len = sizeof(name) / sizeof(name[0]);
    for (int i = 0; i < len; i++) {
        if ((size_t)k < strlen(name[i]))
            printf("%c", name[i][k]);
        else
            printf(" ");
        printf("\n");
    }
}

/* 2. 2D array of strings */
static void example2(int k) {
    char *name[2][2] = {{"Robert", "Carlos"}, {"Tomson", "fazel"}};
    int len1 = sizeof(name) / sizeof(name[0]);
    int len2 = sizeof(name[0]) / sizeof(name[0][0]);
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if ((size_t)k < strlen(name[i][j]))
                printf("%c", name[i][j][k]);
            else
                printf(" ");
            printf("\n");
        }
    }
}

/* 3. Array of pointers to int arrays.  *(values[i] + j) == values[i][j] */
static void example3(void) {
    int mat1[2] = {5, 3};
    int mat2[2] = {9, 6};
    int *values[2] = {mat1, mat2};
    int len = sizeof(values) / sizeof(values[0]);   /* number of rows    */
    int cols = 2;                                   /* size of each row  */
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", *(values[i] + j));
        printf("\n");
    }
}

/* 4. Array of strings: print each one with %s */
static void example4(void) {
    char *months[2] = {"August", "September"};
    /* printf("%s", months) would be an error: months is an array of POINTERS;
     * the strings are months[i]. */
    for (int i = 0; i < 2; i++)
        printf("Month %d : %s\n", i, months[i]);
}

int main(void) {
    int k;
    printf("Enter a number: ");
    if (scanf("%d", &k) != 1 || k < 0) {
        printf("Error! Enter a non-negative integer.\n");
        return 1;
    }

    printf("\n1) 1D array of strings:\n");  example1(k);
    printf("\n2) 2D array of strings:\n");  example2(k);
    printf("\n3) array of int pointers:\n");example3();
    printf("\n4) months:\n");               example4();
    return 0;
}
