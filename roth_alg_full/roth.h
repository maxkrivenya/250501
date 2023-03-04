#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size 5

FILE* open_read(const char* _FILE_NAME);

char*** char3(int _size, int _size2);

char** roth_step_1(char** c, int C_size, int* Z_size, int i);
char** merge(char**, char**, int*, int);
char** strshift(char** a, int n, int k);
char** repeat_check(char** a, int* x);
char** del(char**, int* n, int);
char** char2(int _size);

char* froth1(char* a, char* b, int* a1, int*b1, int*acount, int*flg);
char* roth_check(char* a, char* b);
char* simple_sub(char* a, char* b);
char* raw_sub(char* a, char* b);
char* z_remove(char* a, char* b);
char* strcpyy(char* a, char* b);
char* over(char* a, char* b);


char roth_mult(char a, char b);
char roth_sub(char a, char b);
char roth_over(char a, char b);

int strcmpp(char* a, char* b);
int issame(char* a, char* b);
int Zcount(char* a);
int numcount(char* a);

void print(char*);
void roth_step_2(char** L, char** Z, int L_size, int Z_size);
void table_print(char*** Cnew, char** c, int C_size, int o);
void printing(int C_size, int A_size, int* q);
void begin_print(char** c, int C_size);
void arrprint(char**, int);
void print_top(char**, int);
