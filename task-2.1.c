#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>

/**
* @brief operation перечисляет действия, которые можно воспроизвести над числами
* @param add сложение
* @param difference разность
* @param multy умножение
* @param divis деление
*/
typedef enum {

	add = 1,
	difference = 2,
	multy = 3,
	divis = 4

} operation;


/*
* @brief double_input принимает на вход значения типа double
* @return возвращает значение введённое пользователем
*/
double double_input(void);

/*
* @brief int_input принимает на вход значения типа in
* @return возвращает значение введённое пользователем
*/
int int_input(void);

/*
* @brief plus складывает два значения
* @param first_number первое число
* @param second_number второе число
* @return возвращает сумму первого и второго числа
*/
double plus(const double first_number, const double second_number);

/*
* @brief diff вычитает из первого числа второе
* @param first_number первое число
* @param second_number второе число
* @return возвращает разность первого и второго числа
*/
double diff(const double first_number, const double second_number);

/*
* @brief multiplication умножает одно число на второе
* @param first_number первое число
* @param second_number второе число
* @return возвращает произведение первого и второго числа
*/
double multiplication(const double first_number, const double second_number);

/*
* @brief division делить одно число на другое
* @param first_number первое число
* @param second_number второе число
* @return возвращает частное от деления одного значения на другое
*/
double division(const double first_number, const double second_number);

/*
* @brief isZero проверяет является ли число нулём
* @param number число
* @return возвращает true, если число является нулём и false, если не является
*/
bool isZero(const double number);



/*
* @brief main принимает на вход два числа и выводит результат их суммы, разности, произведения или деления
* @return возвращает результат действия, выполненного над двумя числами
*/
int main(void) {

	puts("Enter the first number");

	double first_number = double_input();

	puts("Enter the second number");

	double second_number = double_input();

	puts("Enter the operation\n 1 - addition\n 2 - difference\n 3 - multiplication\n 4 - division\n");

	operation _operation = (operation)int_input();

	switch (_operation) {

	case add:
		printf("%f", plus(first_number, second_number));
		break;

	case difference:
		printf("%f", diff(first_number, second_number));
		break;

	case multy:
		printf("%f", multiplication(first_number, second_number));
		break;

	case divis:
		printf("%f", division(first_number, second_number));
		break;

	default:

		puts("Your input is uncorrected");

		exit(EXIT_FAILURE);

	}

	return 0;
}

double double_input(void) {

	double number = 0;

	if (scanf_s("%lf", &number) != 1) {

		puts("Your input is uncorrected");

		exit(EXIT_FAILURE);
	}

	return number;
}

int int_input(void) {

	int number = 0;

	if (scanf_s("%d", &number) != 1) {

		puts("Your input is uncorrected");

		exit(EXIT_FAILURE);
	}

	return number;
}


double plus(const double first_number, const double second_number) {

	return first_number + second_number;
}

double diff(const double first_number, const double second_number) {

	return first_number - second_number;

}

double multiplication(const double first_number, const double second_number) {

	return first_number * second_number;

}

bool isZero(const double number) {

	return number == 0 + DBL_EPSILON;
}

double division(const double first_number, const double second_number) {

	if (isZero(second_number)) {

		puts("Division by zero is not possible");
		exit(EXIT_FAILURE);

	}

	return first_number / second_number;
}
