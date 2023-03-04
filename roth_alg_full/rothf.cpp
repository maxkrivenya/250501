#include "roth.h"

char* froth1(char* a, char* b, int* n, int* n2, int* Acount, int* flg){
	int y_num = 0; int flag = *flg; int bruh = 0;
	char* str = (char*)calloc(size, 1);

	for (int i = 0; i < size; i++)
		if ((a[i] == 'x' && b[i] != 'x') or (a[i] != 'x' && b[i] == 'x'))
			bruh++;
	if (bruh) {
		for (int i = 0; i < size; i++)
			str[i] = ' ';
		return str;
	}


	for (int i = 0; i < size; i++) {
		str[i] = roth_mult(a[i], b[i]);
		if (str[i] == 'y') {
			y_num++;
			str[i] = 'x';
		}
	}
	if (y_num == 1) {
		flag = 1;
		*flg = flag;
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

int Zcount(char* a) {
	int b = 0;
	for (int i = 0; i < size; i++)
		if (a[i] == 'Z')
			b++;
	return b;
}

int numcount(char* a) {
	int b = 0;
	for (int i = 0; i < size; i++)
		if (isdigit(a[i]))
			b++;
	return b;
}

char* z_remove(char* a, char* b) {
	for (int i = 0; i < size; i++)
		if (a[i] = 'Z')
			a[i] = b[i];
	return a;
}

char* z_remove_times(char* a, char* b, int m) {
	int c = m;
	for (int i = 0; i < size; i++)
		if (isdigit(a[i]))
			if (c != 0) {
				c--;
				a[i] = b[i];
			}
	return a;
}
//
//char* froth2(char* a, char* b) {
//
//
//	return row;
//}

char** roth_step_1(char** c, int C_size, int* Z_size, int e) {
	char** Z = (char**)calloc(1, sizeof(char*));
	Z[0] = (char*)calloc(size, 1);
	int o = e;
	int A_size = 0;
	char** A = (char**)calloc(1, sizeof(char*));					//A[i] memalloc
	A[0] = (char*)calloc(size, 1);
	begin_print(c, C_size);
	int* q = (int*)calloc(C_size, sizeof(int));						//checking for simple implicants
	for (int i = 0; i < C_size; i++)
		q[i] = 0;
	char*** Cnew = char3(C_size, C_size);
	for (int i = 1; i < C_size; i++)								//table fill-in
		for (int j = i - 1; j >= 0; j--) {
			int flg = 0;
			Cnew[i][j] = froth1(c[i], c[j], q + i, q + j, &A_size, &flg);
			if (flg) {
				A = (char**)realloc(A, A_size * sizeof(char*));
				A[A_size - 1] = (char*)calloc(size, 1);
				A[A_size - 1] = strcpyy(A[A_size - 1], Cnew[i][j]);
			}
		}
	for (int i = 0; i < C_size; i++)								//diagonal
		for (int j = 0; j < size; j++)
			Cnew[i][i][j] = '-';
	int n = 0;
	for (int i = 0; i < C_size; i++)
		if (q[i] == 0)
			n++;
	*Z_size = n;
	if (n) {
		Z = (char**)calloc(n, sizeof(char*));
		for (int i = 0; i < n; i++)
			Z[i] = (char*)calloc(size, 1);
		int w = 0;
		for (int i = 0; i < C_size; i++)
			if (q[i] == 0) {
				Z[w] = strcpyy(Z[w], c[i]);
				w++;
			}
	}
	table_print(Cnew, c, C_size, o);		//table print
	for (int i = 0; i < C_size; i++) {
		for (int j = 0; j < C_size; j++)
			free(Cnew[i][j]);
		free(Cnew[i]);
	}
	free(Cnew);
	repeat_check(A, &A_size);
	printf("\n");
	printing(C_size, A_size, q);
	free(q);
	o++;
	printf("\n\n\n");

	int Zi_size = 0;

	if (A_size > 1 && o < size) {
		char** Zi = roth_step_1(A, A_size, &Zi_size, o);
		Z = merge(Z, Zi, &n, Zi_size);
	}
	*Z_size = n;

	//printf("\nSimple Implicants:");
	//for (int i = 0; i < n; i++) {
	//	printf("\tZ[%d] - ", i);
	//	print(Z[i]);
	//}
	//printf("\n\n");

	return Z;
}

void roth_step_2(char** L, char** Z, int L_size, int Z_size) {
	printf("\nStarted step two.\n");
	int E_size = 0;

	int rest_size = L_size;
	char** rest = char2(rest_size);

	//UNFINISHED

	//for()
















	//UNFINISHED


	//for (int i = 0; i < L_size; i++) {
	//	C[0][i] = simple_sub(L[i], E[0]);
	//	print(C[0][i]);
	//	if (C[0][i][0] == '\0')
	//		for (int k = 0; k < size; k++)
	//			L[i][k] = '\0';
	//}

////int* L_covered = (int*)calloc(L_size, sizeof(int));
////for (int i = 0; i < L_size; i++)
////	L_covered[i] = 0;





	//temporary
	FILE* fptr = open_read("temp.txt");
	for (int i = 0; i < rest_size; i++) {
		for (int j = 0; j < size; j++) 
			rest[i][j] = getc(fptr);
		char temp = fgetc(fptr);
	}
	//temporary
	

	int* rest_important = (int*)calloc(L_size, sizeof(int));
	for (int i = 0; i < L_size; i++)
		rest_important[i] = 0;

	
	printf("\n\nZuL\t"); print_top(L, L_size);
	for (int i = 0; i < rest_size; i++) {
		if (rest[i][0] != ' ') {
			print(rest[i]);
			for (int j = 0; j < L_size; j++) {
				 char* c = over(rest[i], L[j]);
				if (c[0])
					rest_important[i] = 1;

				print(c);
			}
			printf("\n");
		}
	}
	char** E = char2(1);
	printf("\nThe following simple implicants are included into E:\t");
	for (int i = 0; i < L_size; i++)
		if (rest_important[i]) {
			print(Z[i]);
			E_size++;
			E = (char**)realloc(E, E_size * sizeof(char*));
			E[E_size - 1] = (char*)calloc(size, 1);
			E[E_size - 1] = strcpyy(E[E_size - 1], Z[i]);
		}


	char*** C = char3(E_size, L_size);
	printf("\n\nL#E\t"); print_top(L, L_size);
	print(E[0]);
	for (int i = 0; i < L_size; i++) {
		C[0][i] = simple_sub(L[i], E[0]);
		print(C[0][i]);
		if (C[0][i][0] == '\0')
			for (int k = 0; k < size; k++)
				L[i][k] = '\0';
	}
	printf("\n");
	for (int i = 1; i < E_size; i++) {
		print(E[i]);
		for (int j = 0; j < L_size; j++) {
			C[i][j] = simple_sub(C[i-1][j], E[i]);
			if (C[i-1][j][0] == '\0')
				for (int k = 0; k < size; k++)
					C[i][j][k] = '\0';
			print(C[i][j]);
		}
		printf("\n");
	}	

	printf("\nresults:");
	char** L1 = char2(1);
	int	L1_size = 0;
	for (int i = 0; i < L_size; i++) {
		printf("\n[%d] - ", i); 
		print(C[E_size-1][i]);
		if (C[E_size - 1][i][0]) {
			L1_size++;
			L1 = (char**)realloc(L1, L1_size * sizeof(char*));
			L1[L1_size - 1] = (char*)calloc(size, 1);
			L1[L1_size - 1] = strcpyy(L1[L1_size - 1], C[E_size - 1][i]);
		}
	}
	printf("\n\n");
	for (int i = 0; i < E_size; i++)
		for (int j = 0; j < Z_size; j++)
			if (strcmpp(E[i], Z[j]))
				del(Z, &Z_size, j);
	printf("Z^ :\t"); for (int i = 0; i < Z_size; i++) print(Z[i]); printf("\n");
	char*** add = char3(L1_size, Z_size);
	for (int i = 0; i < L1_size; i++)								//table fill-in
		for (int j = 0; j < Z_size; j++) 
			add[i][j] = over(L1[i], Z[j]);
	printf("\n\nFinal Table:\n");
	printf("\nZ^uL1\t");												//table print
	for (int i = 0; i < Z_size; i++)								//
		print(Z[i]);												//
	printf("\n\n");													//
	for (int i = 0; i < L1_size; i++) {								//
		print(L1[i]);												//
		for (int j = 0; j < Z_size; j++)							//
			print(add[i][j]);										//
		printf("\n");												//
	}
	printf("\n\nMinimal DNF is: ");
	for (int i = 0; i < E_size-1; i++) {
		for (int j = 0; j < size; j++)
			printf("%c", E[i][j]);
		printf(" + ");
	}
	print(E[E_size - 1]);
	printf("\n\n");
}