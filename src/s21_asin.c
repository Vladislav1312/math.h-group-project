#include "s21_math.h"

long double s21_asin(double x) {
  long double s21_asin = x;
  if (x == S21_NAN) {
    s21_asin = S21_NAN;
  }
  if (S21_IS_INF(x)) {
    s21_asin = S21_INF;
  }
  if (x < -1 || x > 1) {
    s21_asin = S21_NAN;
  }
  if (x == -1) {
    s21_asin = (S21_PI_2) * -1;
  }
  if (x == 1) {
    s21_asin = (S21_PI_2);
  }
  if (x == 0) {
    s21_asin = 0;
  }

  if (x < 1 && x > -1) {
    s21_asin = s21_atan(x / s21_sqrt(1 - x * x));
  }
  return s21_asin;
}
