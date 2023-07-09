#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(test_abs) {
  int inf_max = 1.0 / 0.0;
  int inf_min = -1.0 / 0.0;
  int nan_max = 0.0 / 0.0;

  ck_assert_int_eq(s21_abs(nan_max), abs(nan_max));
  ck_assert_int_eq(s21_abs(inf_min), abs(inf_min));
  ck_assert_int_eq(s21_abs(inf_max), abs(inf_max));

  ck_assert_int_eq(s21_abs(-0), abs(-0));
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(10), abs(10));
  ck_assert_int_eq(s21_abs(-10), abs(-10));
}
END_TEST

START_TEST(test_acos) {
  ck_assert_ldouble_nan(s21_acos(S21_NAN));
  ck_assert_ldouble_infinite(s21_acos(S21_MIN_INF));
  ck_assert_ldouble_infinite(s21_acos(S21_INF));

  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_acos(-0), acos(-0), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_acos(0.5), acos(0.5), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_acos(-0.5), acos(-0.5), S21_MIN_TEST);
}
END_TEST

START_TEST(test_asin) {
  ck_assert_ldouble_nan(s21_asin(S21_NAN));
  ck_assert_ldouble_nan(s21_asin(S21_MIN_INF));
  ck_assert_ldouble_nan(s21_asin(S21_INF));

  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_asin(-0), asin(-0), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_asin(0.5), asin(0.5), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_asin(-0.5), asin(-0.5), S21_MIN_TEST);
}
END_TEST

START_TEST(test_atan) {
  ck_assert_ldouble_nan(s21_atan(S21_NAN));

  ck_assert_ldouble_eq_tol(s21_atan(S21_INF), atan(S21_INF), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(S21_MIN_INF), atan(S21_MIN_INF), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_atan(-0), atan(-0), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_atan(0.1), atan(0.1), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_atan(-0.1), atan(-0.1), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_atan(-0.889), atan(-0.889), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_atan(0.5), atan(0.5), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_atan(-0.5), atan(-0.5), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_atan(2.5), atan(2.5), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_atan(-2.5), atan(-2.5), S21_MIN_TEST);
}
END_TEST

START_TEST(test_ceil) {
  ck_assert_ldouble_nan(s21_ceil(S21_NAN));

  ck_assert_ldouble_infinite(s21_ceil(S21_MIN_INF));
  ck_assert_ldouble_infinite(s21_ceil(S21_INF));

  ck_assert_ldouble_eq_tol(s21_ceil(0), ceil(0), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_ceil(-0), ceil(-0), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_ceil(1), ceil(1), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_ceil(-1), ceil(-1), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_ceil(0.542313545), ceil(0.542313545),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_ceil(-5.12121), ceil(-5.12121), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_ceil(1.45432132), ceil(1.45432132),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_ceil(-1.1212411), ceil(-1.121241), S21_MIN_TEST);
}
END_TEST

START_TEST(test_cos) {
  ck_assert_ldouble_nan(s21_cos(S21_NAN));
  ck_assert_ldouble_nan(s21_cos(S21_MIN_INF));
  ck_assert_ldouble_nan(s21_cos(S21_INF));

  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_cos(-0), cos(-0), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_cos(-1), cos(-1), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_cos(-1.732050808), cos(-1.732050808),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_cos(-0.577350269), cos(-0.577350269),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_cos(0.577350269), cos(0.577350269),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_cos(1.732050808), cos(1.732050808),
                           S21_MIN_TEST);
}
END_TEST

START_TEST(test_exp) {
  ck_assert_ldouble_nan(s21_exp(S21_NAN));
  ck_assert_ldouble_infinite(s21_exp(S21_INF));

  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_exp(-0), exp(-0), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_exp(1), exp(1), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_exp(-1), exp(-1), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_exp(-1.732050808), exp(-1.732050808),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_exp(-0.577350269), exp(-0.577350269),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_exp(0.577350269), exp(0.577350269),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_exp(1.732050808), exp(1.732050808),
                           S21_MIN_TEST);
}
END_TEST

