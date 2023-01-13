#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "mystrings.h"
#include <string.h>

void strinput(char*, int, int);
char** stralloc(int, ...);
char** strtoword(char**, int*, int);
void arrprint(char**, int);
void strsort(char**, int);
char** char2adjust(char**, int);
char** argalloc(int, char**);
void bye();

