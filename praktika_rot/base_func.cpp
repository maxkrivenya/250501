#include "roth.h"
char roth_mult(char a, char b)
{
	if (a == b)
		return a;

	else
		if (isdigit(a))
			if (isdigit(b))
				return 'y';
			else
				return a;
		else
			return b;
}

char roth_sub(char a, char b)
{
	if (a == b)
		return 'Z';
	else {

		if ((a == '0' && b == '1') or (a == '1' && b == '0'))
			return 'y';

		if (b == 'x')
			return 'Z';

		if (a == 'x') {

			if (b == '0')
				return '1';
			if (b == '1')
				return '0';
		}
	}
	//return '3';
}

char* raw_sub(char* a, char* b) {
	char* c = (char*)calloc(size, 1);
	for (int i = 0; i < size; i++)
		c[i] = roth_sub(a[i], b[i]);
	return c;
}

char* simple_sub(char* x, char* b) {
	char* a = (char*)calloc(size, 1);
	for (int i = 0; i < size; i++)
		a[i] = roth_sub(x[i], b[i]);
	if (z_count(a) == size)
		for (int i = 0; i < size; i++)
			a[i] = '\0';
	else
		for (int i = 0; i < size; i++)
			if (a[i] == 'Z' or a[i] == 'y')
				a[i] = x[i];
	return a;
}

char roth_over(char a, char b) {
	if (a != ' ' && b != ' ') {
		if (a == b)
			return a;

		else
			if (isdigit(a))
				if (isdigit(b))
					return 'E';
				else
					return a;
			else
				return b;
	}
	else return ' ';
}

char* over(char* a, char* b) {
	char* c = (char*)calloc(size, 1);
	int i = 0;
	for (i; i < size; i++) {
		c[i] = roth_over(a[i], b[i]);
		if (c[i] == 'E') {
			for (int j = 0; j < size; j++)
				c[j] = '\0';
			i = size + 1;
		}
	}

	return c;
}