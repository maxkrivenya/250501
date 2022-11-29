#include <stdio.h>
#include <stdlib.h>
#include "maxf.h"
int main()
{
	int l, j = 0;
	int* p1;
	int** p;
	printf("input l ");
	scanf_s("%d", &l);
	//memalloc(p, l);
	p = (int**)calloc(l * l, sizeof(int**));
	for (int i = 0; i < l; i++) p[i] = (int*)calloc(l, sizeof(int));
	arrscan(p, l);
	arrprint(p, l);
	latinf(p, l);
	return 0;
}