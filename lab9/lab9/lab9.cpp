#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS

struct books {
	char BookName[50];
	char autor[30];
	int year;
} book;

int main() {
	setlocale(0, "rus");
	char st[30];
	char st1[50];
	char year[6];
	puts("Введите имя файла");
	gets_s(st);
	FILE* F;
	F = fopen(st, "w+b");

	if (F != NULL) {
		setlocale(0, "rus");
		while (puts("Введите название книги, её автора и год издания:"),
			gets_s(st1), strlen(st1) != 0, gets_s(st), strlen(st) != 0) {

			strcpy(book.BookName, st1);
			strcpy(book.autor, st);
			book.year = atoi(gets_s(year));
			fwrite(&book, sizeof(book), 1, F);
		}

		rewind(F);
		printf("----------------------ДАННЫЕ В ФАЙЛЕ F----------------------\n");
		printf("____________________________________________________________\n");
		printf("Название книги\t\t      Автор книги\t Год издания\n");
		printf("____________________________________________________________\n");
		setlocale(LC_ALL, ".866");
		while (fread(&book, sizeof(book), 1, F) > 0) {
			printf("%-30s%-20s%-6d\n", book.BookName, book.autor, book.year);
		}
		printf("____________________________________________________________\n");
		printf("\n");

		FILE* G;
		G = fopen("G.dat", "w+b");
		if (G != NULL) {
			fseek(F, 0, SEEK_END);
			int point = ftell(F);
			int i = sizeof(book);
			while (i <= point) {
				fseek(F, -i, SEEK_END);
				fread(&book, sizeof(book), 1, F);
				fwrite(&book, sizeof(book), 1, G);
				i += sizeof(book);
			}
			rewind(G);
			setlocale(0, "rus");
			printf("----------------------ДАННЫЕ В ФАЙЛЕ G----------------------\n");
			printf("____________________________________________________________\n");
			printf("Название книги\t\t      Автор книги\t Год издания\n");
			printf("____________________________________________________________\n");
			setlocale(LC_ALL, ".866");
			while (fread(&book, sizeof(book), 1, G) > 0) {
				printf("%-30s%-20s%-6d\n", book.BookName, book.autor, book.year);
			}
			printf("____________________________________________________________\n");
		}
		_fcloseall();
	} else {
		printf("Невозможно открыть файл");
	}

	return 0;
}

