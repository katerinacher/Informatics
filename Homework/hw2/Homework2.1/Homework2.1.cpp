#include <io.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <process.h>
#include <locale.h>
#include <string.h>

#define TRUE 1

typedef struct {
  char brand[30];
  char name[30];
  int day;
  int month;
  int year;
  int amount;
  int price;
  char country[30];
} Telephone;

// заполнение полей структуры Telephone
Telephone* InitTelephone() {
  Telephone* phone = (Telephone*)malloc(sizeof(Telephone));
  printf("\nВведите марку телефона: ");
  scanf_s("%s", phone->brand, sizeof(phone->brand));
  printf("Введите наименование телефона: ");
  scanf_s("%s", phone->name, sizeof(phone->name));
  printf("Введите дату поступления телефона в формате ДД.ММ.ГГГГ: ");
  scanf_s("%d.%d.%d", &phone->day, &phone->month, &phone->year);
  printf("Введите цену телефона в рублях: ");
  scanf_s("%d", &phone->price);
  printf("Введите страну - производителя телефона: ");
  scanf_s("%s", phone->country, sizeof(phone->country));
  printf("Введите количество телефонов данной марки: ");
  scanf_s("%d", &phone->amount);
  return phone;
}

//формирование файла
void InitFile(char* String, long n) {
  Telephone* phone;
  FILE* F = fopen(String, "w+b");

  if (F == NULL) {
    printf("Невозможно открыть файл.\n");
    abort();
  }

  for (int i = 1; i <= n; i++) {
    printf("\nВведите информацию о телефоне номер %d\n", i);
    phone = InitTelephone();
    fwrite(phone, sizeof(Telephone), 1, F);
  }
  fclose(F);
}

// добавление структур в бинарный файл
void AddToFile(char* String, long n) {
  Telephone* phone;
  FILE* F = fopen(String, "a+b");

  if (F == NULL) {
    printf("Невозможно открыть файл.\n");
    abort();
  }

  for (int i = 1; i <= n; i++) {
    printf("\nВведите информацию о телефоне номер %d\n", i);
    phone = InitTelephone();
    fwrite(phone, sizeof(Telephone), 1, F);
  }
  fclose(F);
}

// удаление структур из бинарного файла
void RemoveFromFile(char* String, long Position) {
  FILE* F = fopen(String, "r+b");
  int DescriptorFile = _fileno(F);
  long LengthFile = _filelength(DescriptorFile);
  Telephone* phone = (Telephone*)malloc(sizeof(Telephone));
  long NewLength = LengthFile - sizeof(Telephone);

  if (F == NULL) {
    printf("Невозможно открыть файл.\n");
    abort();
  }

  fseek(F, Position * sizeof(Telephone), SEEK_SET);
  while (fread(phone, sizeof(Telephone), 1, F) != 0) {
    fseek(F, -2 * (long)sizeof(Telephone), SEEK_CUR);
    fwrite(phone, sizeof(Telephone), 1, F);
    fseek(F, (long)sizeof(Telephone), SEEK_CUR);
  }

  DescriptorFile = _chsize(DescriptorFile, NewLength);
  free(phone);
  fclose(F);
}

//выводит на экран структуру типа Telephone из бинарного файла
void DisplayTelephone(Telephone* phone) {
  printf("\n|%-10s %-13s|%02d.%02d.%4d          |%-12d|%-26s|%-15d|\n", phone->brand, phone->name, phone->day, phone->month, phone->year, phone->price, phone->country, phone->amount);
  printf(" _____________________________________________________________________________________________________");
}

//выводит на экран содержимое бинарного файла
void DisplayFile(char* String) {
  Telephone* phone = (Telephone*)malloc(sizeof(Telephone));
  FILE* F = fopen(String, "r+b");
  if (F == NULL) {
    printf("Невозможно открыть файл.\n");
    abort();
  }

  printf("\n _____________________________________________________________________________________________________\n");
  printf("|Наименование и марка    |Дата поступления    |Цена        |Страна - производитель    |Количество штук|");
  printf("\n _____________________________________________________________________________________________________");

  while (fread(phone, sizeof(Telephone), 1, F) != 0) {
    DisplayTelephone(phone);
  }
  free(phone);
  fclose(F);
}

//case 5
void CountryProduct (char* String) {
  FILE* F = fopen(String, "r+b");
  Telephone* phone = (Telephone*)malloc(sizeof(Telephone));
  char string_country[30];
  int count = 0;
  if (F == NULL) {
    printf("Невозможно открыть файл.\n");
    abort();
  }
  printf("Введите страну, чей товар хотите найти:");
  scanf_s("%s", string_country, sizeof(string_country));

  while (fread(phone, sizeof(Telephone), 1, F) != 0) {
    if (strcmp(string_country, phone->country) == 0) {
      count++;
    }
  }

  rewind(F);
  if (count != 0) {
    printf("Товар производства данной страны есть:\n");

    printf("\n _____________________________________________________________________________________________________\n");
    printf("|Наименование и марка    |Дата поступления    |Цена        |Страна - производитель    |Количество штук|");
    printf("\n _____________________________________________________________________________________________________");
    while (fread(phone, sizeof(Telephone), 1, F) != 0) {
      if (strcmp(string_country, phone->country) == 0) {
        DisplayTelephone(phone);
      }
    }
  } else {
    printf("Товара производства данной страны нет\n");
  }

  fclose(F);
}

