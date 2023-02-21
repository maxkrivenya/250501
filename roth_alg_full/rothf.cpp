#include "roth.h"

char* roth_mult(char*a, char*b) {
	char* c = (char*)calloc(4, 1);
	for (int i = 0; i < 4; i++)
		c[i] = '1';
	return c;
}