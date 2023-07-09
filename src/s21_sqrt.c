#include "s21_math.h"

long double s21_sqrt(double x) {
  long double rez = 0;
  if (x > 0) {
    rez = s21_pow(x, 0.5);
  } else if (x == 0) {
    rez = 0;
  } else {
    rez = S21_NAN;
  }
  return rez;
}
