#include"roth.h"
#define n 8
#define size 4
int main (){
	char*** Cnew = (char***)calloc(n, sizeof(char**));
	for (int i = 0; i < n; i++)
		Cnew[i] = (char**)calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			Cnew[i][j] = (char*)calloc(size, 1);
	char** c = (char**)calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
		c[i] = (char*)calloc(size, 1);
	//input
	for (int i = 0; i < n; i++)
		for (int j = n-i-1; j >= 0; j--)
			Cnew[i][j] = roth_mult(c[i], c[j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < size; j++)
			Cnew[n-i-1][i][j] = '2';

	for (int i = n-1; i >= 0; i--) {
		for (int j = 0; j < n-i; j++)
		{
			for (int a = 0; a < size; a++)
				printf("%c", Cnew[i][j][a]);
			printf("\t");
		}
		printf("\n");
	}
	return 0;
}