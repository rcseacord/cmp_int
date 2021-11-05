# cmp_int
C implementation of C++ Utility functions https://en.cppreference.com/w/cpp/utility/intcmp

## `cmp_equal`, `cmp_not_equal`, `cmp_less`, `cmp_greater`, `cmp_less_equal`, `cmp_greater_equal`

In the synopses in this subclause, integer indicates that the argument shall be an expression of real integer type.

```
bool cmp_equal(integer lhs, integer rhs);
bool cmp_not_equal(integer lhs, integer rhs);
bool cmp_less(integer lhs, integer rhs);
bool cmp_greater(integer lhs, integer rhs);
bool cmp_less_equal(integer lhs, integer rhs);
bool cmp_greater_equal(integer lhs, integer rhs);
```

Compare the values of two integers `lhs` and `rhs`. Unlike builtin comparison operators, negative signed integers always compare "less than" (and "not equal to") unsigned integers: the comparison is safe against lossy integer conversion.

```
-1 > 0u; // true
std::cmp_greater(-1, 0u); // false
```
 
It is a compile-time error if either `lhs` or `rhs` is not a signed or unsigned integer type (including standard integer type and extended integer type).

## Parameters
`lhs` - left-hand argument

`rhs` - right-hand argument

## Return value
1 `true` if `lhs` is equal to `rhs`.

2 `true` if `lhs` is not equal to `rhs`.

3 `true` if `lhs` is less than `rhs`.

4 `true` if `lhs` is greater than `rhs`.

5 `true` if `lhs` is less or equal to `rhs`.

6 `true` if `lhs` is greater or equal to `rhs`.