START_TEST(test_fabs) {
  ck_assert_ldouble_nan(s21_fabs(S21_NAN));

  ck_assert_ldouble_infinite(s21_fabs(S21_MIN_INF));
  ck_assert_ldouble_infinite(s21_fabs(S21_INF));

  ck_assert_ldouble_eq_tol(s21_fabs(0.542313545), fabs(0.542313545),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_fabs(-5.12121), fabs(-5.12121), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_fabs(1.45432132), fabs(1.45432132),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_fabs(-1.1212411), fabs(-1.121241), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_fabs(1.0), fabs(1.0), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_fabs(-1.0), fabs(-1.0), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_fabs(4545.42423), fabs(4545.42423),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_fabs(1.0e-300), fabs(1.0e-300), S21_MIN_TEST);
}
END_TEST

START_TEST(test_floor) {
  ck_assert_ldouble_nan(s21_floor(S21_NAN));

  ck_assert_ldouble_infinite(s21_floor(S21_MIN_INF));
  ck_assert_ldouble_infinite(s21_floor(S21_INF));

  ck_assert_ldouble_eq_tol(s21_floor(0.542313545), floor(0.542313545),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_floor(-5.12121), floor(-5.12121), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_floor(1.45432132), floor(1.45432132),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_floor(-1.1212411), floor(-1.121241),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_floor(1.0), floor(1.0), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_floor(-1.0), floor(-1.0), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_floor(4545.42423), floor(4545.42423),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_floor(1.0e-300), floor(1.0e-300), S21_MIN_TEST);
}
END_TEST

START_TEST(test_fmod) {
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_NAN));
  ck_assert_ldouble_eq_tol(s21_fmod(2.99, S21_MIN_INF), fmod(2.99, S21_MIN_INF),
                           S21_MAX_TEST);
  ck_assert_ldouble_nan(s21_fmod(S21_MIN_INF, S21_MIN_INF));
  ck_assert_ldouble_nan(s21_fmod(S21_INF, S21_INF));

  ck_assert_ldouble_eq_tol(s21_fmod(0.542313545, 0.343),
                           fmod(0.542313545, 0.343), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_fmod(-5.12121, 2.43), fmod(-5.12121, 2.43),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_fmod(1.45432132, 0.12), fmod(1.45432132, 0.12),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_fmod(-1.1212411, -0.034),
                           fmod(-1.121241, -0.034), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_fmod(1.0, 0.4), fmod(1.0, 0.4), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_fmod(-1.0, 0.45), fmod(-1.0, 0.45),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_fmod(4545.42423, 12.34324),
                           fmod(4545.42423, 12.34324), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_fmod(1.0e-300, 0.3334), fmod(1.0e-300, 0.3334),
                           S21_MIN_TEST);
}
END_TEST

START_TEST(test_log) {
  ck_assert_ldouble_nan(s21_log(S21_NAN));
  ck_assert_ldouble_nan(s21_log(S21_MIN_INF));
  ck_assert_ldouble_infinite(s21_log(S21_INF));

  ck_assert_ldouble_infinite(s21_log(0));
  ck_assert_ldouble_infinite(s21_log(-0));
  ck_assert_ldouble_eq_tol(s21_log(1), log(1), S21_MIN_TEST);
  ck_assert_ldouble_nan(s21_log(-1));
  ck_assert_ldouble_eq_tol(s21_log(1.732050808), log(1.732050808),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_log(0.577350269), log(0.577350269),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_log(5.34), log(5.34), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_log(0.999999), log(0.999999), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_log(3.99), log(3.99), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_log(7.57), log(7.57), S21_MIN_TEST);
}
END_TEST

