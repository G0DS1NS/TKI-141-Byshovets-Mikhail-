
#include <stdio.h>
#include <stdlib.h>

/*
* @brief функция input принимает вводимые значение
* @param number вводимое значение
* @return возвращает вводимое значение
*/

double input(void);

/*
* @brief функция get_t считает значение изменения температуры
* @param Q отдаваемая энергия
* @param m масса ложки
* @return возвращает значение изменения температуры
*/

double get_t(const double Q, const double m);

/*
* @brief функция main выводит значение t, исходя из значений Q и m
* @param Q отдаваемая энергия
* @param m масса ложки
* @return возвращает 0 в случае успеха
*/

int main() {
  
  double Q;

  double m;

  puts("Введите значение Q:");

  Q = input();

  puts("Введите значение m:");

  m = input();

  printf("t = %f\n", get_t(Q, m));
}

double input(void) {

  double number;

  if (scanf_s("%lf", &number) != 1 || number <= 0) {

    puts("Значение не может быть меньше нуля");

    exit(EXIT_FAILURE);
  }

  return number;

}

double get_t(const double Q, const double m) {

  const double c = 462;

  return Q / (c * m);
}