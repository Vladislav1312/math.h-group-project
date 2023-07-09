#include "s21_math.h"

long double s21_sin(double x) {
  double n = x;
  double sum = 0.;
  int i = 1;

  if (S21_IS_NAN(x)) {
    sum = S21_NAN;
  } else if (S21_IS_INF(x)) {
    sum = S21_NAN;
  } else {
    while (s21_fabs(n) > S21_EPS) {
      sum += n;
      n *= (-1.0 * x * x) / ((2 * i + 1) * (2 * i));
      i++;
    }
  }
  return sum;
}