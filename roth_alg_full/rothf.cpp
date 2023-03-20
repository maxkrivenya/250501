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

char* random_z_remove(char* a) {
	for (int i = 0; i < size; i++)
		if (a[i] == 'Z')
			a[i] = 'x';
	return a;
}

int z_count(char* a) {
	int b = 0;
	for (int i = 0; i < size; i++)
		if (a[i] == 'Z')
			b++;
	return b;
}

int x_count(char* a) {
	int b = 0;
	for (int i = 0; i < size; i++)
		if (a[i] == 'x')
			b++;
	return b;
}

int y_count(char* a) {
	int b = 0;
	for (int i = 0; i < size; i++)
		if (a[i] == 'y')
			b++;
	return b;
}

int num_count(char* a) {
	int b = 0;
	for (int i = 0; i < size; i++)
		if (isdigit(a[i]))
			b++;
	return b;
}

char* z_remove(char* a, char* b) {
	for (int i = 0; i < size; i++)
		if (a[i] == 'Z') {
			a[i] = b[i];
		}
	return a;
}

char* z_remove_times(char* _temp, char* _origin, int m) {
	int c = m;
	char* d = (char*)calloc(size, 1);
	for (int i = 0; i < size; i++) {
		if (isdigit(_temp[i])) {
			if (c != 0) {
				c--;
				d[i] = 'Z';
			}
			else {
				c--;
				d[i] = _temp[i];
			}
		}
		else
			d[i] = 'Z';
	}
	d = z_remove(d, _origin);
	return d;
}

char** x_sort(char** x, int s) {
	int j = 0; int max = 0;
	for (int i = 0; i < s; i++)
		if (x_count(x[i]) > max) {
			j = i;
			max = x_count(x[i]);
		}
	for (int i = j - 1; i >= 0; i--)
		x[i + 1] = x[i];
	x[0] = strcpyy(x[0], x[j]);
	return x;
}

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

