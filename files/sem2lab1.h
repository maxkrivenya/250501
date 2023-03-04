#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE* file(const char* file_name, const char* open_mode);							//Открытие файла в режиме
FILE* file_choice(const char* a, const char* b);									//?Открытие файла с возможностью перезаписи

char** wordlist_add(char** wordlist, char* word, int word_amt);						//добавление в wordlist слова
char** alloc(int str_amount, int str_size);											//выделение памяти под массив строк
char* fword(char*, int, int);														//копирование промежутка строки в новую строку
char* strcpyy(char* _dest, char* _source);											//копирование одной строки в другую
char* word_get(FILE* fptr, int i);

int* wordcount_add(int* wordcount, int word_amt);									//инцииализация слова в wordcount
int getnum();																		//ввод числа с клавиатуры

bool word_search(char** wordlist, int word_amt, int* wordcount, char* word);		//проверка наличия слова в массиве wordlsit, в случае наличия инкрементирует число появлений слова в wordcount

void result_print(char** wordlist, int* wordcount, int word_amt, int n, FILE*);		//вывод результатов на экран
void sort_and_print(char** wordlist, int* wordcount, int word_amt, int n);			//сортировка и вывод результатов на экран
void str_switch(char** a, char** b);												//замена местами двух строк
void file_print(FILE* fptr);														//построчный вывод файла на экран			