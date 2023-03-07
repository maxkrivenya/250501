#include "roth.h"

FILE* open_read(const char* a) {
	FILE* fp;
	fopen_s(&fp, a, "r");
	if (fp == NULL) {
		printf("file open error");
		exit(1);
	}
	return fp;
}

char*** char3(int C_size, int D_size) {
	char*** Cnew = (char***)calloc(C_size, sizeof(char**));			//C[[i] memalloc
	for (int i = 0; i < C_size; i++)
		Cnew[i] = (char**)calloc(D_size, sizeof(char*));
	for (int i = 0; i < C_size; i++)
		for (int j = 0; j < D_size; j++)
			Cnew[i][j] = (char*)calloc(size, 1);
	return Cnew;
}

char** del(char** a, int* x, int z) {
	int n = *x;
	for (int i = z; i < n - 1; i++)
		a[i] = a[i + 1];
	n--;
	a = (char**)realloc(a, n * sizeof(char*));
	*x = n;
	return a;
}

char** char2(int a) {
	char** c = (char**)calloc(a, sizeof(char*));
	for (int i = 0; i < a; i++)
		c[i] = (char*)calloc(size, 1);
	return c;
}

char** repeat_check(char** a, int* x) {
	int n = *x;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (issame(a[i], a[j])) {
				strshift(a, n, j);
				n--;
				a = (char**)realloc(a, n * sizeof(char**));
			}
	*x = n;
	return a;

}

char** strshift(char** a, int n, int k) {
	for (int i = k; i < n - 1; i++)
		for (int j = 0; j < size; j++)
			a[i][j] = a[i + 1][j];
	return a;
}

char** merge(char** a, char** b, int* c, int d) {
	if (d) {
		int s = *c;
		s += d;
		*c = s;
		a = (char**)realloc(a, s * sizeof(char*));
		s -= d;
		for (int i = 0; i < d; i++) {
			a[s + i] = (char*)calloc(size, 1);
			a[s + i] = strcpyy(a[s + i], b[i]);
			free(b[i]);
		}
		free(b);
		return a;
	}
	else return a;
	
}

char* strcpyy(char* a, char* b) {
	for (int i = 0; i < size; i++)
		a[i] = b[i];
	return a;
}

//char* dectobin(char* a) {
//	int x = atoi(a);
//	char* b = (char*)calloc(size+1, 1);
//	for (int i = size-1; i >= 0; i--) {
//		if (x - 2 ^ i > 0) {
//			x -= 2 ^ i;
//			b[size-i] = 1;
//		}
//	}
//	return b;
//}

int strcmpp(char* a, char* b) {
	int same = 1;
	for (int i = 0; i < size; i++)
		if (a[i] != b[i])
			same = 0;
	return same;
}

int issame(char* a, char* b) {
	int flg = 0;
	for (int i = 0; i < size; i++)
		if (a[i] != b[i])
			flg++;
	if (!flg)
		return 1;
	else
		return 0;

}