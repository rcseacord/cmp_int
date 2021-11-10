//==-----------------------------------------------------------------------===//
//
// MIT License
//
// Copyright(c) 2021 Robert C.Seacord & Aaron Ballman
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this softwareand associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright noticeand this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//===----------------------------------------------------------------------===//

#include <limits.h>
#include <stdio.h>
#include "cmp_int.h"

int main(void) {
    printf("%s", "cmp_equal(-1, INT_MAX) returns ");
    cmp_equal(-1, INT_MAX) ? puts("true") : puts("false");

    printf("%s", "cmp_equal(0, 0) returns ");
    cmp_equal(0, 0) ? puts("true") : puts("false");
    
    printf("%s", "cmp_equal(-5, (unsigned)5) returns ");
    puts(cmp_equal(-5, (unsigned)5) ? "true" : "false");
    
    printf("%s", "cmp_equal(1 || 1, 0) returns ");
    puts(cmp_equal(1 || 1, 0) ? "true" : "false");
    
    printf("%s", "cmp_equal(1 ^ 1, 0) returns ");
    puts(cmp_equal(1 ^ 1, 0) ? "true" : "false");

    printf("%s", "cmp_not_equal(-1, INT_MAX) returns ");
    cmp_not_equal(-1, INT_MAX) ? puts("true") : puts("false");

    printf("%s", "cmp_not_equal(0, 0) returns ");
    cmp_not_equal(0, 0) ? puts("true") : puts("false");
    
    printf("%s", "cmp_not_equal(-5, (unsigned)5) returns ");
    puts(cmp_not_equal(-5, (unsigned)5) ? "true" : "false");

    printf("%s", "cmp_less(0, 0) returns ");
    cmp_less(0, 0) ? puts("true") : puts("false");

    printf("%s", "cmp_less(-1, 1) returns ");
    cmp_less(-1, 1) ? puts("true") : puts("false");

    printf("%s", "cmp_less(1, -1) returns ");
    cmp_less(1, -1) ? puts("true") : puts("false");
    
    printf("%s", "cmp_less(1 || 1, 0) returns ");
    puts(cmp_less(1 || 1, 0) ? "true" : "false");
    
    printf("%s", "cmp_less(1 && 1, 0) returns ");
    puts(cmp_less(1 && 1, 0) ? "true" : "false");

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

    // NOTE: this test case behaves differently depending on whether the
    // CMP_INT_WANT_PORTABLE macro is defined to 1 or not. If not defined or
    // defined to 0, this test will output:
    //   with i == 0, cmp_less_equal(i++, 0U) returns true and i is 1
    // but with CMP_INT_WANT_PORTABLE defined to 1, this test will output:
    //   with i == 0, cmp_less_equal(i++, 0U) returns false and i is 2
    int i = 0;
    printf("%s", "with i == 0, cmp_less_equal(i++, 0U) returns ");
    cmp_less_equal(i++, 0U) ? printf("true") : printf("false");
    printf(" and i is %d\n", i);

    if (cmp_equal(0, 0U))
        puts("use within an if condition behaves as expected");
    else if (cmp_less(0, 0U))
        puts("something has gone very, very wrong");
}
