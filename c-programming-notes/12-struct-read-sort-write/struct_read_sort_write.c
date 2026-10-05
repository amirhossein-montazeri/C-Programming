/*
 * Read an array of struct from a text file, sort it by GPA and write the
 * result to a second file.
 *
 * Input line format :  <first name> <last name> <gpa>
 *
 * Usage:  ./struct_read_sort_write [input_file] [output_file]
 *         (defaults: file.txt -> file2.txt)
 */
#include <stdio.h>

#define MAX_MASTERS 100

struct Master {
    char  fname[20];
    char  lname[20];
    float gpa;
};

static int read_file(const char *path, struct Master masters[], int *count) {
    FILE *fptr = fopen(path, "r");
    if (fptr == NULL) {
        printf("Error! Cannot open %s\n", path);
        return 1;
    }
    *count = 0;
    while (*count < MAX_MASTERS &&
           fscanf(fptr, "%19s %19s %f", masters[*count].fname,
                  masters[*count].lname, &masters[*count].gpa) == 3) {
        (*count)++;
    }
    fclose(fptr);
    return 0;
}

/* Bubble sort, ascending by gpa (use '<' instead of '>' for descending) */
static void sort_file(struct Master masters[], int count) {
    for (int k = 0; k < count - 1; k++) {
        for (int i = 0; i < count - k - 1; i++) {
            if (masters[i].gpa > masters[i + 1].gpa) {
                struct Master temp = masters[i];
                masters[i] = masters[i + 1];
                masters[i + 1] = temp;
            }
        }
    }
}

static int write_file(const char *path, struct Master masters[], int count) {
    FILE *fw = fopen(path, "w");
    if (fw == NULL) {
        printf("Error! Cannot open %s\n", path);
        return 1;
    }
    for (int i = 0; i < count; i++)
        fprintf(fw, "%s %s %.2f\n", masters[i].fname, masters[i].lname, masters[i].gpa);
    fclose(fw);
    return 0;
}

int main(int argc, char *argv[]) {
    const char *in  = argc > 1 ? argv[1] : "file.txt";
    const char *out = argc > 2 ? argv[2] : "file2.txt";

    struct Master masters[MAX_MASTERS];
    int count;

    if (read_file(in, masters, &count) != 0) return 1;
    sort_file(masters, count);
    if (write_file(out, masters, count) != 0) return 1;

    printf("%d record(s) read from %s, sorted by GPA, written to %s\n", count, in, out);
    return 0;
}
