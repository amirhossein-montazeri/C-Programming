/*
 * Build a file name by concatenating ".txt" to a name typed by the user.
 *
 * The buffer holds 50 bytes: at most 45 characters are read ("%45s"), which
 * leaves room for ".txt" (4 chars) and the terminating '\0'.
 */
#include <stdio.h>
#include <string.h>

int main(void) {
    char fileName[50];

    printf("Enter the name of the file: ");
    if (scanf("%45s", fileName) != 1) {
        printf("Error! Invalid input.\n");
        return 1;
    }

    /* concatenate the name with ".txt" */
    strcat(fileName, ".txt");

    printf("%s\n", fileName);
    return 0;
}
