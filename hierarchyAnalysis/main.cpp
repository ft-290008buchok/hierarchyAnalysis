/*Программа для анализа иерархий методом Томаса Саати
Сравенеие критериев первого уровня*/

#include<iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

void norm(float*, int);


int main() {
	setlocale(LC_ALL, "rus");
	cout << "                            Анализ иерархий\n";
	cout << "                          методом Томаса Саати\n";
	cout << "Введите колличество критериев оценивания\n";
	int cr_num, i, j;
	cin >> cr_num;

	//Массив хранящий значения коэффициентов
	float *coefficients = new float[cr_num];
	for (i = 0; i < cr_num; i++) 
		coefficients[i] = 0;
	
	float **relations = new float*[cr_num];

	for (i = 0; i < cr_num; i++)
		relations[i] = new float[cr_num];
		

	for (i = 0; i < cr_num; i++)
		for (j = 0; j < cr_num; j++)
			relations[i][j] = 0;

	/*Создание таблицы для ввода матрицы
	дробей попарного сравнения критериев*/
	for (i = 0; i < cr_num; i++) {
		cout << "   " << i + 1 << "-й";
	}
	cout << "   козфициент";
	for (i = 0; i < cr_num; i++) {
		cout << "\n" << i + 1 << "-й";
		cout << " ";
		for (j = 0; j < cr_num; j ++)
			cout << "/     ";
	}

	float numerator;
	float denominator;
	float relation;

	//Перемещение курсора по консоли
	// Объявление необходимой структуры
	COORD position;
	// Получение дескриптора устройства стандартного вывода
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// Установка координат X и Y
	position.X = 3;
	position.Y = 5;
	// Перемещение каретки по заданным координатам
	SetConsoleCursorPosition(hConsole, position);

	/*Ввод дробей попарного сравнения критериев*/
	for (i = 0; i < cr_num; i++) {
		for (j = i; j < cr_num; j++) {
			cin >> numerator;
			position.X += 2;
			SetConsoleCursorPosition(hConsole, position);
			cin >> denominator;
			relation = numerator / denominator;
			relations[i][j] = relation;
			relations[j][i] = 1 / relation;

			position.Y += (j - i);
			position.X -= (6 * (j - i) + 2);
			SetConsoleCursorPosition(hConsole, position);
			cout << denominator;
			position.X += 2;
			SetConsoleCursorPosition(hConsole, position);
			cout << numerator;
			position.X += (6 * (j - i));
			position.Y -= (j - i);
			SetConsoleCursorPosition(hConsole, position);

			position.X += 4;
			SetConsoleCursorPosition(hConsole, position);
		}
		position.X = 3 + 6 * (i + 1);
		position.Y += 1;
		SetConsoleCursorPosition(hConsole, position);
	}

	for (i = 0; i < cr_num; i++)
		for (j = 0; j < cr_num; j++)
			coefficients[i] += relations[i][j];

	//Нормирование и округление сумм по строкам
	norm(coefficients, cr_num);

	//Вывод коэффициентов
	position.X = 3 + 6 * cr_num;
	position.Y = 5;
	SetConsoleCursorPosition(hConsole, position);
	for (i = 0; i < cr_num; i++) {
		cout << coefficients[i];
		position.Y ++;
		SetConsoleCursorPosition(hConsole, position);
	}
	cout << endl;

	cout << "Для продолжения нажмите любую клавишу";
	_getch();  //пауза

	return 0;
}




//Функция нормирует и округляет коэффициенты до 0,01
void norm(float *mass, int size) {

	//Сумма всех коэффициентов
	float sum = 0;
	//Нормированное, но не округлённое значение коэффициента
	float normed_c;
	//Хвост от округления
	float tail;

	for (int i = 0; i < size; i++)
		sum += mass[i];

	//Нормирование и округление коэффициентов
	for (int i = 0; i < size; i++) {
		normed_c = mass[i] / sum;
		tail = (normed_c * 100 - (int)(normed_c * 100)) / 100;
		//Округление результата
		if (tail * 1000 >= 5) {
			normed_c += 0.01;
		}
		normed_c -= tail;
		mass[i] = normed_c;
	}
}