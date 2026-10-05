/*
 * Array of structures.
 *
 *   char character = '...'     (single quotes -> one character)
 *   char string[20] = "..."    (double quotes -> string)
 */
#include <stdio.h>

struct color {
    char  name[10];
    char  grade;
    float gpa;
};

int main(void) {
    struct color color1 = {"blue",  'B', 2.231f};
    struct color color2 = {"green", 'G', 3.123f};
    struct color color3 = {"red",   'R', 2.90023f};
    struct color colors[] = {color1, color2, color3};

    int n = sizeof(colors) / sizeof(colors[0]);
    for (int i = 0; i < n; i++) {
        printf("Color name: %s, ", colors[i].name);
        printf("Grade: %c, ", colors[i].grade);
        printf("GPA: %.2f\n", colors[i].gpa);
    }
    return 0;
}
