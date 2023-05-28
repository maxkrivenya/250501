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
			Cnew[i][j] = (char*)calloc(size + 1, 1);
	return Cnew;
}


char** char2(int a) {
	char** c = (char**)calloc(a, sizeof(char*));
	for (int i = 0; i < a; i++)
		c[i] = (char*)calloc(size + 1, 1);
	return c;
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

char** repeat_check(char** a, int* x) {
	int n = *x;
	for (int i = n-2; i >=0; i--)
		for (int j = i+1; j < n; j++)
			if (strcmpp(a[i], a[j])) {
				strshift(a, n, j);
				n--;
				a = (char**)realloc(a, n * sizeof(char**));
			}
	*x = n;
	return a;

}

char** strshift(char** a, int n, int k) {
	for (int i = k; i < n-1; i++)
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


char* dectobin(char* a) {
	char* temp = (char*)calloc(size + 1, 1);
	int dec = atoi(a);
	int j = size - 1;
	int bruh = 1;
	for (int i = 0; i < size; i++) {
		temp[i] = '0';
		bruh = 1;
		for (int k = 0; k < j; k++)
			bruh *= 2;
		if (dec - bruh >= 0) {
			dec -= bruh;
			temp[i] = '1';
		}
		j--;
	}
	return temp;
}

char* strcpyy(char* a, char* b) {
	for (int i = 0; i < size; i++)
		a[i] = b[i];
	return a;
}


int strcmpp(char* a, char* b) {
	int same = 1;
	for (int i = 0; i < size; i++)
		if (a[i] != b[i])
			same = 0;
	return same;
}

int str_found(char* a, char** b, int c) {
	for (int i = 0; i < c; i++)
		if (strcmpp(a, b[i]))
			return 1;
	return 0;
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

void file_input(int C_size, int L_size, char*** c_main, char*** l_main) {
	char** c = char2(C_size); char** L = char2(L_size);

	FILE* fptr = open_read("input.txt");
	for (int i = 0; i < C_size; i++) {
		fgets(c[i], size - 1, fptr);
		if (!isdigit(c[i][0]))
			fgets(c[i], size - 1, fptr);
		if (!isdigit(c[i][0])) {
			printf("invalid reading from file");
			exit(2);
		}
		c[i] = dectobin(c[i]);
		if (i < L_size)
			L[i] = strcpyy(L[i], c[i]);
	}
	fclose(fptr);
	*c_main = c;
	*l_main = L;
}