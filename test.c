#include <limits.h>
#include <stdio.h>
#include "utility.h"

int main(void) {
    printf("%s", "comp_equal(-1, INT_MAX) returns ");
    comp_equal(-1, INT_MAX) ? puts("true") : puts("false");

    printf("%s", "comp_equal(0, 0) returns ");
    comp_equal(0, 0) ? puts("true") : puts("false");

    printf("%s", "cmp_not_equal(-1, INT_MAX) returns ");
    cmp_not_equal(-1, INT_MAX) ? puts("true") : puts("false");

   printf("%s", "cmp_not_equal(0, 0) returns ");
   cmp_not_equal(0, 0) ? puts("true") : puts("false");

    printf("%s", "cmp_less(0, 0) returns ");
    cmp_less(0, 0) ? puts("true") : puts("false");

    printf("%s", "cmp_less(-1, 1) returns ");
    cmp_less(-1, 1) ? puts("true") : puts("false");

    printf("%s", "cmp_less(1, -1) returns ");
    cmp_less(1, -1) ? puts("true") : puts("false");

    printf("%s", "cmp_greater(0, 0) returns ");
    cmp_greater(0, 0) ? puts("true") : puts("false");

    printf("%s", "cmp_greater(-1, 1) returns ");
    cmp_greater(-1, 1) ? puts("true") : puts("false");

    printf("%s", "cmp_greater(1, -1) returns ");
    cmp_greater(1, -1) ? puts("true") : puts("false");

    printf("%s", "cmp_less_equal(0, 0) returns ");
    cmp_less_equal(0, 0) ? puts("true") : puts("false");

    printf("%s", "cmp_less_equal(-1, 1) returns ");
    cmp_less_equal(-1, 1) ? puts("true") : puts("false");

    printf("%s", "cmp_less_equal(1, -1) returns ");
    cmp_less_equal(1, -1) ? puts("true") : puts("false"); 

    printf("%s", "cmp_greater_equal(0, 0) returns ");
    cmp_greater_equal(0, 0) ? puts("true") : puts("false");

    printf("%s", "cmp_greater_equal(-1, 1) returns ");
    cmp_greater_equal(-1, 1) ? puts("true") : puts("false");

    printf("%s", "cmp_greater_equal(1, -1) returns ");
    cmp_greater_equal(1, -1) ? puts("true") : puts("false");      
}
