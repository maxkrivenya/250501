#include "stack.h"

FILE* file(const char* a, const char* b) {
	FILE* fptr = NULL;
	fopen_s(&fptr, a, b);
	if (fptr == NULL) {
		printf("file open error");
		exit(1);
	}
	return fptr;
}

char* input(const char* a, const char* b) {
	char* str = (char*)calloc(101, 1);
	FILE* fptr = file(a, b);
	fgets(str, 100, fptr);
	fclose(fptr);
	return str;
}