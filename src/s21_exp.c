#include "s21_math.h"

long double s21_exp(double x) {
  long double fraction = 1.0; // Переменная дробей
  int i = 1;                  // Счётчик факториала
  long double res = 1.0; // Итоговый результат функции
  if (S21_IS_NAN(x)) {
    res = S21_NAN;
  } else if (S21_IS_INF(x) && x > 0.) {
    res = S21_INF;
  } else if ((S21_IS_INF(x) && x < 0.) || (x < -14.6)) {
    res = 0.0;
  } else {
    while (s21_fabs(fraction) > S21_EPS) { // Пока дробь > Заданной точности
      fraction *= x / i; // Увеличение значений в дроби
      res += fraction;
      i++;

      if (res > S21_DOUBLE_MAX) {
        res = x < 0. ? 0.0 : S21_INF;
        break;
      }
    }
  }
  return res;
}
