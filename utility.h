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

#ifndef UTILITY_H
#define UTILITY_H

#define is_integer(x) (_Generic((x), \
                         default: 0, \
                         signed char: 1, \
                         signed short: 1, \
                         signed int: 1, \
                         signed long: 1, \
                         signed long long: 1, \
                         unsigned char: 1, \
                         unsigned short: 1, \
                         unsigned int: 1, \
                         unsigned long: 1, \
                         unsigned long long: 1))

#define is_signed(x) (_Generic((x), \
                         default: 0, \
                         signed char: 1, \
                         signed short: 1, \
                         signed int: 1, \
                         signed long: 1, \
                         signed long long: 1))

#define make_unsigned(x) (_Generic((x), \
                         default: (x), \
                         signed char: ((unsigned char)x), \
                         signed short: ((unsigned short)x), \
                         signed int: ((unsigned int)x), \
                         signed long: ((unsigned long)x), \
                         signed long long: (unsigned long long)x))

#define check_types(lhs, rhs) \
  _Static_assert(is_integer(lhs), "lhs must be an integer"); \
  _Static_assert(is_integer(rhs), "rhs must be an integer");

#define comp_equal(lhs, rhs) ({                      \
  check_types(lhs, rhs);                             \
  int res = 0;                                       \
  if (is_signed(lhs) == is_signed(rhs))              \
    res = lhs == rhs;                                \
  else if (is_signed(lhs))                           \
    res = lhs < 0 ? 0 : make_unsigned(lhs) == rhs;   \
  else                                               \
    res = rhs < 0 ? 0 : lhs == make_unsigned(rhs);   \
  res;                                               \
})

#define cmp_not_equal(lhs, rhs) !comp_equal(lhs, rhs)
 
#define cmp_less(lhs, rhs) ({                        \
  check_types(lhs, rhs);                             \
  int res = 0;                                       \
  if (is_signed(lhs) == is_signed(rhs))              \
    res = lhs < rhs;                                 \
  else if (is_signed(lhs))                           \
    res = lhs < 0 ? 1 : make_unsigned(lhs) < rhs;    \
  else                                               \
    res = rhs < 0 ? 0 : lhs < make_unsigned(rhs);    \
  res;                                               \
})

#define cmp_greater(lhs, rhs) cmp_less(rhs, lhs)
#define cmp_less_equal(lhs, rhs) !cmp_greater(lhs, rhs)
#define cmp_greater_equal(lhs, rhs) !cmp_less(lhs, rhs)

#endif /* UTILITY_H */
