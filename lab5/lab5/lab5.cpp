#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

int main()
{
  setlocale(0, "russian");
  int n;
  char matrix[10][10];
  int count = 0;
  printf(" Введите n < 10: ");
  scanf_s("%d", &n);
  if (n < 10) {
    printf(" Заполните матрицу:\n");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf(" matrix[%d][%d] = ", i+1, j+1);
        scanf_s(" %c", &matrix[i][j]);
      }
    }
    printf(" Матрица                 | Количество латинских букв в этой строке:\n");

    for (int i = 0; i < n; i++) {
      count = 0;
      for (int j = 0; j < n; j++) {
        printf(" %c ", matrix[i][j]);
      if (((matrix[i][j] >= 65) && (matrix[i][j] <= 90)) || ((matrix[i][j] >= 97) && (matrix[i][j] <= 122))) {
        count++;
      }
      }
      printf("               %7d\n", count);
    }

  } else {
    printf(" Вы ввели n >= 10\n");
  }
  system("pause");
}

