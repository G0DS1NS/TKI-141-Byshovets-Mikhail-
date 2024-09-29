#include <stdio.h>

#include <math.h>

/*
* @brief get_a считает значение параметра a, исходя из заданных значений x, y и z
* @param x значение параметра x
* @param y значение параметра y
* @param z значение параметра z
* @return возвращает значение a
*/

double get_a(const double x, const double y, const double z);

/*
* @brief get_b считает значение параметра b, исходя из заданных значений x, y и z
* @param x значение параметра x
* @param y значение параметра y
* @param z значение параметра z
* @return возвращает значение параметра b
*/

double get_b(const double x, const double y, const double z);

/*
* @brief main выводит значения a и b
* @param x значение параметра x
* @param y значение параметра y
* @param z значение параметра z
* @return возвращает 0 в случае успеха
*/

int main(const double x = -0.5, const double y = 1.7, const double z = 0.44) {

	printf("a = %f\n", "b = %f", get_a(x, y, z), get_b(x, y, z));

	return 0;

}

double get_a(const double x, const double y, const double z) {

	return exp(-y * z) * sin(x * y - y) - sqrt(fabs(y * z + x));

}


double get_b(const double x, const double y, const double z) {

	return y * sin(get_a(x, y, z) * z * z * cos(2 * z)) - 1;

}