#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size 5
char* froth(char* a, char* b, int*, int*, int*);
char roth_mult(char a, char b);
char roth_sub(char a, char b);
char roth_over(char a, char b);
char* roth_check(char* a, char* b);
char*** del(char***, int* n, int);
void print(char*);