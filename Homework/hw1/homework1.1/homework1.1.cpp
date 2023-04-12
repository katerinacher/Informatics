#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <ctime>

void fill_matr(int** matr, int n, int m) {
	srand(time(0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			*(*(matr + j) + i) = rand() % 30;
		}
	}
}

void print_matr(int** matr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d \t", *(*(matr + j) + i));
		}
		printf("\n");
	}
}

int del(int** matr, int n, int m) {
	bool flag = false;

	for (int j = 0; j < m; j++) {
		if (**(matr + j) < 0) {
			flag = true;
			std::cout << "\nНайденный элемент = " << **(matr + j) << " и его адрес - " << *(matr + j);
			delete[] *(matr + j);

			for (int k = j; k < m - 1; k++) {
				*(matr + k) = *(matr + k + 1);
			}

			*(matr + m - 1) = nullptr;
			m--;
			j--;
		}
	}

	if (flag == false) {
		printf("\nНет столбца, первый элемент которого < 0\n");
		printf("\nМатрица без изменений:\n");
	} else {
		printf("\n\nПреобразованная матрица:\n");
	}

	return m;
}

int main() {
	setlocale(0, "rus");
	int n, m;

	printf("Введите размер матрицы n*m (n < m):\n");
	printf("n = ");
	scanf_s("%d", &n);

	printf("m = ");
	scanf_s("%d", &m);

	if ((n > 0) && (m > 0) && (n < m)) {
		int** mtrx = new int* [m];
		for (int i = 0; i < m; i++) {
			*(mtrx + i) = new int[n];
		}

		fill_matr(mtrx, n, m);
		print_matr(mtrx, n, m);

		m = del(mtrx, n, m);
		print_matr(mtrx, n, m);

		for (int i = 0; i < m; i++) {
			delete[] * (mtrx + i);
		}
		delete[] mtrx;
	} else {
		printf("Вы ввели некоррекнтый размер матрицы\n");
	}
	return 0;
}