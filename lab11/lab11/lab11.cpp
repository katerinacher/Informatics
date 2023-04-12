#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <ctime>
#include <locale.h>

int main() {
	setlocale(0, "russian");
	int n;
	int compos = 1;
	bool fl = 1;
	int count = 0;
	srand(time(NULL));

	printf("Введите размер масcива: ");
	scanf_s("%d", &n);

	if (n > 0) {
		int* arr = new int[n];

		printf("\nВаш массив: \n");
		for (int i = 0; i < n; i++) {
			*(arr + i) = rand() % 20 - 10;
			printf("%d | ", *(arr + i));
		}

		// Поиск элементов, кратных 2 и подсчёт их произведения
		for (int i = 0; i < n; i++) {
			if ((*(arr + i) % 2 == 0) && (*(arr + i) != 0)) {
				compos *= *(arr + i);
				printf("\n\nАдрес элемента %d, кратного 2: %p", *(arr + i) ,arr + i);
			}
		}

		if (compos != 1) {
			printf("\n\nПроизведение элементов, кратных 2: %d", compos);
			printf("\n");

			// Замена первого положительного элемента произведением элементов, кратных 2
			//и подсчёт количества положительных элементов
			for (int i = 0; i < n; i++) {
				if ((fl) && (*(arr + i) > 0)) {
					count += 1;
					*(arr + i) = compos;
					fl = 0;
				}
			}

			if (count == 0) {
				printf("\nНет положительных элементов. \nМассив не изменился:\n\n");
			} else {
				printf("\nИзменённый массив:\n\n");
			}

		} else {
			printf("\n\nЭлементов, кратных 2 нет.\nМассив не изменился: \n\n");
		}

		// Вывод изменённого массива
		for (int i = 0; i < n; i++) {
			printf("%d | ", *(arr + i));
		}
		printf("\n");

		delete[] arr;
	} else {
		printf("Вы ввели n <= 0\n");
	}
	system("pause");
	return 0;
}


