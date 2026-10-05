/*
 * Run-length compression / decompression of repeated characters.
 *
 * Format: a run of 3 or more identical characters  c c c c c   (5 times)
 *         is written as  c ! N   where N = (number of repetitions - 1),
 *         so one run holds at most 10 characters (N = 9).
 *         Runs of 1 or 2 characters are copied unchanged.
 *            "aaaaabbbcd"  ->  "a!4b!2cd"
 *
 * Files:  C : source.txt       -> compression.txt
 *         D : compression.txt  -> decompression.txt
 *
 * Limitation: the source text must not contain the '!' character.
 *
 * Exit codes: 0 ok, 1/3 error opening files (compress), 2/4 (decompress), 5 invalid choice.
 */
#include <stdio.h>

int compress(FILE *fin, FILE *fout);
int decompress(FILE *fin, FILE *fout);

int main(void) {
    FILE *f_read, *f_com, *f_dec;
    char choice;
    int numberOfCharacters = 0;

    printf("Compression(C) or Decompression(D): ");
    if (scanf(" %c", &choice) != 1) {
        printf("Error: invalid input.\n");
        return 5;
    }

    switch (choice) {
        case 'C':
            if ((f_read = fopen("source.txt", "r")) == NULL) {
                printf("Error: opening source file.\n");
                return 1;
            }
            if ((f_com = fopen("compression.txt", "w")) == NULL) {
                printf("Error: opening compression file.\n");
                fclose(f_read);
                return 3;
            }
            numberOfCharacters = compress(f_read, f_com);
            fclose(f_read);
            fclose(f_com);
            break;

        case 'D':
            if ((f_com = fopen("compression.txt", "r")) == NULL) {
                printf("Error: opening compression file.\n");
                return 4;
            }
            if ((f_dec = fopen("decompression.txt", "w")) == NULL) {
                printf("Error: opening decompression file.\n");
                fclose(f_com);
                return 2;
            }
            numberOfCharacters = decompress(f_com, f_dec);
            fclose(f_dec);
            fclose(f_com);
            break;

        default:
            printf("Error: invalid character.\n");
            return 5;
    }

    if (numberOfCharacters == 0)
        printf("No characters.\n");
    else
        printf("The number of characters written is: %d\n", numberOfCharacters);

    return 0;
}

/* Reads fin, writes the compressed text to fout, returns the characters written */
int compress(FILE *fin, FILE *fout) {
    int ch, ch1;                 /* int: so that EOF can be detected */
    int i, counter = 0, numberOfCharacters = 0;

    ch = getc(fin);
    while (ch != EOF) {
        ch1 = getc(fin);
        if (ch == ch1 && counter < 9) {
            counter++;                       /* same character: extend the run */
        } else {
            if (counter >= 2) {              /* run of 3+ : write  c!N */
                fprintf(fout, "%c!%d", ch, counter);
                numberOfCharacters += 3;
            } else {                         /* run of 1-2: copy as is */
                for (i = 0; i < counter + 1; i++) {
                    fputc(ch, fout);
                    numberOfCharacters++;
                }
            }
            counter = 0;
        }
        ch = ch1;
    }
    return numberOfCharacters;
}

/* Reads compressed text from fin, writes the original text to fout */
int decompress(FILE *fin, FILE *fout) {
    int ch, ch1;
    int i, counter, numberOfCharacters = 0;

    ch = getc(fin);
    while (ch != EOF) {
        ch1 = getc(fin);
        if (ch1 == '!') {
            int digit = getc(fin);
            if (digit == EOF) break;         /* malformed input */
            counter = digit - '0';
            for (i = 0; i < counter + 1; i++) {
                fputc(ch, fout);
                numberOfCharacters++;
            }
            ch = getc(fin);                  /* next run starts after the digit */
        } else {
            fputc(ch, fout);
            numberOfCharacters++;
            ch = ch1;
        }
    }
    return numberOfCharacters;
}
