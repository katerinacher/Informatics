#include <iostream>

int main() {
  setlocale(0, "russian");
  FILE* f;
  FILE* g;
  char filename[10];
  char word[40];
  char consonant[] = "qwrtpsdfghjklzxcvbnmQWRTPSDFGHJKLZXCVBNM", *cletter;
  char vowel[] = "eyuioaEYUIOA", * vletter;
  int count = 0;

  printf("Введите имя файла:");
  gets_s(filename);
  fopen_s(&f, filename, "w+t");
  fopen_s(&g, "name", "w+t");

  if (f != NULL) {
    printf("Введите слова:\n");
    while (gets_s(word), strlen(word) != 0) {
      fputs(word, f);
      fputs("\n", f);
      if (strlen(word) > 6) {
        count++;
      }
      for (cletter = consonant; *cletter; cletter++) {
        if (*word == *cletter) {
          fputs(word, g);
          fputs("\n", g);
        }
      }
    }

    rewind(f);
    printf("Сформированный файл:\n");
    while (fgets(word, 40, f) != NULL) {
      printf("%s", word);
    }

    rewind(f);
    printf("\nСлова, начинающиеся на гласную:\n");
    while (fgets(word, 40, f) != NULL) {
      for (vletter = vowel; *vletter; vletter++) {
        if (*word == *vletter) {
          printf("%s", word);
        }
      }
    }
    printf("\nКоличество слов, длина которых больше 6: %d", count);
    if (count != 0) {
      printf("\nЭти слова:\n");
      rewind(f);
      while (fgets(word, 40, f) != NULL) {
        if (strlen(word) > 7) {
          printf("%s", word);
        }
      }
    }

    rewind(g);
    puts("\nПолученный файл:");
    while (fgets(word, 40, g) != NULL) {
      printf("%s", word);
    }

    _fcloseall();
  } else {
    printf("Невозможно открыть файл\n");
  }

  return 0;
}
