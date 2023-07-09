#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double rem_div = 0;
  if (y == 0 || (S21_IS_INF(x) && S21_IS_INF(y)) || S21_IS_NAN(x) ||
      S21_IS_NAN(y))
    return S21_NAN;
  else if (S21_IS_INF(y))
    return x;
  else {
    long long int res = x / y;
    rem_div = (long double)x - res * (long double)y;
    return rem_div;
  }
}
