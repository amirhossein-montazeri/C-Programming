/*
 * Command-line arguments: convert a text file to lower or upper case.
 *
 * Usage:   ./case_converter <L|U> <input_name> [output_file]
 *   L  -> convert to lower case
 *   U  -> convert to UPPER case
 *   <input_name> : file name; ".txt" is appended when missing
 *   [output_file]: default output.txt
 *
 * Example: ./case_converter U input        (reads input.txt, writes output.txt)
 *
 * argv[0] = program name, argv[1] = mode, argv[2] = input name, argv[3] = output
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ToLower(FILE *fp_in, FILE *fp_out);
int ToUpper(FILE *fp_in, FILE *fp_out);

int main(int argc, char *argv[]) {
    FILE *fp_read, *fp_write;
    int numberOfCharacters = 0;
    char filename[256];

    if (argc < 3 || argc > 4 || strlen(argv[1]) != 1) {
        printf("Usage: %s <L|U> <input_name> [output_file]\n", argv[0]);
        return 1;
    }
    char choice = argv[1][0];
    const char *outName = argc == 4 ? argv[3] : "output.txt";

    if (strlen(argv[2]) > sizeof(filename) - 5) {
        printf("Error: file name too long.\n");
        return 1;
    }
    strcpy(filename, argv[2]);
    size_t len = strlen(filename);
    if (len < 4 || strcmp(filename + len - 4, ".txt") != 0)
        strcat(filename, ".txt");

    if (choice != 'L' && choice != 'U') {
        printf("Error: invalid character (use L or U).\n");
        return 5;
    }

    if ((fp_read = fopen(filename, "r")) == NULL) {
        printf("Error opening file %s.\n", filename);
        return 2;
    }
    if ((fp_write = fopen(outName, "w")) == NULL) {
        printf("Error opening file %s.\n", outName);
        fclose(fp_read);
        return 3;
    }

    numberOfCharacters = (choice == 'L') ? ToLower(fp_read, fp_write)
                                         : ToUpper(fp_read, fp_write);
    fclose(fp_read);
    fclose(fp_write);

    if (numberOfCharacters == 0)
        printf("No characters.\n");
    else
        printf("Number of characters: %d\n", numberOfCharacters);

    return 0;
}

int ToLower(FILE *fp_in, FILE *fp_out) {
    int numberOfCharacters = 0, ch;
    while ((ch = getc(fp_in)) != EOF) {
        putc(tolower(ch), fp_out);
        numberOfCharacters++;
    }
    return numberOfCharacters;
}

int ToUpper(FILE *fp_in, FILE *fp_out) {
    int numberOfCharacters = 0, ch;
    while ((ch = getc(fp_in)) != EOF) {
        putc(toupper(ch), fp_out);
        numberOfCharacters++;
    }
    return numberOfCharacters;
}
