/*
 * Count runs of identical adjacent characters.
 *
 * Reads file.txt and writes fileWritten.txt with one line per run:
 *     <character>:<run length>
 * Example: "aaabcc"  ->  a:3  b:1  c:2
 *
 * Exit codes: 0 ok, 1 cannot open the input file, 3 cannot open the output file.
 */
#include <stdio.h>

/* Writes one run; control characters are shown as escape sequences */
static void writeRun(FILE *out, int ch, int counter) {
    switch (ch) {
        case '\n': fprintf(out, "\\n:%d\n", counter); break;
        case '\t': fprintf(out, "\\t:%d\n", counter); break;
        case '\r': fprintf(out, "\\r:%d\n", counter); break;
        case ' ':  fprintf(out, "' ':%d\n", counter); break;
        default:   fprintf(out, "%c:%d\n", ch, counter);
    }
}

int main(void) {
    FILE *fp_in, *fp_write;
    int numberOfCharacters = 0, counter = 1;
    int ch, ch1;                         /* int, so EOF can be detected */

    if ((fp_in = fopen("file.txt", "r")) == NULL) {
        printf("Error opening file (reading version).\n");
        return 1;
    }
    if ((fp_write = fopen("fileWritten.txt", "w")) == NULL) {
        printf("Error opening file (written version).\n");
        fclose(fp_in);
        return 3;
    }

    ch = getc(fp_in);
    if (ch != EOF) {
        numberOfCharacters = 1;
        while ((ch1 = getc(fp_in)) != EOF) {
            numberOfCharacters++;
            if (ch == ch1) {             /* '==' compares, '=' would assign */
                counter++;
            } else {
                writeRun(fp_write, ch, counter);
                ch = ch1;
                counter = 1;
            }
        }
        writeRun(fp_write, ch, counter); /* the last run is written after the loop */
    }

    fclose(fp_in);
    fclose(fp_write);

    printf("Characters read: %d (runs written to fileWritten.txt)\n", numberOfCharacters);
    return 0;
}
