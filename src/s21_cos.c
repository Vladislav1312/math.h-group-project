#include "s21_math.h"

long double s21_cos(double x) {
  double sum = 0.;
  if (x == S21_NAN || x == S21_INF || x == -S21_INF) {
    sum = S21_NAN;
  } else {
    sum = s21_sin(S21_PI_2 - x);
  }
  return sum;
}