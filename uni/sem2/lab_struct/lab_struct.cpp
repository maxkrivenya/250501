#include "structs.h"

int main() {
	int cont = 1; int n = 1; temp* a_new = NULL; int a_new_size = 0;
	FILE* fptr = file("input.txt", "r"); fileprint(fptr);
	temp* a = alloc();
	a = fstruct(a, fptr, &n);
	do {
		a_new_size = 0;
		a_new = labstep1(a, n, &cont, &a_new_size);
	} while (!cont);
	bout(a, "structs.bin", n);
	free(a_new);
	//free(a);
	return 0;
}