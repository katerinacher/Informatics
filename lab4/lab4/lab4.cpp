#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctime>
#include <locale.h>
#define SIZE 20


int main()
{
	setlocale(0, "russian");
	int maxdist = 0;
	int point1, point2, ipoint1, ipoint2;
	int arr[SIZE];
		srand(time(NULL));
		printf("Ваш массив: ");
		for (int i = 0; i < SIZE; i++) {
			arr[i] = rand() % 50 -25;
			printf("%d ", arr[i]);
		}
		for (int i = 0; i < SIZE; i++) {
			for (int j = i + 1; j < SIZE; j++) {
				if (arr[j] - arr[i] > maxdist) {
					maxdist = arr[j] - arr[i];
					point1 = arr[i];
					point2 = arr[j];
					ipoint1 = i + 1;
					ipoint2 = j + 1;
				}
			}
		}
		printf("\nНаибольшее расстояние между двумя точками: %d\nПервая точка: %d\nВторая точка: %d\n",maxdist, point1, point2);
		printf("Номер первой точки: % d\nНомер второй точки: % d\n", ipoint1, ipoint2);
		system("pause");
		return 0;
}