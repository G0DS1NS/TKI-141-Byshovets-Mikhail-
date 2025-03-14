#include <iostream>
#include "Header1.h"

using namespace std;

int main(void)
{
	double catheter1 = 0;
	double catheter2 = 0;
	puts("Введите первый катет");
	cin >> catheter1;
	puts("Введите второй катет");
	cin >> catheter2;
	Triangle triangle(catheter1, catheter2);
	cout << "Площадь: " << triangle.GetSquare() << endl;
	cout << "Радиус описанной окружности: " << triangle.GetRadius() << endl;
	return 0;
}