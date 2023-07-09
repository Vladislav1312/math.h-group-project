#include "s21_math.h"

long double s21_fabs(double x) {
  long double res = x;
  if (S21_IS_NAN(x))
    res = S21_NAN;
  if (x < 0)
    res *= -1;
  return res;
}
