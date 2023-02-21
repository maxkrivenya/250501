#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE* file(const char* file_name, const char* open_mode);							//???????? ?????
FILE* file_choice(const char* a, const char* b);									//???????? ????? ? (?? ??????? ????????????) ?????? ? ???? ??????

char** wordlist_add(char** wordlist, char* word, int word_amt);						//?????????? ????? ? ?????? 
char** alloc(int str_amount, int str_size);											//????????? ?????? ?? ?????? ??????
char* fword(char*, int, int);														//??????????? ????? ?? ??????

int* wordcount_add(int* wordcount, int word_amt);									//????????? ????????? ????????? ????? ? ?????? ?????
int getnum();																		//???? ????? ? ??????????

bool word_search(char** wordlist, int word_amt, int* wordcount, char* word);		//???????? ??????? ????? ? ??????? ????

void result_print(char** wordlist, int* wordcount, int word_amt, int n, FILE*);		//????? ??????????? ????????? ?? ?????
void sort_and_print(char** wordlist, int* wordcount, int word_amt, int n);			//?????????? ? ????? ?????????? ?? ?????
void str_switch(char** a, char** b);												//???????? ??????? ???? ?????
void file_print(FILE* fptr);														//????? ??????????? ?????????? ????? ?? ?????			