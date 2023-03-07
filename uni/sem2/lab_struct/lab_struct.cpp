#include "structs.h"

int main() {
	int cont = 1; int n = 1;
	FILE* fptr = file("input.txt", "r"); fileprint(fptr);
	temp* a = alloc();
	a = fstruct(a, fptr, &n);
	do {
		const char* c = getsf();
		printf("Please input 0 for the goods or 1 for the country.\t");
		int mode = getnum();
		printf("\nTotal goods amount is %d\n", part_print(a, n, c, mode));
		prog_end(&cont);
	} while (!cont);
	freopen_s(&fptr, "structs.bin", "w", fptr);
	binprint(a, n, fptr);
	free(a); 
	freopen_s(&fptr, "structs.bin", "r", fptr);
	a = bin_read(n, fptr);
	arrprint(a, n);
	fclose(fptr);
	return 0;
}