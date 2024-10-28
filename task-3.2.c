#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
* @brief get_summ считает значение функции, исходя из значений n и k
* @param k параметр k
* @param n параметр n
* @return возвращает значение фукции
*/
double get_summ(const int k, const int n);


/*
* @brief get_answer табулирует значение фукции
* @param k параметр k
* @param n параметр n
* @param e параметр e
*/
void get_answer(int k, const int n, double e);

/*
* @brief input принимает значение типа int
* @return возвращает значение типа int, введённое пользователем
*/
int dinput(void);

/**
* @brief finput принимает на вход значения типа double
* @return возвращает значение типа double, веденное пользователем
*/
double finput(void);

/**
* @brief factorial считает значение факториала числа
* @param x параметр x
* @return возвращает значение факториала переданного значения
*/
int factorial(int x);

/*
* @brief main выводит значение протабулированной функции
* @return возращает 0 в слухае успеха
*/
int main(void) {

	int k = 1;
	
	puts("Enter the n:");

	int n = dinput();

	puts("Enter the e:");

	double e = finput();

	get_answer(k, n, e);

	return 0;
}

double get_summ(const int k, int fact_k) {

	return pow(-1, k) * (1 / pow(fact_k, 2));
}


int dinput(void) {

	int number = 0;

	if (scanf_s("%d", &number) != 1) {

		puts("Your input is incorrect");

		exit(EXIT_FAILURE);	
	}

	return number;
}

factorial(void) {

	int k = 1;

	for (int i = 1; i <= k; i++) {

		k *= i;
	}

	return k;
}

void get_answer(int k, const int n, double e) {

	double summ = 0;

	double summ_e = 0;

	double summ_k = get_summ(k, factorial());

	if (summ_k >= e) {

		summ_e += summ_k;
	}

	summ += summ_k;

	k += 1;

	for (k; k <= n; k++) {

		summ_k /= -pow(k, 2);

		if (summ_k >= e) {

			summ_e += summ_k;
		}

		summ += summ_k;

	}

	printf("%lf\n", summ);
	printf("%lf\n", summ_e);
}

double finput(void) {

	double number = 0;

	if (scanf_s("%lf", &number) != 1) {

		puts("Your input is uncorrected");
		
		exit(EXIT_FAILURE);	
	}

	return number;
}
