#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <float.h>
#include <stdio.h>

#define S21_EPS 1e-15
#define S21_MIN_TEST 0.000001
#define S21_MAX_TEST 9999999999999999.0
#define S21_E 2.7182818284590452354
#define S21_PI 3.14159265358979323846
#define S21_PI_2 1.57079632679
#define S21_PI_3 1.0471975512
#define S21_PI_4 0.7853981633
#define S21_PI_6 0.5235987755

#define S21_NAN 0.0 / 0.0
#define S21_INF 1.0 / 0.0
#define S21_MIN_INF -1.0 / 0.0
#define S21_IS_NAN(x) __builtin_isnan(x)
#define S21_IS_INF(x) __builtin_isinf_sign(x)
#define S21_DOUBLE_MAX 1.7976931348623157E+308

int s21_abs(int x);                           // 1 OK
long double s21_acos(double x);               // 2 OK
long double s21_asin(double x);               // 3 OK
long double s21_atan(double x);               // 4 OK
long double s21_ceil(double x);               // 5 OK
long double s21_cos(double x);                // 6 OK
long double s21_exp(double x);                // 7 OK
long double s21_fabs(double x);               // 8 OK
long double s21_floor(double x);              // 9 OK
long double s21_fmod(double x, double y);     // 10 OK
long double s21_log(double x);                // 11 OK
long double s21_pow(double base, double exp); // 12 OK
long double s21_sin(double x);                // 13 OK
long double s21_sqrt(double x);               // 14 OK
long double s21_tan(double x);                // 15 OK

#endif
