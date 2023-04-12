#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <ctime>

int main() {
  setlocale(0, "russian");
  srand(time(NULL));
  int n, m, p, q;
  int elem;
  int count = 0;

  printf("Введите размер матрицы n*m (n < m):\n");
  printf("n = ");
  scanf_s("%d", &n);

  printf("m = ");
  scanf_s("%d", &m);

  if ((m > n) && (m > 0) && (n > 0)) {
    int** mtrx = new int* [n];

    for (int i = 0; i < n; i++) {
      *(mtrx+i) = new int[m];
      for (int j = 0; j < m; j++) {
        *(*(mtrx+i)+j) = rand() % 20-10;
        printf("%d \t", *(*(mtrx + i) + j));
      }
      printf("\n");
    }

    printf("Введите индексы p и q нужного элемента (отсчёт с 1):\n");
    printf("p = ");
    scanf_s("%d", &p);

    printf("q = ");
    scanf_s("%d", &q);

    if ((p <= n) && (p > 0) && (q <= m) && (q > 0)) {
      printf("\nЗначение элемента с индексами p и q: %d\n", *(*(mtrx + p - 1) + q - 1));

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (*(*(mtrx + i) + j) < *(*(mtrx + p - 1) + q - 1)) {
            count += 1;
            printf("\nАдрес элемента %d, меньшего, чем элемент с индексами p и q: %p\n", *(*(mtrx + i) + j), *(mtrx + i) + j);
          }
        }
      }

      if (count != 0) {
        printf("\nКоличество элементов, меньших, чем элемент с индексами p и q: %d\n", count);
      } else {
        printf("\nЭлементов, меньших, чем элемент с индексами p и q, нет\n");
      }
    } else {
      printf("Вы ввели не удовлетворяющие условиям p и q\n");
    }
    for (int i = 0; i < n; i++)
      delete[] *(mtrx + i);
    delete[] mtrx;

  } else {
    printf("Вы ввели не удовлетворяющие условиям m и n\n");
  }
  return 0;
}

