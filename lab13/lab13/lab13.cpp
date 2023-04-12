#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
  setlocale(0, "rus");
  char *line = new char[100];
  printf("Введите строки:\n");
  int i = 0;
  int j;

  while (printf("\n"), gets_s(line, 100), strlen(line) != 0) {
    printf("\nАдрес первого элемента строки: %p", line);
    printf("\n");

    for (i = 0; i < strlen(line); i++) {
      if (*(line + i) == '%' || *(line + i) == '&' || *(line + i) == '#' ||
          *(line + i) == '$' || *(line + i) == '@' || isdigit(*(line + i))) {
        printf("\nАдрес удаленного элемента: %p", line + i);
      } 
    }

    printf("\n\nИсправленная строка: ");

    for (i = 0; i < strlen(line); i++) {
      if (*(line + i) == '%' || *(line + i) == '&' || *(line + i) == '#' ||
          *(line + i) == '$' || *(line + i) == '@' || isdigit(*(line + i))) {
        for (j = i; j < strlen(line); j++) {
          *(line + j) = *(line + j + 1);
        }
        i--;
      }
    }

    puts(line);
  }
  delete[] line;
  return 0;
}