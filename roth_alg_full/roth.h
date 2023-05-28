#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size 6

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
char* z_remove_times(char* _Z_remove, char* _origin, int n);
char* strcpyy(char* a, char* b);
char* dectobin(char* a);
char* over(char* a, char* b);
char* dectobin(char*);

char roth_mult(char a, char b);
char roth_sub(char a, char b);
char roth_over(char a, char b);

int str_found(char* a, char** b, int c);
int strcmpp(char* a, char* b);
int issame(char* a, char* b);
int z_count(char* a);
<<<<<<< HEAD
int y_count(char* a);
int num_count(char* a);
=======
int num_count(char* a);
int y_count(char* a);
>>>>>>> bad627e7ad185f82e345dc4a099518e5e6caba14

void prin(char*);
void print(char*);
void roth_step_2(char*** L, char*** Z, int* L_size, int* Z_size);
void table_print(char*** Cnew, char** c, int C_size, int o);
void printing(int C_size, int A_size, int* q);
void begin_print(char** c, int C_size);
void arrprint(char**, int);
void print_top(char**, int);
