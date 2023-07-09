#include "s21_math.h"

long double s21_acos(double x) {
  long double s21_acos = x;
  if (x >= 1 && x < -1) {
    s21_acos = S21_NAN;
  }
  if (x == -1) {
    s21_acos = S21_PI;
  }
  if (x == 0) {
    s21_acos = S21_PI_2;
  }
  if (x == 1) {
    s21_acos = 0;
  }
  if (x <= 1 && x >= -1) {
    s21_acos = S21_PI_2 - s21_asin(x);
  }
  return s21_acos;
}
