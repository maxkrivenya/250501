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

FILE* file(const char* _FILE_NAME, const char* _MODE);

int getnum();
int strcmpp(char* a, const char* b);

char* getsf();

void fileprint(FILE*);
void prog_end(int* cont);
void arrprint(temp*, int);
void binprint(temp* a, int n, FILE* fptr);
void bout(temp* a, const char* _NAME, int n);

temp* alloc();
temp* recalloc(temp*, int);
temp* bin_read(int n, FILE* fptr);
temp* fstruct(temp* a, FILE* fptr, int* n);
temp* labstep1(temp* a, int n, int* cont, int* a_new_size);
temp* part_print(temp* a, int n, const char* b, int mode, int* x, int* total);