START_TEST(test_pow) {
  ck_assert_ldouble_nan(s21_pow(S21_NAN, 0.343));
  ck_assert_ldouble_nan(s21_pow(0.343, S21_NAN));

  ck_assert_ldouble_infinite(s21_pow(S21_INF, S21_INF));
  ck_assert_ldouble_eq_tol(s21_pow(S21_MIN_INF, S21_MIN_INF),
                           pow(S21_MIN_INF, S21_MIN_INF), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_pow(1, S21_INF), pow(1, S21_INF), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_pow(1, S21_MIN_INF), pow(1, S21_MIN_INF),
                           S21_MIN_TEST);

  ck_assert_ldouble_eq_tol(s21_pow(2.54, 0), pow(2.54, 0), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_pow(0.542313545, 0.343), pow(0.542313545, 0.343),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_pow(5.12121, 2.43), pow(5.12121, 2.43),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_pow(1.45432132, 0.12), pow(1.45432132, 0.12),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_pow(1.1212411, -0.034), pow(1.121241, -0.034),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_pow(-2, -1), pow(-2, -1), S21_MIN_TEST);
  ck_assert_double_eq_tol(s21_pow(-1, -2), pow(-1, -2), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_pow(45.42423, 2.34324), pow(45.42423, 2.34324),
                           S21_MIN_TEST);
}
END_TEST

START_TEST(test_sin) {
  ck_assert_ldouble_nan(s21_sin(S21_NAN));
  ck_assert_ldouble_nan(s21_sin(S21_MIN_INF));
  ck_assert_ldouble_nan(s21_sin(S21_INF));

  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_sin(-0), sin(-0), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_sin(-1), sin(-1), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_sin(-1.732050808), sin(-1.732050808),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_sin(-0.577350269), sin(-0.577350269),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_sin(0.577350269), sin(0.577350269),
                           S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_sin(1.732050808), sin(1.732050808),
                           S21_MIN_TEST);
}
END_TEST

START_TEST(test_sqrt) {
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
  ck_assert_ldouble_nan(s21_sqrt(S21_MIN_INF));
  ck_assert_ldouble_infinite(s21_sqrt(S21_INF));

  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_sqrt(-0), sqrt(-0), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), S21_MIN_TEST);
  ck_assert_ldouble_nan(s21_sqrt(-1));
  ck_assert_ldouble_eq_tol(s21_sqrt(0.542313545), sqrt(0.542313545),
                           S21_MIN_TEST);
  ck_assert_ldouble_nan(s21_sqrt(-5.12121));
  ck_assert_ldouble_eq_tol(s21_sqrt(1.45432132), sqrt(1.45432132),
                           S21_MIN_TEST);
  ck_assert_ldouble_nan(s21_sqrt(-1.1212411));
}
END_TEST

START_TEST(test_tan) {
  ck_assert_ldouble_nan(s21_tan(S21_NAN));

  ck_assert_ldouble_nan(s21_tan(S21_INF));
  ck_assert_ldouble_nan(s21_tan(S21_MIN_INF));
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_tan(-0), tan(-0), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_tan(-1), tan(-1), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_tan(0.1), tan(0.1), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_tan(-0.1), tan(-0.1), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_tan(0.5), tan(0.5), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_tan(-0.5), tan(-0.5), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_tan(2.5), tan(2.5), S21_MIN_TEST);
  ck_assert_ldouble_eq_tol(s21_tan(-2.5), tan(-2.5), S21_MIN_TEST);
}
END_TEST

int main(void) {
  Suite *suite = suite_create("COLLECTION"); // test suite - это набор тестов
  TCase *tcase = tcase_create("TESTS"); // test case — это конкретный тест кейс
  SRunner *srunner = srunner_create(suite);

  int result = 0;

  suite_add_tcase(suite, tcase);
  tcase_add_test(tcase, test_abs);
  tcase_add_test(tcase, test_acos);
  tcase_add_test(tcase, test_asin);
  tcase_add_test(tcase, test_atan);
  tcase_add_test(tcase, test_ceil);
  tcase_add_test(tcase, test_cos);
  tcase_add_test(tcase, test_exp);
  tcase_add_test(tcase, test_fabs);
  tcase_add_test(tcase, test_floor);
  tcase_add_test(tcase, test_fmod);
  tcase_add_test(tcase, test_log);
  tcase_add_test(tcase, test_pow);
  tcase_add_test(tcase, test_sin);
  tcase_add_test(tcase, test_sqrt);
  tcase_add_test(tcase, test_tan);

  srunner_run_all(srunner, CK_NORMAL);
  result = srunner_ntests_failed(srunner);

  srunner_free(srunner); // чистка памяти srunner

  return result == 0 ? 0 : 1;
}
