#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct FILO {
	char c;
	FILO* next;
};

FILE* file(const char* _NAME, const char* _MODE);

char* input(const char* _NAME, const char* _MODE);