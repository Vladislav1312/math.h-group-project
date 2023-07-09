#include "s21_math.h"

long double s21_log(double x) {
  int count = 0;
  long double res = 0;
  double com = 0;

  if (x == 0) {
    res = -S21_INF;
  } else if (S21_IS_INF(x) && x > 0) {
    res = S21_INF;
  } else if (x == 1) {
    res = 0.0;
  } else if (x < 0.0 || S21_IS_NAN(x) || (S21_IS_INF(x) && x < 0)) {
    res = S21_NAN;
  } else {
    for (; x > S21_E; x /= S21_E, count++)
      continue;
    for (int i = 0; i < 200; i++) {
      com = res;
      res = com + 2 * (x - s21_exp(com)) / (x + s21_exp(com));
    }
    res += count;
  }
  return res;
}
