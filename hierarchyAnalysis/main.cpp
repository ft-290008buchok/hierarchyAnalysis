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

	
	for (int i = 0; i < cr_num; i++) {
		cout << "   " << i + 1 << "-й";
	}
	for (int i = 0; i < cr_num; i++) {
		cout << "\n" << i + 1 << "-й";
	}

	COORD position;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	position.X = 3;
	position.Y = 5;
	SetConsoleCursorPosition(hConsole, position);
	for (int i = 0; i < cr_num; i++) {
		for (int j = 0; j < cr_num; j++) {
			cin >> digit;
			position.X += 6;
			SetConsoleCursorPosition(hConsole, position);
		}
		position.X = 3;
		position.Y += 1;
		SetConsoleCursorPosition(hConsole, position);
	}

	return 0;
}
