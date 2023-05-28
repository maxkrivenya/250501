#include"roth.h"

int main() {
	int L_size = 16;int C_size = 40;
	int Z_size = 0; int Zi_size = 0;
	char** c = char2(C_size); char** L = char2(L_size);
	FILE* fptr = open_read("input.txt");
	for (int i = 0; i < C_size; i++) {
		fgets(c[i], size-1, fptr);
		if (!isdigit(c[i][0]))
			fgets(c[i], size-1, fptr);
		if (!isdigit(c[i][0])) {
			printf("invalid reading from file");
			exit(2);
		}
		c[i] = dectobin(c[i]);
		if (i < L_size)
			L[i] = strcpyy(L[i], c[i]);
	}
	fclose(fptr);

	char** Zi = roth_step_1(c, C_size, &Zi_size, 0);
	char** Z = (char**)calloc(1, sizeof(char*));
	Z[0] = (char*)calloc(size, 1);
	Z = merge(Z, Zi, &Z_size, Zi_size);

 	printf("\nThere are % d simple implicants : ", Z_size);	arrprint(Z, Z_size);
	printf("\nStep one finished.\n");

	roth_step_2(&L, &Z, &L_size, &Z_size);

	for (int i = 0; i < L_size; i++)
		free(L[i]);
	free(L);
	for (int i = 0; i < Z_size; i++)
		free(Z[i]);
	free(Z);

	return 0;
}