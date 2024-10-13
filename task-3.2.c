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
*/
void get_answer(const int k, const int n);

/*
* @brief input принимает значение типа int
* @return возвращает значение типа int, введённое пользователем
*/
int input(void);

/*
* @brief initialize заполняет массив факториалами разных чисел
* @param arr передаваемый, уже инициализированный массив
* @param n параметр n
* @param k параметр k
*/
void initialize(int* arr, int n, int k);

/*
* @brief main выводит значение протабулированной функции
* @return возращает 0 в слухае успеха
*/
int main(void) {

	int k = 1;
	
	puts("Enter the n:");

	int n = input();

	get_answer(k, n);

	return 0;
}

double get_summ(const int k, const int n, int fact_k) {

	return pow(-1, k) * (1 / pow(fact_k, 2));
}

int input(void) {

	int number;

	if (scanf_s("%d", &number) != 1) {

		puts("Your input is incorrect");

		exit(EXIT_FAILURE);	
	}

	return number;
}

void get_answer(int k,const int n) {

	int *factorial_k = NULL;

	factorial_k = malloc(sizeof(int) * n);

	initialize(factorial_k, n, k);

	for (k; k < n + 1; k++) {

		printf("%f\n", get_summ(k, n, factorial_k[k - 1]));
	}

}

void initialize(int* factorial_k, const int n, int k) {

	factorial_k[0] = k;

	for (int i = 1; i < n + 1; i++) {

		factorial_k[i] = factorial_k[i - 1] * (factorial_k[i - 1] + 1);
	}
}