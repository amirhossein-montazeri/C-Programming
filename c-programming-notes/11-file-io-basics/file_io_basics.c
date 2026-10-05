/*
 * File I/O basics.
 *
 * Writing / appending:            Reading:
 *   fprintf(fptr, "%s", string);    fscanf(fptr, "%d", &number);
 *   fputs(string, fptr);            fgets(string, 20, fptr);
 *   putc(character, fptr);          getc(fptr);
 *
 * Modes: "r" read, "w" write (truncates), "a" append.
 * Always check fopen() for NULL and fclose() every file you opened - once.
 */
#include <stdio.h>

#define FILE_NAME "file.txt"

/* 1. Reading an integer from a file */
static void readInteger(void) {
    FILE *fptr = fopen(FILE_NAME, "r");
    if (fptr == NULL) {
        printf("Error!\n");
        return;
    }
    int num;
    if (fscanf(fptr, "%d", &num) == 1)
        printf("integer read: %d\n", num);
    else
        printf("no integer found\n");
    fclose(fptr);
}

/* 2. Reading a string from a file (at most size-1 characters) */
static void readString(void) {
    FILE *fptr = fopen(FILE_NAME, "r");
    if (fptr == NULL) {
        printf("Error!\n");
        return;
    }
    char string[10];
    if (fgets(string, sizeof(string), fptr) != NULL)
        printf("string read: %s\n", string);
    fclose(fptr);
}

/* 3. Reading a single character from a file */
static void readCharacter(void) {
    FILE *fptr = fopen(FILE_NAME, "r");
    if (fptr == NULL) {
        printf("ERROR!\n");
        return;
    }
    int character = getc(fptr);   /* int, so EOF can be detected */
    if (character != EOF)
        printf("character read: %c\n", character);
    fclose(fptr);
}

/* 4. Writing a number to a file ("w" overwrites the file) */
static void writeNumber(int num) {
    FILE *fw = fopen(FILE_NAME, "w");
    if (fw == NULL) {
        printf("ERROR!\n");
        return;
    }
    fprintf(fw, "%d", num);
    fclose(fw);
}

/* 5. Appending a string to a file ("a" keeps the old content) */
static void appendString(const char *string) {
    FILE *fw = fopen(FILE_NAME, "a");
    if (fw == NULL) {
        printf("ERROR!\n");
        return;
    }
    fputs(string, fw);
    fclose(fw);
}

int main(void) {
    writeNumber(2);          /* file.txt: 2    */
    appendString("EEE");     /* file.txt: 2EEE */
    readInteger();
    readString();
    readCharacter();
    return 0;
}
