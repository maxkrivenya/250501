#include "roth.h"

char** roth_step_1(char** c, int C_size, int* Z_size, int prev_depth) {

	char** Z = (char**)calloc(1, sizeof(char*));					//local rest declare
	Z[0] = (char*)calloc(size, 1);									//local rest alloc
	int depth = prev_depth;											//receiving depth
	
	int A_size = 0;													//A size declare
	char** A = (char**)calloc(1, sizeof(char*));					//A alloc
	A[0] = (char*)calloc(size, 1);									//A[0] alloc

	begin_print(c, C_size);											//C printout

	int* simplified = (int*)calloc(C_size, sizeof(int));			//array of 0 for Z[i] and 1 for C[i+1]
	for (int i = 0; i < C_size; i++)				
		simplified[i] = 0;											//starting with 0s

	char*** Cnew = char3(C_size, C_size);							//table alloc
	for (int i = 1; i < C_size; i++)								//table fill-in
		for (int j = i - 1; j >= 0; j--) {							//filling half-table

			int flg = 0;											//flag for producing a new implicant
			Cnew[i][j] = froth1(c[i], c[j], simplified + i, simplified + j, &A_size, &flg);		//filling in the Cnew table

			if (flg) {																			//if a new implicant was produced
				A = (char**)realloc(A, A_size * sizeof(char*));									//realloc A
				A[A_size - 1] = (char*)calloc(size, 1);											//realloc A[A_size-1]
				A[A_size - 1] = strcpyy(A[A_size - 1], Cnew[i][j]);								//copy the new implicant to A
			}
		}

	for (int i = 0; i < C_size; i++)								//diagonal print
		for (int j = 0; j < size; j++)
			Cnew[i][i][j] = '-';


	int Z_size_local = 0;											//declare local Z size
	for (int i = 0; i < C_size; i++)
		if (!simplified[i])
			Z_size_local++;											//local Z size based on simplified[]

	//*Z_size = Z_size_local;											//returning Z_size_local

	if (Z_size_local) {												//if Z exists locally
		Z = (char**)calloc(Z_size_local, sizeof(char*));			//Z alloc 
		for (int i = 0; i < Z_size_local; i++)		
			Z[i] = (char*)calloc(size, 1);							//Z[i] alloc
		int j = 0;
		for (int i = 0; i < C_size; i++)							//copying Z elements from C to Z
			if (!simplified[i]) {
				Z[j] = strcpyy(Z[j], c[i]);
				j++;
			}
	}


	table_print(Cnew, c, C_size, depth);							//table print

	for (int i = 0; i < C_size; i++) {
		for (int j = 0; j < C_size; j++)
			free(Cnew[i][j]);
		free(Cnew[i]);
	}
	free(Cnew);
	A = repeat_check(A, &A_size);
	printf("\n");
	printing(C_size, A_size, simplified);
	free(simplified);
	depth++;
	printf("\n\n\n");

	int Zi_size = 0;

	if (A_size > 1) {
		char** Zi = roth_step_1(A, A_size, &Zi_size, depth);	//receiving Z[i+1]
		Z = merge(Z, Zi, &Z_size_local, Zi_size);				//merging Z[i] and Z[i+1]
	}
	if (A_size == 1) {
		Z_size_local++;
		Z = (char**)realloc(Z, Z_size_local * sizeof(char*));
		Z[Z_size_local - 1] = (char*)calloc(size, 1);
		strcpyy(Z[Z_size_local - 1], A[0]);
	}
	*Z_size = Z_size_local;										//returning Z[i] size 


	return Z;													//returning Z[i]
}

void roth_step_2(char*** L_main, char*** Z_main, int* L_size_main, int* Z_size_main) {
	printf("\nStarted step two.\n");

	char** Z = *Z_main; char** L = *L_main;							//receiving values from addresses
	int L_size = *L_size_main;										//receiving values from addresses
	int Z_size = *Z_size_main;										//receiving values from addresses


	//operating here


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



	//operating here

	char** E = char2(1);															//E alloc
	int E_size = 1;																	//E_size declare
	if (flg) {																		//if Z produced a rest

		int* rest_important = (int*)calloc(Z_size, sizeof(int));					//important rests alloc
		for (int i = 0; i < Z_size; i++)
			rest_important[i] = 0;

		printf("\n\nZuL\t"); print_top(L, L_size);									//table of checking if rests are important
		for (int i = 0; i < Z_size; i++)											//
			for (int k = 0; k < rest_size[i]; k++) {								//
				if (rest[i][k][0]) {												//
					print(rest[i][k]);												//
					for (int j = 0; j < L_size; j++) {								//
						char* c = over(rest[i][k], L[j]);							//
						if (c[0])													//		//if rest[i] OVER L produced something, rest_important[i] = 1
							rest_important[i] = 1;									//
																					//
						print(c);													//
					}																//
					printf("\n");													//
				}																	//
			}																		//table of checking if rests are important


		printf("\nThe following simple implicants are included into E:\t");
		for (int i = 0; i < Z_size; i++)											//copying L-extremals to E
			if (rest_important[i]) {
				print(Z[i]);
				E_size++;
				E = (char**)realloc(E, E_size * sizeof(char*));
				E[E_size - 1] = (char*)calloc(size, 1);
				E[E_size - 2] = strcpyy(E[E_size - 2], Z[i]);
			}
	}
	else {
				printf("\nZ:\t\n");
				arrprint(Z, Z_size);
		Z = x_sort(Z, Z_size);
				printf("\nZ:\t\n");
				arrprint(Z, Z_size);
		E[0] = strcpyy(E[0], Z[0]);

	}

	char*** C = char3(E_size, L_size);							//L#E table alloc
	printf("\n\nL#E\t"); print_top(L, L_size);
	print(E[0]);

	for (int i = 0; i < L_size; i++) {							//L#E table fill-in and print
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
			C[i][j] = simple_sub(C[i - 1][j], E[i]);
			if (C[i - 1][j][0] == '\0')
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
		print(C[E_size - 1][i]);
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

	E = repeat_check(E, &EE_size);
	printf("\n\nMinimal DNF is: ");									//result printout
	for (int i = 0; i < EE_size - 1; i++) {
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

	*L_main = L;
	*Z_main = Z;
	*L_size_main = L_size;
	*Z_size_main = Z_size;
}