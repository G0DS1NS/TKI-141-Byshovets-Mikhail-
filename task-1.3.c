
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
* @brief is Number проверяет меньше число нуля или нет
* @param number число
* @return возвращает true, если больше 0 и fasle, если меньше или равен 0
*/
bool isNumber(const double number);

/*
* @brief функция main выводит значение t, исходя из значений Q и m
* @param Q отдаваемая энергия
* @param m масса ложки
* @return возвращает 0 в случае успеха
*/
int main() {

  puts("Введите значение Q:");

  double Q = input();

  puts("Введите значение m:");

  double m = input();

  printf("t = %f\n", get_t(Q, m));
}

double input(void) {

  double number;

  if (scanf_s("%lf", &number) != 1 || !isNumber(number)) {

    puts("Значение не может быть меньше нуля");

    exit(EXIT_FAILURE);
  }

  return number;

}

double get_t(const double Q, const double m) {

  const double c = 462;

  return Q / (c * m);
}

bool isNumber(const double number){
  return number > 0;
}
