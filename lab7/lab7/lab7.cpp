#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#define LEN 40

char* strdel(char* str, char* str2){
  char* ptr;
  strcpy(str2, str);
  while ((ptr = strstr(str2, "  ")) != NULL) {
    strcpy(ptr, ptr + 1);
  }
  ptr = str2;
  if (str2[0] == ' ') {
    strcpy(ptr, ptr + 1);
  }
  return str2;
}

int main() {
  setlocale(0, "russian");
  char line[LEN];
  char line2[LEN];
  char line3[LEN];
  int i = 0;
  int start = 0;
  int counter = 0;
  int max = 0;
  char maxword = 0;
  int n = 0;

  printf("Введите строку, длиной меньше 40:\n");
  gets_s(line);
  strdel(line, line2);

  if (line2[i] != NULL) {
    while (line2[i] != '.') {
      n++;
      if (line2[i] != ' ') {
        counter++;
        if (counter > max) {
          max = counter;
          maxword = counter;
          start = i - max + 1;
        }
      } else {
        counter = 0;
      }
      i++;
    }

    printf("\nВаша строка:\n");
    strcpy(line3, line2);
    line3[n] = NULL;
    puts(line3);

    maxword += start;
    printf("\nСамое длинное слово:\n");

    for (i = start; i < maxword; i++) {
      putchar(line2[i]);
    }
    printf("\n");

    printf("\nДлина самого длинного слова: %d\n", max);

    i = start;
    printf("\nСкорректированная строка: \n");
    while (i < (LEN - max)) {
      line2[i] = line2[i + max + 1];
      i++;
    }

    strcpy(line3, line2);
    line3[n-max-1] = NULL;
    puts(line3);
    printf("\n");

  } else {
    printf("Вы ввели нулевую строку\n");
  }

  return 0;
}
