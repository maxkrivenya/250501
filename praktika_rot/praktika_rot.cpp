#include"roth.h"

int main() {
	int L_size = 16; int C_size = 16; int Z_size = 0;

	char** c = NULL; char** L = NULL;
	file_input(C_size, L_size, &c, &L);

	char** Z = roth_step_1(c, C_size, &Z_size, 0);

	printf("\nThere are % d simple implicants : ", Z_size);	
	arrprint(Z, Z_size);
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