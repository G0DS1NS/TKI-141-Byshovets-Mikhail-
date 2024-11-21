#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>


#define RAND_MIN -1000 // Минимальное значение случаных чисел
#define RAND_MAX 1000 // Максимальное значение случайных чисел

/**
* @brief sinput принимает значение, введённое пользователем
* @return возвращает значение введённое пользователем
*/
size_t sinput(void);

/**
* @brief choose перечисляет констаты для того, чтобы пользователь выбрал, как заполнять список
* @param manually вручную
* @param random случайные числа
*/
typedef enum {

	manually = 1, 
	random
}choose;

/**
* @brief is_positive проверяет, является ли число положительным
* @param n проверяемое число
* @return true, если число положительное и false, если отрицательное
*/
bool is_positive(const int n);

/**
* @brief summ_of_number считает сумму четных элементов массива
* @param list_of_number массив чисел
* @return сумму целый чисел массива
*/
int summ_of_even(const int* list_of_number);


/**
* @brief summ_of_two_char считает количество элементов массива, состоящих из двух цифр
* @param list_of_number массив целых чисел
* @return количество чисел, состоящих из двух цифр
*/
int count_of_two_char(const int* list_of_number);


/**
* @brief replace_list заменяет последний отрицательный элемент массива на модуль первого элемента массива
* @param list_of_number массив целых чисел
*/
void replace_list(int* list_of_number);

/**
* @brief initialize_manually заполняет массив целыми числами, которые ввёл пользователь
* @param list_of_number массив 
* @param n длина списка
*/
void initialize_manually(int* list_of_number,const int n);


/**
* @brief initialize_rand заполняет массив случайными целыми числами
* @param list_of_number массив целых чисел
* @param n длина списка
*/
void initialize_rand(int* list_of_number,const int n);

/**
* @brief input считывает значение, вводимое пользователем
* @return возвращает значение, вводимое пользователем
*/
int input(void);

/**
* @brief main выводит результат всех действий пользователю на экран
* @return возвращает 0 в случае успеха
*/
int main(void) 
{

	puts("Enter the n:");

	size_t n = input();

	if (!is_positive(n)) {

		puts("n is not positive");

		return 1;
	}

	int *list_of_number = (int*)malloc(sizeof(int) * n);

	if(list_of_number == NULL)
	{
		puts("Error");
		return 1;
	}

	choose choose_initialize = (choose)input();

	switch (choose_initialize) {

	case manually:
		initialize_manually(list_of_number, n);
		break;
	case random:
		initialize_rand(list_of_number, n);
		break;
	default:
		puts("Error");
		return 1;
	}

	replace_list(list_of_number);

	printf("summ of even numbers = %d\nThe count of numbers consisting of two digits = %d\n", summ_of_even(list_of_number), count_of_two_char(list_of_number));

	free(list_of_number);

	return 0;
}

int summ_of_even(int* list_of_number)
{
	int summ = 0;

	for (size_t i = 0; i < sizeof(list_of_number) / sizeof(list_of_number[0]); i++)
	{
		if (list_of_number[i] % 2 == 0)
		{
			summ += list_of_number[i];
		}
	}

	return summ;
}

int count_of_two_char(int* list_of_number)
{

	int count = 0;

	for (size_t i = 0; i < sizeof(list_of_number) / sizeof(list_of_number[0]); i++) {

		double element = (double)list_of_number[i];

		if (element / 100 > 0.1 + DBL_EPSILON && element / 100 < 1 + DBL_EPSILON) {

			count += 1;
		}
	}

	return count;
}

void replace_list(int* list_of_number)
{
	int replace_element = 0;

	for (size_t i = sizeof(list_of_number) / sizeof(list_of_number[0]) - 1; i != -1; i--)
	{
		if (list_of_number[i] < 0)
		{
			replace_element = list_of_number[0];
			list_of_number[0] = list_of_number[i];
			list_of_number[i] = replace_element;

			break;
		}
	}

}

void initialize_manually(int* list_of_number, int n)
{

	for (size_t i = 0; i < n; i++)

	{
		puts("\nEnter the your number:");
		list_of_number[i] = input();
	}

}

void initialize_rand(int* list_of_number, int n)
{

	for (size_t i = 0; i < n; i++)
	{
		list_of_number[i] = rand();
	}
}

int input(void)
{
	int number = 0;

	if (scanf_s("%d", &number) != 1)
	{

		puts("Your input is uncorrected");

		exit(EXIT_FAILURE);
	}

	return number;
}

bool is_positive(const int n) {

	return n > 0;
}

size_t sinput(void)
{
    size_t number = 0;
    if (scanf_s("%zu", &number) != 1)
    {
        puts("Your input is uncorrected");
        exit(EXIT_FAILURE);

    }

    return number;
}
