#include"roth.h"
int main (){
	int L_size = 7;	int C_size = 12; int Z_size = 0; int Zi_size = 0;
	char** c = char2(C_size); char** L = char2(L_size);
	FILE* fptr = open_read("input.txt");

	for (int i = 0; i < C_size; i++) {
		for (int j = 0; j < size; j++) {
			c[i][j] = getc(fptr);
			if (i < L_size)
				L[i][j] = c[i][j];
		}
		char temp = fgetc(fptr);
	}
	fclose(fptr);

	char** Zi = roth_step_1(c, C_size, &Zi_size, 0);
	char** Z = (char**)calloc(1, sizeof(char*));
	Z[0] = (char*)calloc(size, 1);
	Z = merge(Z, Zi, &Z_size, Zi_size);
	printf("\nThere are % d simple implicants : ", Z_size);	arrprint(Z, Z_size);
	printf("\nStep one finished.\n");
	roth_step_2( L, Z, L_size, Z_size);
	return 0;
}