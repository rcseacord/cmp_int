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

#ifndef CMP_INT_H
#define CMP_INT_H

// Define the CMP_INT_WANT_PORTABLE macro to 1 to get the most portable
// implementation of these facilities. This portability comes at a cost though:
// compiler extensions are what protect against unintended duplicate side
// effects in the macro expansion. For this reason, the macro defaults to
// requesting the nonportable interfaces.
#ifndef CMP_INT_WANT_PORTABLE
#define CMP_INT_WANT_PORTABLE 0
#endif // CMP_INT_WANT_PORTABLE

#define is_supported_type(x) (_Generic((x), \
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

#define check(val, which)                                                      \
  _Static_assert(                                                              \
      is_supported_type(val), which                                            \
      " is not a supported type: must be an integer other than bool or char")

#if CMP_INT_WANT_PORTABLE
#define cmp_equal(lhs, rhs) \
  ((_Bool)((void)sizeof(struct { check(lhs, "lhs"); int d; check(rhs, "rhs"); }),\
    (is_signed(lhs) == is_signed(rhs) ? (lhs) == (rhs) : \
    is_signed(lhs) ? \
      (lhs) >= 0 && make_unsigned(lhs) == (rhs) : \
      ((rhs) >= 0 && (lhs) == make_unsigned(rhs)))))

#define cmp_less(lhs, rhs) \
  ((_Bool)((void)sizeof(struct { check(lhs, "lhs"); int d; check(rhs, "rhs"); }),\
  (is_signed(lhs) == is_signed(rhs) ? (lhs) < (rhs) : \
    is_signed(lhs) ? \
      (lhs) < 0 || make_unsigned(lhs) < (rhs) : \
      ((rhs) >= 0 && (lhs) < make_unsigned(rhs)))))
#else
#define cmp_equal(lhs, rhs)                                                    \
  ({                                                                           \
    __typeof__(lhs) lhs_val = lhs;                                             \
    __typeof__(rhs) rhs_val = rhs;                                             \
    check(lhs_val, "lhs");                                                     \
    check(rhs_val, "rhs");                                                     \
    int res = 0;                                                               \
    if (is_signed(lhs_val) == is_signed(rhs_val))                              \
      res = (lhs_val) == (rhs_val);                                            \
    else if (is_signed(lhs_val))                                               \
      res = (lhs_val) < 0 ? 0 : make_unsigned(lhs_val) == (rhs_val);           \
    else                                                                       \
      res = (rhs_val) < 0 ? 0 : (lhs_val) == make_unsigned(rhs_val);           \
    res;                                                                       \
  })

#define cmp_less(lhs, rhs)                                                     \
  ({                                                                           \
    __typeof__(lhs) lhs_val = lhs;                                             \
    __typeof__(rhs) rhs_val = rhs;                                             \
    check(lhs_val, "lhs");                                                     \
    check(rhs_val, "rhs");                                                     \
    int res = 0;                                                               \
    if (is_signed(lhs_val) == is_signed(rhs_val))                              \
      res = (lhs_val) < (rhs_val);                                             \
    else if (is_signed(lhs_val))                                               \
      res = (lhs_val) < 0 ? 1 : make_unsigned(lhs_val) < (rhs_val);            \
    else                                                                       \
      res = (rhs_val) < 0 ? 0 : (lhs_val) < make_unsigned(rhs_val);            \
    res;                                                                       \
  })
#endif // CMP_INT_WANT_PORTABLE

#define cmp_not_equal(lhs, rhs) ((_Bool)!cmp_equal(lhs, rhs))
#define cmp_greater(lhs, rhs) ((_Bool)cmp_less(rhs, lhs))
#define cmp_less_equal(lhs, rhs) ((_Bool)!cmp_greater(lhs, rhs))
#define cmp_greater_equal(lhs, rhs) ((_Bool)!cmp_less(lhs, rhs))

#endif /* CMP_INT_H */
