#include "Header.h"
char roth_mult(char a, char b)
{
	if (a == b)
		return a;

	else
		if (isdigit(a))
			if (isdigit(b))
				return 'y';
			else
				return a;
		else
			return b;
}

char roth_sub(char a, char b)
{
	if (a == b)
		return 'Z';
	else {

		if ((a == '0' && b == '1') or (a == '1' && b == '0'))
			return 'y';

		if (b == 'x')
			return 'Z';

		if (a == 'x') {

			if (b == '0')
				return '1';
			if (b == '1')
				return '0';
		}
	}
}

char* raw_sub(char* a, char* b) {
	char* c = (char*)calloc(size, 1);
	for (int i = 0; i < size; i++)
		c[i] = roth_sub(a[i], b[i]);
	return c;
}

char* simple_sub(char* x, char* b) {
	char* a = (char*)calloc(size, 1);
	for (int i = 0; i < size; i++)
		a[i] = roth_sub(x[i], b[i]);
	if (Zcount(a) == size)
		for (int i = 0; i < size; i++)
			a[i] = '\0';
	else
		for (int i = 0; i < size; i++)
			if (a[i] == 'Z' or a[i] == 'y')
				a[i] = x[i];
	return a;
}

char roth_over(char a, char b) {
	if (a != ' ' && b != ' ') {
		if (a == b)
			return a;

		else
			if (isdigit(a))
				if (isdigit(b))
					return 'E';
				else
					return a;
			else
				return b;
	}
	else return ' ';
}

char* over(char* a, char* b) {
	char* c = (char*)calloc(size, 1);
	int i = 0;
	for (i; i < size; i++) {
		c[i] = roth_over(a[i], b[i]);
		if (c[i] == 'E') {
			for (int j = 0; j < size; j++)
				c[j] = '\0';
			i = size + 1;
		}
	}

	return c;
}



void table() {//UNFISHED
	int rest_size = L_size;
	char** rest = char2(rest_size);

	//char**** Q = (char****)calloc(Z_size, sizeof(char***));
	//for (int i = 0; i < Z_size; i++) {
	//	Q[i] = (char***)calloc(Z_size, sizeof(char**));
	//	for (int j = 0; j < Z_size; j++) {
	//		Q[i][j] = (char**)calloc(1, sizeof(char*));
	//		Q[i][j][0] = (char*)calloc(size, 1);
	//	}
	//}
	//char* temp = (char*)calloc(size, 1);
	//for (int i = 0; i < Z_size; i++) {
	//	int div = 1;
	//	for (int j = 0; j < Z_size; j++)
	//		if (j != i) {
	//			for (int k = 0; k < div; k++) {
	//				temp = raw_sub(Q[i][j][k], Z[i]);
	//				if (numcount(temp)) {
	//					if (div < numcount(temp)) {
	//						int newdiv = numcount(temp);
	//						Q[i][j] = (char**)realloc(Q[i][j], newdiv * sizeof(char*));
	//						for (int m = div; m < newdiv; m++)
	//							Q[i][j][m] = (char*)calloc(size, 1);
	//						div = newdiv;
	//						for (int m = 0; m < div; m++)
	//							Q[i][j][m] = z_remove_times(temp, Q[i][j][k], m);

	//					}
	//				}
	//				else
	//					for (int m = 0; m < size; m++)
	//						Q[i][j][k][m] = '\0';
	//			}

	//		}
	//}
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
}