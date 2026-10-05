/*
 * <ctype.h> character classification.
 *
 * Each function receives ONE character (a single-quoted value such as 'A'),
 * never a whole string such as '32.50' - that is a multi-character constant
 * and is NOT a valid char. To test a string, test it character by character.
 *
 * Note: cast to (unsigned char) before calling the ctype functions, so that
 * negative char values never reach them (undefined behaviour).
 */
#include <stdio.h>
#include <ctype.h>

static void classify(char c) {
    unsigned char u = (unsigned char)c;
    printf("'%c' ->", c);
    if (isdigit(u)) printf(" digit");
    if (isalpha(u)) printf(" alpha");
    if (isalnum(u)) printf(" alnum");
    if (isupper(u)) printf(" upper");
    if (islower(u)) printf(" lower");
    if (isspace(u)) printf(" space");
    if (ispunct(u)) printf(" punct");
    printf("\n");
}

static void countClasses(const char *s) {
    int digits = 0, letters = 0, others = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit((unsigned char)s[i]))      digits++;
        else if (isalpha((unsigned char)s[i])) letters++;
        else                                   others++;
    }
    printf("\"%s\": %d digit(s), %d letter(s), %d other\n", s, digits, letters, others);
}

int main(void) {
    char grade = '5';
    if (isdigit((unsigned char)grade)) printf("digit\n");

    char grade2 = 'A';
    if (isalnum((unsigned char)grade2)) printf("alnum\n");
    if (isupper((unsigned char)grade2)) printf("upper\n");

    char grade3 = 's';
    if (islower((unsigned char)grade3)) printf("lower\n");

    char grade4 = 'r';
    if (isalpha((unsigned char)grade4)) printf("alpha\n");

    printf("\nFull classification:\n");
    const char samples[] = {'3', 'A', 's', '?', ' '};
    for (size_t i = 0; i < sizeof(samples) / sizeof(samples[0]); i++)
        classify(samples[i]);

    printf("\nStrings, character by character:\n");
    countClasses("32.50");
    countClasses("12reis");

    return 0;
}
