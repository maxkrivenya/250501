#include <stdio.h>
#include <stdlib.h>
#include "maxf.h"
int main()
{
	int l, j = 0;
	int* p1;
	p1 = &j;
	int** p;
	p = &p1;
	printf("input l ");
	scanf_s("%d", &l);
	memalloc(p, l);
	arrscan(p, l);
	arrprint(p, l);
	latinf(p, l);
	return 0;
}