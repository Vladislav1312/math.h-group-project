#include "s21_math.h"

long double s21_ceil(double x) {
  long double res = 0;
  if (S21_IS_NAN(x))
    res = S21_NAN;
  else if (S21_IS_INF(x) && x > 0.)
    res = S21_INF;
  else if (S21_IS_INF(x) && x < 0.)
    res = -S21_INF;
  else if (x != 0) {
    res = (long long int)x;
    if (x > 0. && x != res)
      res += 1;
  }
  return res;
}
