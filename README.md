# Integer Comparison Macros
C implementation of C++ Utility functions https://en.cppreference.com/w/cpp/utility/intcmp

## `cmp_equal`, `cmp_not_equal`, `cmp_less`, `cmp_greater`, `cmp_less_equal`, `cmp_greater_equal`

In the synopses in this subclause, integer indicates that the argument shall be an expression of real integer type.

```c
bool cmp_equal(integer lhs, integer rhs);
bool cmp_not_equal(integer lhs, integer rhs);
bool cmp_less(integer lhs, integer rhs);
bool cmp_greater(integer lhs, integer rhs);
bool cmp_less_equal(integer lhs, integer rhs);
bool cmp_greater_equal(integer lhs, integer rhs);
```

Compare the values of two integers `lhs` and `rhs`. Unlike builtin comparison operators, negative signed integers always compare "less than" (and "not equal to") unsigned integers: the comparison is safe against lossy integer conversion.

```c
-1 > 0u; // true
std::cmp_greater(-1, 0u); // false
```
 
It is a compile-time error if either `lhs` or `rhs` is not a signed or unsigned integer type (including standard integer type and extended integer type):

```c
cmp_greater_equal(1.0, -1.0) ? puts("true") : puts("false"); // doesn't compile
cmp_greater((char)-1, (char)1) ? puts("true") : puts("false"); // doesn't compile
```

## Parameters
`lhs` - left-hand argument

`rhs` - right-hand argument

## Return value

`cmp_equal` returns `true` if `lhs` is equal to `rhs`.

`cmp_not_equal` returns `true` if `lhs` is not equal to `rhs`.

`cmp_less` returns `true` if `lhs` is less than `rhs`.

`cmp_greater` returns `true` if `lhs` is greater than `rhs`.

`cmp_less_equal` returns `true` if `lhs` is less or equal to `rhs`.

`cmp_greater_equal` returns `true` if `lhs` is greater or equal to `rhs`.
