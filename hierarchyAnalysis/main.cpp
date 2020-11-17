#include<iostream>
#include <Windows.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	cout << "                            Анализ иерархий\n";
	cout << "                          методом Томаса Саати\n";
	cout << "Введите колличество критериев оценивания\n";
	int cr_num;
	int digit;
	cin >> cr_num;
	float *coefficients = new float[cr_num];
	for (int i = 0; i < cr_num; i++) {
		coefficients[i] = 0;
	}
	
	for (int i = 0; i < cr_num; i++) {
		cout << "   " << i + 1 << "-й";
	}
	cout << "   козфициент";
	for (int i = 0; i < cr_num; i++) {
		cout << "\n" << i + 1 << "-й";
		cout << " ";
		for (int j = 0; j < cr_num; j ++)
			cout << "/     ";
	}

	float numerator;
	float denominator;
	float relation;

	COORD position;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	position.X = 3;
	position.Y = 5;
	SetConsoleCursorPosition(hConsole, position);
	for (int i = 0; i < cr_num; i++) {
		for (int j = 0; j < cr_num; j++) {
			cin >> numerator;
			position.X += 2;
			SetConsoleCursorPosition(hConsole, position);
			cin >> denominator;
			relation = numerator / denominator;
			coefficients[i] += relation;
			position.X += 4;
			SetConsoleCursorPosition(hConsole, position);
		}
		position.X = 3;
		position.Y += 1;
		SetConsoleCursorPosition(hConsole, position);
	}

	return 0;
}
