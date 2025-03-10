#include<iostream>
#include "Person.h"

using namespace std;

int main(void) {
	string ln, fn, pn;
	cout << "圾志快忱我找快 我技攸:";
	cin >> ln;
	cout << "圾志快忱我找快 扳忘技我抖我攻:";
	cin >> fn;
	cout << "圾志快忱我找快 抉找折快扼找志抉:";
	cin >> pn;
	Person student(ln, fn, pn);
	student.Show();
	student.ShowFormal();
}