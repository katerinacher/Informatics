#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

struct elem {
  int num;
  elem* next;
};
elem* first, * cur, * next, * last;
char snum[200];

int main() {
  setlocale(0, "rus");
  int number;
  int min = 41;
  int max = 0;
  int max_num = 0;
  int min_num = 0;
  int sum = 0;
  int count = 0;
  char* token;

  puts("Введите более одного числа через пробел: ");
  gets_s(snum);

  token = strtok(snum, " ");
  first = new elem;
  first->num = atoi(token);
  first->next = NULL;
  last = first;
  token = strtok(NULL, " ");

  while (token != 0) {
    cur = new elem;
    cur->num = atoi(token);
    cur->next = NULL;
    last->next = cur;
    last = cur;
    count++;
    token = strtok(NULL, " ");
  }

  if (count >= 1) {
    puts("Ваш список: ");
    cur = first;
    while (cur != NULL) {
      printf("%d\t", cur->num);
      cur = cur->next;
    }
    printf("\n");

    cur = first;
    while (cur != NULL) {
      sum = 0;
      number = cur->num;
      while (cur->num > 0) {
        sum += cur->num % 10;
        cur->num /= 10;
      }
      if (sum > max) {
        max = sum;
        max_num = number;
      }
      if (sum < min) {
        min = sum;
        min_num = number;
      }
      cur = cur->next;
    }

    printf("\nМаксимальная сумма цифр %d у числа %d\n", max, max_num);
    printf("\nМинимальная сумма цифр %d у числа %d\n", min, min_num);

    while (first != NULL) {
      cur = first;
      first = first->next;
      delete cur;
    }
    cur = NULL;
    last = NULL;

  } else {
    printf("Вы ввели меньше двух чисел");
  }
  return 0;
}