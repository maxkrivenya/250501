#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE* file(const char* file_name, const char* open_mode);
char** wordlist_add(char** wordlist, char* word, int word_amt);
char** alloc(int str_amount, int str_size);
char* fword(char*, int, int);
bool word_search(char** wordlist, int word_amt, int* wordcount, char* word);
void result_print(char** wordlist, int* wordcount, int word_amt);
void sort_and_print(char** wordlist, int* wordcount, int word_amt);
void str_switch(char** a, char** b);
void file_print(FILE* fptr);