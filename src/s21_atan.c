#include "s21_math.h"

long double s21_atan(double x) {
  long double s21_atan = 0;
  if (x == S21_INF) {
    s21_atan = S21_PI_2;
  } else if (x == -S21_INF) {
    s21_atan = -S21_PI_2;
  } else if (x != x) {
    s21_atan = S21_NAN;
  } else if (x == 0) {
    s21_atan = 0;
  } else if (x == -1) {
    s21_atan = -S21_PI_4;
  } else if (x == 1) {
    s21_atan = S21_PI_4;
  } else {
    if (s21_fabs(x) < 1) {
      for (long int i = 0; i < 300; i++) {
        s21_atan += (s21_pow(-1, i) * s21_pow(x, 1 + 2 * i)) / (1 + 2 * i);
      }
    } else if (s21_fabs(x) > 1) {
      for (long int i = 0; i < 300; i++) {
        s21_atan += (s21_pow(-1, i) * s21_pow(x, -1 - 2 * i)) / (1 + 2 * i);
      }
      s21_atan = ((S21_PI * s21_sqrt(x * x)) / (2 * x)) - s21_atan;
    }
  }

  return s21_atan;
}
