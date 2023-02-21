#include "roth.h"

char* roth_check(char*a, char*b) {
	char* c = (char*)calloc(size, 1);
	for (int i = 0; i < size; i++)
		c[i] = '1';
	return c;
}

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
		return 'z';
	else {

		if ((a == '0' && b == '1') or (a == '1' && b == '0'))
			return 'y';

		if (b == 'x')
			return 'z';

		if (a == 'x') {

			if (b == '0')
				return '1';
			if (b == '1')
				return '0';
		}
	}
}

char roth_over(char a, char b) {
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

char* froth(char* a, char* b, int* n, int* n2, int* Acount){
	int y_num = 0;
	char* str = (char*)calloc(size, 1);
	for (int i = 0; i < size; i++) {
		str[i] = roth_mult(a[i], b[i]);
		if (str[i] == 'y') {
			y_num++;
			str[i] = 'x';
		}
	}
	if (y_num == 1) {
		*n = 1;
		*n2 = 1;
		*Acount = *Acount + 1;
		return str;
	}
	else {
		for (int i = 0; i < size; i++)
			str[i] = ' ';
		return str;
	}
	return str;
}

char*** del(char*** a, int* x, int z) {
	int n = *x;
	for (int i = z; i < n - 1; i++)
		a[i] = a[i + 1];
	n--;
	a = (char***)realloc(a, n * sizeof(char**));
	*x = n;
	return a;
}

void print(char* c) {
	for (int i = 0; i < size; i++)
		printf("%c", c[i]);
	printf("\t");
}