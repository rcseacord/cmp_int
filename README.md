# cmp_int
C implementation of C++ Utility functions https://en.cppreference.com/w/cpp/utility/intcmp

{{cpp/title|cmp_equal, cmp_not_equal, cmp_less, cmp_greater, cmp_less_equal, cmp_greater_equal}}
{{cpp/utility/navbar}}

In the synopses in this subclause, integer indicates that the argument shall be an expression of real integer type.

{{dcl begin}}
{{dcl header | utility }}
{{dcl | num=1  | 1=
bool cmp_equal(integer lhs, integer rhs);
}}
{{dcl | num=2  | 1=
bool cmp_not_equal(integer lhs, integer rhs);
}}
{{dcl | num=3  | 1=
bool cmp_less(integer lhs, integer rhs);
}}
{{dcl | num=4  | 1=
bool cmp_greater(integer lhs, integer rhs);
}}
{{dcl | num=5 | 1=
bool cmp_less_equal(integer lhs, integer rhs);
}}
{{dcl | num=6 | 1=
bool cmp_greater_equal(integer lhs, integer rhs);
}}
{{dcl end}}

Compare the values of two integers {{tt|lhs}} and {{tt|rhs}}. Unlike builtin comparison operators, negative signed integers always compare ''less than'' (and ''not equal to'') unsigned integers: the comparison is safe against lossy integer conversion.

{{source|1=
-1 > 0u; // true
std::cmp_greater(-1, 0u); // false
}}
 
It is a compile-time error if either {{tt|T}} or {{tt|U}} is not a signed or unsigned integer type (including standard integer type and extended integer type).

===Parameters===
{{par begin}}
{{par | t | left-hand argument}}
{{par | u | right-hand argument}}
{{par end}}

===Return value===
@1@ {{c|true}} if {{tt|t}} is equal to {{tt|u}}.
@2@ {{c|true}} if {{tt|t}} is not equal to {{tt|u}}.
@3@ {{c|true}} if {{tt|t}} is less than {{tt|u}}.
@4@ {{c|true}} if {{tt|t}} is greater than {{tt|u}}.
@5@ {{c|true}} if {{tt|t}} is less or equal to {{tt|u}}.
@6@ {{c|true}} if {{tt|t}} is greater or equal to {{tt|u}}.
