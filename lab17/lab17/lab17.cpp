#include <iostream>

struct elem {
  int num;
  elem* next;
};
elem* first, * cur, * next, * last;
char snum[40];

int SumOfDigit(int num) {
  if (num == 0) {
    return 0;
  } else {
    return (num % 10) + SumOfDigit(num / 10);
  }
}

void PrintList(elem** first) {
  cur = *first;
  while (cur != NULL) {
    printf("%7d", cur->num);
    cur = cur->next;
  }
  printf("\n");
}

void SortList(elem** first) {
  elem* cur, * prev, * next;
  bool flag;
  if (*first != NULL) {
    flag = true;
    cur = *first;
    while (flag) {
      flag = false;
      prev = NULL;
      cur = *first;
      next = cur->next;
      while (next != NULL) {
        if (abs(SumOfDigit(cur->num)) > abs(SumOfDigit(next->num))) {
          flag = true;
          cur->next = next->next;
          next->next = cur;
          cur = next;
          if (prev != NULL) {
            prev->next = cur;
          } else {
            *first = cur;
          }
        }
        prev = cur;
        cur = cur->next;
        next = cur->next;
      }
    }
  }
}

int main() {
  setlocale(0, "rus");
  FILE* f;
  fopen_s(&f, "file", "r+t");
  char value[8];
  int count = 0;

  if (f != 0) {
    while (fgets(snum, 40, f) != NULL) {
      *value = '\0';
      int j = 0;
      for (int i = 0; i <= strlen(snum); i++) {
        if ((snum[i] == ' ') || (snum[i] == '\0')) {
          value[j] = '\0';

          if (first == NULL) {
            first = new elem;
            first->next = NULL;
            first->num = atoi(value);
            last = first;
          } else {
            cur = new elem;
            cur->num = atoi(value);
            cur->next = NULL;
            last->next = cur;
            last = cur;
          }

          j = 0;
          value[j] = '\0';

        } else {
          value[j++] = snum[i];
        }
      }
    }

    cur = first;
    while (cur != NULL) {
      count++;
      cur = cur->next;
    }

    printf("Числа в файле:\n ");
    PrintList(&first);

    printf("\nКоличество чисел в списке: %d\n", count);

    int k = 0;
    cur = first;
    while (cur != NULL) {
      if (cur->num % 5 == 0) {
        k++;
      }
      cur = cur->next;
    }
    printf("\n");

    if (k != 0) {
      printf("Количество чисел в списке, кратных 5: %d", k);
      printf("\nЧисла списка, кратные 5: ");
      cur = first;
      while (cur != NULL) {
        if (cur->num % 5 == 0) {
          printf("%d\t", cur->num);
        }
        cur = cur->next;
      }
      printf("\n");
    } else {
      printf("Чисел, кратных 5, в списке нет\n");
    }

    cur = first;
    while (cur != NULL) {
      printf("\nСумма цифр в числе %d: %3d", cur->num, abs(SumOfDigit(cur->num)));
      cur = cur->next;
    }
    printf("\n");

    printf("\nСписок, отсортированный по возрастанию суммы цифр числа:\n ");
    SortList(&first);
    PrintList(&first);

    while (first != NULL) {
      cur = first;
      first = first->next;
      delete cur;
    }
    cur = NULL;
    last = NULL;

  } else {
    printf("Невозможно открыть файл\n");
  }

  return 0;
}