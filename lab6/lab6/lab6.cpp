#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "prost.h"
#include <stdbool.h>

int main()
{
	setlocale(0, "russian");
	int n;
	printf("Введите чётное n > 2: \n");
	scanf_s("%d", &n);

	if ((n > 2) && (n % 2 == 0)) {
		for (int i = 1; i <= n/2; i++) {
			for (int j = 1; j < n; j++) {
				if ((i + j == n) && (prost(j) == true) && (prost(i) == true)) {
					printf("Число %d является суммой простых чисел %d и %d\n", n, i, j);
					printf("i = %d\n",i);
					printf("j = %d\n", j);
				}
			}
		}
	} else {
		printf("Вы ввели не удовлетворяющее условиям n\n");
	}
	system("pause");
	return 0;
}