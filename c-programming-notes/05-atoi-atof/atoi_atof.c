/*
 * String / character -> number conversions.
 *
 *   atoi : string -> int      (<stdlib.h>)
 *   atof : string -> double   (<stdlib.h>)
 *   '5' - '0' : single digit character -> int (works because the digit
 *               characters '0'..'9' are consecutive in the ASCII table)
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char *str = "1234";
    printf("atoi(\"%s\") = %d\n", str, atoi(str));

    const char *str2 = "54.12";
    printf("atof(\"%s\") = %f\n", str2, atof(str2));

    /* literals work too */
    printf("atoi(\"5\")      = %d\n", atoi("5"));
    printf("atof(\"5.542\")  = %f\n", atof("5.542"));

    /* char -> int and char -> float */
    printf("'5' - '0'        = %d\n", '5' - '0');
    printf("(float)('5'-'0') = %f\n", (float)('5' - '0'));

    /* atoi/atof return 0 when nothing can be converted (no error reporting) */
    printf("atoi(\"abc\")    = %d\n", atoi("abc"));

    return 0;
}
