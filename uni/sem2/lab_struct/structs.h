#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size 10
typedef struct temp {
	char data[2][size];	//0 for goods, 1 for country.
	int amount;
};

FILE* file(const char* _FILE_NAME, const char* _MODE);								//открытие файла с проверкой

int getnum();																		//считывание числа с клавиатуры
int strcmpp(char* a, const char* b);												//сравнение строк
	
char* getsf();																		//считывание строки из файла

void fileprint(FILE*);																//вывод файла на экран
void prog_end(int* cont);															//проверка окончания программы
void arrprint(temp*, int);															//вывод массива на экран
void binprint(temp* a, int n, FILE* fptr);											//запись в бинарный файл
void bout(temp* a, const char* _NAME, int n);										//запись и чтение из бинарного файла
	
temp* alloc();																		//выделение памяти под массив структур
temp* recalloc(temp*, int);															//перевыделение памяти под структуру
temp* bin_read(int n, FILE* fptr);													//чтение массива структур из бинарного файла
temp* fstruct(FILE* fptr, int* n);													//инициализация и заполнение массива структур из файла
temp* labstep1(temp* a, int n, int* cont, int* a_new_size);							//основная функция программы
temp* part_print(temp* a, int n, const char* b, int mode, int* x, int* total);		//вывод на экран и запись в отдельный массив результатов поиска в