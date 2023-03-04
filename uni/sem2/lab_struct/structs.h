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
int part_print(temp* a, int n, const char* b, int mode);

char* getsf();

void fileprint(FILE*);
void prog_end(int* cont);
void arrprint(temp*, int);
void binprint(temp* a, int n, FILE* fptr);

temp* alloc();
temp* recalloc(temp*, int);
temp* fstruct(temp* a, FILE* fptr, int* n);