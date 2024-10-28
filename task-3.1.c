#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/**
* @brief get_y считает значение y
* @param x параметр x
* @return значение y
*/
double get_y(const double x);

/**
* @brief input Считывает вещественное число
* @return Возвращает вещественное число
*/
double input(void);

int main(void)
{

	puts("Введите начальное значение x:");

	double x1 = input();

	puts("Введите значение конечного x:");

	double x2 = input();

	puts("Введите значение шага:");

	double h = input();

	for (x1; x1 <= x2; x1 += h)
	{

		printf(" y = %lf\n", get_y(x1));
	}

}

double input(void) {

	double number = 0;

	if (scanf_s("%lf", &number) != 1)
	{
		puts("Ваш ввод некорректен");

		exit(EXIT_FAILURE);
	}

	return number;
}

double get_y(const double x)
{

	return sin(log(x)) - cos(log(x)) + 2 * log(x);
}
