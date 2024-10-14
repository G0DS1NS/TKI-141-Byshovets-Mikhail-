#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
* @brief input принимает на вход значение double, вводимое пользователем
* @return возвращает значение, введеное пользователем
*/
double input(void);

/*
* @bried get_answer выводин протабулированную функцию
* @param h параметр h, шаг
*/
void get_answer(const double h);

/*
* @brief get_summ считает сумму функционального ряда
* @param x параметр x
* @param n параметр n
* @return возвращает значение суммы фукнуционального ряда
*/
double get_summ(const double x, int n);

/*
* @brief factorial считает факториал числа
* @param x параметр x
* @return возвращает значение факториала числа
*/
int factorial(const double x);

/*
* @brief main принимает значение шага h и выводит аргумент функции, значение функции и сумму функионального ряда
* @return возращает 0 в случае успеха
*/
int main(void) {

	double x = 0.1;

	puts("Enter the h:");

	double h = input();

	printf("x\t\tcos(x)\t\tS\n");

	get_answer(h);

	return 0;
}

double input(void) {

	double number;

	if (scanf_s("%lf", &number) != 1) {

		puts("Your input is uncorrected");

		exit(EXIT_FAILURE);
	}

	return number;
}

int cnt_n_in_x_range(const double h) {

	int cnt = 0;

	for (double x = 0.1; x <= 1; x += h) {

		cnt += 1;
	}

	return cnt;
}

void get_answer(const double h) {


	int n = 1;

	for (double x = 0.1; x <= 1; x += h) {

		printf("%f\t%f\t%.4f\n", x, cos(x), get_summ(x, n));

		n += 1;
	}
}

int factorial(const double x) {

	int factorial_x = 1;

	for (int i = 1; i <= x; i++) {

		factorial_x *= i;
	}

	return factorial_x;
}


double get_summ(const double x, int n) {


	double first_summ = 1 - pow(x, 2) / factorial(x);

	return first_summ + pow(-1, n) * pow(x, 2 * n) / factorial(x);
}

