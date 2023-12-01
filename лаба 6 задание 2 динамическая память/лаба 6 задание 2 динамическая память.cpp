#include <iostream>
#include <clocale>

using namespace std;

/*
* Лабораторная работа 6. Поливцев Михаил, ИВТ-31. Задание 2 (с динамическим выделением памяти).
* Индивидуальный вариант задания 16.
* Дана квадратная матрица A порядка M. Найти минимальный элемент для каждой ее диагонали,
* параллельной главной (начиная с одноэлементной диагонали A1,M ).
*/

int main() {
	setlocale(LC_ALL, "ru");

	int m;
	cout << "Введите порядок матрицы >> ";
	cin >> m;
	if (m < 1) {
		cout << "неверный ввод" << endl;
		return 1;
	}
	int** array;
	array = new int* [m];
	for (int i = 0; i < m; i++) {
		array[i] = new int[m];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << "Введите элемент матрицы >> ";
			cin >> array[i][j];
		}
	}

	// вывод матрицы для удобства
	cout << "\n-----------------------------------------------" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\n-----------------------------------------------" << endl;

	int* res = new int[50];
	int s = 0, n = 1;

	for (int i = m - 1; i >= 0; i--) {
		int iInd = i;
		for (int j = 0; j < n; j++) {
			res[s] = array[j][iInd];
			s++;
			iInd++;
		}
		n++;
		int min = res[0];
		for (int l = 1; l < s; l++) {
			if (res[l] < min) {
				min = res[l];
			}
		}
		cout << min << endl;
		s = 0;
	}

	n = m - 1;
	for (int i = 1; i < m; i++) {
		int iInd = i;
		for (int j = 0; j < n; j++) {
			res[s] = array[iInd][j];
			s++;
			iInd++;
		}
		n--;
		int min = res[0];
		for (int l = 1; l < s; l++) {
			if (res[l] < min) {
				min = res[l];
			}
		}
		cout << min << endl;
		s = 0;
	}

	for (int i = 0; i < m; i++) {
		delete[] array[i];
	}
	delete[] array;
	delete[] res;
}