#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "mystrings.h"
#include <string.h>

void strinput(char*, int, int);				//ввод строки с клавиатуры
char** stralloc(int, ...);					//выделение памяти под массив строк переменного размера
char** strtoword(char**, int*, int);		//преобразование массива строк в массив слов
void arrprint(char**, int);					//вывод массива на экран
void strsort(char**, int);					//сортировка строк массива по длине
char** argalloc(int, char**);				//выделение памяти под массив через аргументы командной строки
void bye();									//прощание с пользователем

