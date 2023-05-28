#include "roth.h"

void prin(char* c) {
	for (int i = 0; i < size; i++)
		printf("%c", c[i]);
}

void print(char* c) {

	for (int i = 0; i < size; i++)
		printf("%c", c[i]);
	printf("\t");
}

void arrprint(char** a, int j) {
	for (int i = 0; i < j; i++)
		print(a[i]);
	printf("\n");
}

void table_print(char*** Cnew, char** c, int C_size, int o) {
	//////////////////////////////////////////////////////////////////
	printf("C%d*C%d\t", o, o);												//table print
	for (int i = 0; i < C_size; i++)								//
		print(c[i]);												//
	printf("\n\n");													//
	for (int i = 0; i < C_size; i++) {								//
		print(c[i]);												//
		for (int j = 0; j < C_size; j++)							//
			print(Cnew[i][j]);										//
		printf("\n");												//
	}
}

void print_top(char** L, int L_size) {
	for (int i = 0; i < L_size; i++)
		print(L[i]);
	printf("\n");
}

void printing(int C_size, int A_size, int* q) {
	for (int i = 0; i < C_size; i++)								//
		printf("%d - %d\t", i, q[i]);
	printf("A_size = %d", A_size);
}

void begin_print(char** c, int C_size) {
	printf("\n\n\n");
	for (int i = 0; i < C_size; i++) {
		printf("c[%d] -\t", i);
		for (int j = 0; j < size; j++)
			printf("%c", c[i][j]);
		printf("\n");
	}
	printf("\n");
}
