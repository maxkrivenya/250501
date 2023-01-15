#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void var(int*);

char** char2fill(int);

char** char2adjust(char**, int);
char** strtoword(char**, int, int*, int);
void strsort(char**, int);
void finishup(char**, int);
void exitf(int*);