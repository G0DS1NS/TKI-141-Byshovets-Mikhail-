#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>


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

/**
* @brief is_positive проверяет число на положительность
* @param h параметр h
* @return возвращает true, если h больше 0 и false, если h меньше или равен 0
*/
bool is_positive(const int h);

int main(void)
{

	puts("Введите начальное значение x:");

	double x1 = input();

	puts("Введите значение конечного x:");

	double x2 = input();

	puts("Введите значение шага:");

	double h = input();

	double start = x1;

	for (start; start <= x2 + DBL_EPSILON; start += h)
	{

		printf("x = %lf y = %lf\n", start, get_y(start));
	}

	return 0;

}

double input(void) {

	double number = 0;

	if (scanf_s("%lf", &number) != 1 || !is_positive(number))
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

bool is_positive(const int h)
{
	return h > 0;
}
