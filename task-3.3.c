#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/*
* @brief input принимает на вход значение double, вводимое пользователем
* @return возвращает значение, введеное пользователем
*/
double input(void);

/*
* @bried get_answer выводин протабулированную функцию
* @param h параметр h, шаг
*/
void get_answer(const double h, double x1, const double x2);

/*
* @brief get_summ считает сумму функционального ряда
* @param x параметр x
* @param n параметр n
* @return возвращает значение суммы фукнуционального ряда
*/
double get_summ(const double x, const int n);

/**
* @brief count_n_in_x_range
* @param h параметр h
* @return возвращает количество шагов h в диапазоне x
*/
int count_n_in_x_range(const double h);

/**
* @brief is_h проверяет значение h на правильность ввода
* @param h параметр h
* @return возращает true, если h больше 0 и false, если нет
*/
bool is_h(const double h);

/*
* @brief main принимает значение шага h и выводит аргумент функции, значение функции и сумму функионального ряда
* @return возращает 0 в случае успеха
*/
int main(void) {
	pust("Enter the x1:");

	double x1 = input();

	puts("Enter the x2:");

	double x2 = input();

	puts("Enter the h:");

	double h = input();

	if(is_h(h){

		printf("x\t\tcos(x)\t\tS\n");
		
		get_answer(h);

	        return 0;

        }

        puts("h is incorrected")
	return 1;
}

double input(void) {

	double number = 0;

	if (scanf_s("%lf", &number) != 1) {

		puts("Your input is uncorrected");

		exit(EXIT_FAILURE);
	}

	return number;
}

int count_n_in_x_range(const double h) {

	int cnt = 0;

	for (double x = 0.1; x <= 1; x += h) {

		cnt += 1;
	}

	return cnt;
}

void get_answer(const double h, double x1; const double x2) {

	int n = 1;

	for (x1; x1 <= x2; x1 += h) {

		printf("%f\t%f\t%.4f\n", x1, cos(x1), get_summ(x1, n));

		n += 1;
	}
}



double get_summ(const double x, const int n) {

	double summ = 0;

	double func = 1 - pow(x, 2) / 2;

	summ += func;

	for (int i = 0; i <= n; i++) {

		func *= pow(x, 2) / (4 * pow(n, 2) - 2 * n);

		summ += func;
	}

	return summ;
}

bool is_h(const double h) {

	return h > 0;
}