void roth_step_2(char*** A, char*** B, int* br, int* fr) {
	printf("\nStarted step two.\n");

	char** Z = *B; char** L = *A;
	int L_size = *br;
	int Z_size = *fr;
	int* rest_size = (int*)calloc(Z_size, sizeof(int));
	for (int i = 0; i < Z_size; i++)
		rest_size[i] = 1;
	char*** rest = (char***)calloc(Z_size, sizeof(char**));

	//UNFINISHED
	char* temp = (char*)calloc(size, 1);
	for (int i = 0; i < Z_size; i++) {
		printf("\n"); print(Z[i]);
		char** row = char2(1);
		int n = 1;
		row[0] = strcpyy(row[0], Z[i]);
		//temp = strcpyy(temp, row[0]);
		for (int j = 0; j < Z_size; j++) {
			if (j != i) {
				for (int k = 0; k < n; k++) {
					temp = raw_sub(row[k], Z[j]);
					if (z_count(temp) != size) {
						if (!y_count(temp)) {
							int new_n = num_count(temp);
							if (new_n != n) {
								row = (char**)realloc(row, new_n * sizeof(char*));
								for (int l = n; l < new_n; l++)
									row[l] = (char*)calloc(size, 1);
								n = new_n;
							}
							for (int l = 0; l < n; l++)
								row[l] = z_remove_times(temp, row[l], l);
						}
					}
					else {
						for (int l = 0; l < size; l++)
							row[k][l] = '\0';
						for (int m = k; m < n - 1; m++)
							row[m] = strcpyy(row[m], row[m + 1]);
						n--;
						row = (char**)realloc(row, n * sizeof(char*));
						if (!n)
							j = Z_size;
					}
					printf(" ("); for (int l = 0; l < n; l++) prin(row[l]); printf(")");
				}
				printf("\t");
			}
		}
		rest[i] = char2(n);
		rest_size[i] = n;
		for (int j = 0; j < n; j++) {
			rest[i][j] = strcpyy(rest[i][j], random_z_remove(row[j]));
			free(row[j]);
		}
		free(row);
		printf("\t\trest:(\t");
		for (int l = 0; l < rest_size[i]; l++)
			print(rest[i][l]);
		printf(")\n");
	}
	free(temp);
	//UNFINISHED
	for (int i = 0; i < Z_size; i++) {
		printf("\nrest[%d]:\t", i);
		for (int j = 0; j < rest_size[i]; j++)
			print(rest[i][j]);
	}

	bool flg = false; 
	for (int i = 0; i < Z_size; i++)
		for (int j = 0; j < rest_size[i]; j++)
			if (rest[i][j][0] != '\0')
				flg = true;

	char** E = char2(1);
	int E_size = 1;
	if (flg) {

		int* rest_important = (int*)calloc(Z_size, sizeof(int));
		for (int i = 0; i < Z_size; i++)
			rest_important[i] = 0;

		printf("\n\nZuL\t"); print_top(L, L_size);
		for (int i = 0; i < Z_size; i++)
			for (int k = 0; k < rest_size[i]; k++) {
				if (rest[i][k][0]) {
					print(rest[i][k]);
					for (int j = 0; j < L_size; j++) {
						char* c = over(rest[i][k], L[j]);
						if (c[0])
							rest_important[i] = 1;

						print(c);
					}
					printf("\n");
				}
			}


		printf("\nThe following simple implicants are included into E:\t");
		for (int i = 0; i < Z_size; i++)
			if (rest_important[i]) {
				print(Z[i]);
				E_size++;
				E = (char**)realloc(E, E_size * sizeof(char*));
				E[E_size - 1] = (char*)calloc(size, 1);
				E[E_size - 2] = strcpyy(E[E_size - 2], Z[i]);
			}
	}
	else {
//		printf("\nZ:\t\n");
//		arrprint(Z, Z_size);
		Z = x_sort(Z, Z_size);
//		printf("\nZ:\t\n");
//		arrprint(Z, Z_size);
		E[0] = strcpyy(E[0], Z[0]);

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
	char** Zi = char2(Z_size);
	int Zi_size = 0;
		for (int j = 0; j < Z_size; j++)
			if (!str_found(Z[j], E, E_size)) {
				Zi[Zi_size] = strcpyy(Zi[Zi_size], Z[j]);
				Zi_size++;
			}


		Zi = (char**)realloc(Zi, Zi_size * sizeof(char*));
		Zi = repeat_check(Zi, &Zi_size);
		int EE_size = E_size;
	printf("Z^ :\t"); for (int i = 0; i < Zi_size; i++) print(Zi[i]); printf("\n");
	char*** add = char3(L1_size, Zi_size);
	for (int i = 0; i < L1_size; i++) {	
		int sex = 0; int sexy = 0;									//table fill-in
		for (int j = 0; j < Zi_size; j++) {
			add[i][j] = over(L1[i], Zi[j]);
			if (add[i][j][0]) {
				sex++;
				sexy = j;
			}
		}
		if (sex == 1) {
			EE_size++;
			E = (char**)realloc(E, EE_size * sizeof(char*));
			E[EE_size - 1] = (char*)calloc(size, 1);
			E[EE_size - 2] = strcpyy(E[EE_size - 2], Zi[sexy]);
		}
	}


	printf("\n\nFinal Table:\n");
	printf("\nZ^uL1\t");												//table print
	for (int i = 0; i < Zi_size; i++)								//
		print(Zi[i]);												//
	printf("\n\n");													//
	for (int i = 0; i < L1_size; i++) {								//
		print(L1[i]);												//
		for (int j = 0; j < Zi_size; j++)							//
			print(add[i][j]);										//
		printf("\n");												//
	}
	//int* Z_covers = (int*)calloc(Zi_size, sizeof(int));
	//char* temp = (char*)calloc(size, 1);
	//for (int i = 0; i < L1_size; i++) {
	//	for(int j = 0; j < Zi_size; j++)
	//		if (add[j][i][0] != '\0') 
	//			if (x_count(add[j][i]) > x_count(temp))
	//				temp = strcpyy(temp, Zi[j]);
	//	printf("for "); print(L1[i]); printf("the covering is "); print(temp);
	//}


	E = repeat_check(E, &EE_size);
	printf("\n\nMinimal DNF is: ");
	for (int i = 0; i < EE_size-1; i++) {
		print(E[i]);
		printf(" + ");
	}
	printf("\n\n");


	for (int i = 0; i < L1_size; i++) {
		for (int j = 0; j < Zi_size; j++)
			free(add[i][j]);
		free(add[i]);
	}
	free(add);

	for (int i = 0; i < E_size; i++) {
		for (int j = 0; j < L_size; j++)
			free(C[i][j]);
		free(C[i]);
	}
	free(C);
	for (int i = 0; i < Z_size; i++) {
		for (int j = 0; j < rest_size[i]; j++)
			free(rest[i][j]);
		free(rest[i]);
	}
	free(rest);

	for (int i = 0; i < Zi_size; i++)
		free(Zi[i]);
	free(Zi);
	for (int i = 0; i < L1_size; i++)
		free(L1[i]);
	free(L1);
	for (int i = 0; i < EE_size; i++)
		free(E[i]);
	free(E);

	*A = L;
	*B = Z;
	*br = L_size;
	*fr = Z_size;
}