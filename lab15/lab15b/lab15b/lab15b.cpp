#include <iostream>

int main() {
  setlocale(0, "russian");
  FILE* f, * g;
  char filename[10];
  int num;

  printf("Введите имя файла:");
  gets_s(filename);
  fopen_s(&f, filename, "w+b");

  if (f != NULL) {

    srand((unsigned)time(NULL));
    int n;
    printf("Введите количество чисел: ");
    scanf_s("%d", &n);

    if (n > 0) {
      for (int i = 0; i < n; i++) {
        int num = rand() % 100;
        fwrite(&num, sizeof(int), 1, f);
      }

      rewind(f);
      printf("Исходный файл:\n");
      while (fread(&num, sizeof(int), 1, f) != 0) {
        printf("%d   ", num);
      }

      rewind(f);
      printf("\n\nЧётные цифры: ");
      while (fread(&num, sizeof(int), 1, f) != 0) {
        if (num % 2 == 0) {
          printf("%d   ", num);
        }
      }
      printf("\n");

      fopen_s(&g, "name", "w+b");
      fseek(f, 0, SEEK_END);
      int point = ftell(f);
      int i = sizeof(int);

      while (i <= point) {
        fseek(f, -i, SEEK_END);
        fread(&num, sizeof(int), 1, f);
        if (num % 2 != 0) {
          fwrite(&num, sizeof(int), 1, g);
        }
        i += sizeof(int);
      }

      rewind(g);
      printf("\nПолученный файл:\n");
      while (fread(&num, sizeof(int), 1, g) != 0) {
        printf("%d   ", num);
      }

      _fcloseall();
    } else {
      printf("Вы ввели некорректное количество чисел\n");
    }
  } else {
    printf("Невозможно открыть файл\n");
  }

  return 0;
}
