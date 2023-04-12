#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctime>

struct elem {
  float num;
  elem* next;
};
elem* first, * cur, * next, * last;
char snum[10];

int main() {
  setlocale(0, "rus");
  char* ptrEnd;
  puts("Введите число или ENTER: ");
  first = new elem;
  gets_s(snum);
  first->num = strtod(snum, &ptrEnd);
  first->next = NULL;
  last = first;

  while (gets_s(snum), strlen(snum) != 0) {
    cur = new elem;
    cur->num = strtod(snum, &ptrEnd);
    cur->next = NULL;
    last->next = cur;
    last = cur;
  }

  if (first->num != NULL) {
    puts("Введённый список: ");
    cur = first;
    while (cur != NULL) {
      printf("%3.2f\t", cur->num);
      cur = cur->next;
    }
    printf("\n");

    int k = 0, n = 0;
    cur = first;
    while (cur != NULL) {
      if (cur->num < 0) {
        k++;
      }
      if (cur->num >= 0) {
        n++;
      }
      cur = cur->next;
    }
    printf("\n");


    if (k != 0) {
      puts("Отрицательные числа списка: ");
      cur = first;
      while (cur != NULL) {
        if (cur->num < 0) {
          printf("%3.2f\t", cur->num);
        }
        cur = cur->next;
      }
      printf("\n");
    } else {
      puts("Отрицательных чисел в списке нет");
    }

    if (n != 0) {
      puts("\nПоложительные числа списка: ");
      cur = first;
      while (cur != NULL) {
        if (cur->num >= 0) {
          printf("%3.2f\t", cur->num);
        }
        cur = cur->next;
      }
      printf("\n");
    } else {
      puts("\nПоложительных чисел в списке нет");
    }

    while (first != NULL) {
      cur = first;
      first = first->next;
      delete cur;
    }
    cur = NULL;
    last = NULL;
  } else {
    puts("Вы не ввели чисел");
  }

	return 0;
}