// case 6
void Summa(char* String) {
  FILE* F = fopen(String, "r+b");
  Telephone* phone = (Telephone*)malloc(sizeof(Telephone));
  int sum;
  int n = 0;
  if (F == NULL) {
    printf("Невозможно открыть файл.\n");
    abort();
  }
  printf("\nВведите сумму:");
  scanf_s("%d", &sum);


  while (fread(phone, sizeof(Telephone), 1, F) != 0) {
    int summa = phone->price;
    for (int i = 1; i <= phone->amount; i++) {
      if (sum >= summa) {
        summa += phone->price;
        n = i;
      }
    }
    printf("Телефон марки %s %s - максимально возможное количество таких телефоноф на заданную сумму = %d\n", phone->brand, phone->name, n);
  }

  fclose(F);
}

//case 7
void SumProduct(char* String) {
  FILE* F = fopen(String, "r+b");
  Telephone* phone = (Telephone*)malloc(sizeof(Telephone));
  int data_mon;
  int data_day;
  int data_year;
  int sum = 0;

  if (F == NULL) {
    printf("Невозможно открыть файл.\n");
    abort();
  }
  printf("\nВведите дату:");
  scanf_s("%d.%d.%d", &data_day, &data_mon, &data_year);

  while (fread(phone, sizeof(Telephone), 1, F) != 0) {
    if ((phone->year > data_year) || ((phone->year >= data_year) && (phone->month > data_mon)) 
      || ((phone->year >= data_year) && (phone->month >= data_mon) && ((phone->day > data_day)))) {
      sum += (phone->price) * (phone->amount);
    }
  }

  rewind(F);
  if (sum != 0) {
    printf("Общая сумма поступивших товаров, начиная с заданной даты: %d\n", sum);
    printf("Эти товары:");

    printf("\n _____________________________________________________________________________________________________\n");
    printf("|Наименование и марка    |Дата поступления    |Цена        |Страна - производитель    |Количество штук|");
    printf("\n _____________________________________________________________________________________________________");
    while (fread(phone, sizeof(Telephone), 1, F) != 0) {
      if ((phone->year > data_year) || ((phone->year >= data_year) && (phone->month > data_mon))
        || ((phone->year >= data_year) && (phone->month >= data_mon) && ((phone->day > data_day)))) {
        DisplayTelephone(phone);
      }
    }
  } else {
    printf("Позже заданной даты товары не поступали\n");
  }

  fclose(F);
}

int main() {
  setlocale(0, "rus");
  int number;
  char FileName[20];
  int num;
  puts("Введите имя файла: ");
  gets_s(FileName);

  while (TRUE) {
    printf("\n\n------------MENU------------\n");
    printf("1 - Сформировать файл\n");
    printf("2 - Вывести содержимое файла\n");
    printf("3 - Добавить товар в файл\n");
    printf("4 - Удалить товар из файла\n");
    printf("5 - Определить, есть ли в магазине указанный товар производства данной страны\n");
    printf("6 - Определить, можно ли приобрести товар за данную сумму\n");
    printf("7 - Определить на какую общую сумму поступили товары, начиная с указанной даты\n");
    printf("8 - Выход\n");
    printf("Ваше число: ");

    scanf_s("%d", &number);
    switch (number) {
    case 1:
      while (TRUE) {
        printf("\nВведите количество телефонов: ");
        scanf_s("%d", &num);
        if (num > 0) break;
        printf("\nНеверный ввод. Попробуйте снова...\n");
      }
      InitFile(FileName, num);
      break;

    case 2:
      DisplayFile(FileName);
      break;

    case 3:
      while (TRUE) {
        printf("\nВведите количество телефонов для добавления:");
        scanf_s("%d", &num);
        if (num > 0) break;
        printf("\nНеверный ввод. Попробуйте снова...\n");
      }
      AddToFile(FileName, num);
      break;

    case 4:
      while (TRUE) {
        printf("\nВведите номер телефона, который хотите удалить:");
        scanf_s("%d", &num);
        if (num > 0) break;
        printf("\nНеверный ввод. Попробуйте снова...\n");
      }
      RemoveFromFile(FileName, num);
      break;

    case 5:
      CountryProduct(FileName);
      break;

    case 6:
      Summa(FileName);
      break;

    case 7:
      SumProduct(FileName);
      break;

    case 8:
      return 0;

    default:
      printf("\nНеверный ввод. Попробуйте снова...");
      break;
    }
  }
  return 0;
}