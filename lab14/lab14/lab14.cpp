#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <ctime>
#include "prog.h"

int main() {
  setlocale(0, "russian");
  srand(time(NULL));
  int n;

  printf("Введите размер матрицы n*n:\n");
  printf("n = ");
  scanf_s("%d", &n);

  if (n > 0) {
    float** mtrx = new float* [n];
    printf("Исходная матрица:\n");
    for (int i = 0; i < n; i++) {
      *(mtrx + i) = new float[n];
      for (int j = 0; j < n; j++) {
        *(*(mtrx + i) + j) = (float)(rand() % 2000 - 1000) / 100.0;
        printf("%4.2f \t", *(*(mtrx + i) + j));
      }
      printf("\n");
    }
    
    printf("\n%4.2f - %p\n ", *(*(mtrx + 0) + 0), (*(mtrx + 0) + 0));
    printf("%4.2f- %p \n", *(*(mtrx + 1) + 0),  (*(mtrx + 1) + 0));


    for (int j = 0; j < n; j++) {
      prog(mtrx, n, j);
    }

    printf("\nПреобразованная матрица:\n");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%4.2f \t", *(*(mtrx + i) + j));
      }
      printf("\n");
    }

    for (int i = 0; i < n; i++)
      delete[] *(mtrx + i);
    delete[] mtrx;

  } else {
    printf("Вы ввели некорректный размер матрицы.\n");
  }

  return 0;
}