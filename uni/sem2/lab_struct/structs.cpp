#include "structs.h"

FILE* file(const char* a, const char* b) {
	FILE* fptr;
	fopen_s(&fptr, a, b);
	if (fptr == NULL) {
		printf("File open error (1)");
		exit(1);
	}
	return fptr;
}

int getnum() {
	int a;
	printf("Input number. ");
	scanf_s("%d", &a);
	return a;
}

int strcmpp(char* a, const char* b) {
	int flg = 1;
	for (int i = 0; i < strlen(b); i++)
		if (a[i] != b[i])
			flg = 0;
	return flg;
}

void prog_end(int* cont) {
	printf("\nType 0 to continue. ");
	scanf_s("%d", cont);
	rewind(stdin);

}

void fileprint(FILE* fptr) {
	printf("Input data:\n\n");
	do {
		char* str = (char*)calloc(81, sizeof(char));
		fgets(str, 80, fptr);
		printf("\t"); puts(str);
		free(str);
	} while (!feof(fptr));
	printf("\n");
	rewind(fptr);
}

void arrprint(temp* a, int n) {
	printf("\ngoods\t\tcountry\t\tamt\n\n");
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < size; j++)
			printf("%c", a[i].data[0][j]);
		printf("\t\t");
		for (int j = 0; j < size; j++)
			printf("%c", a[i].data[1][j]);
		printf("  \t");
		printf("%d\n", a[i].amount);
	}
	printf("\n");
}

void binprint(temp* a, int n, FILE* fptr) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < size && isalpha(a[i].data[j][k]); k++)
				fputc(a[i].data[j][k], fptr);
			fputc(' ', fptr);
		}
		fwrite(&a[i].amount, sizeof(int), 1, fptr);
		fputc(' ', fptr);
	}
}

int part_print(temp* a, int n, const char* b, int mode) {
	int total = 0;
	printf("\ngoods\t\tcountry\t\tamt\n\n");
	for (int i = 0; i < n - 1; i++)
		if (strcmpp(a[i].data[mode], b)) {
			for (int k = 0; k < 2; k++) {
				for (int j = 0; j < size; j++)
					printf("%c", a[i].data[k][j]);
				printf("\t\t");
			}
			total += a[i].amount;
			printf("%d\n", a[i].amount);
		}
	
	printf("\n");
	return total;
}

char* getsf() {
	char* c = (char*)calloc(20, sizeof(char));
	printf("Input sort parameter\t");
	fgets(c, 20, stdin);
	for (int i = 0; i < strlen(c); i++)
		if (!isalpha(c[i])) {
			c[i] = '\0';
			i = 200;
		}
	return c;
}

temp* alloc() {
	temp* a = (temp*)calloc(1, sizeof(temp));
	for (int i = 0; i < size; i++) {
		a[0].data[0][i] = '\0';
		a[0].data[1][i] = '\0';
	}
	return a;
}

temp* recalloc(temp* a, int n) {
	a = (temp*)realloc(a, n * sizeof(temp));
	for (int i = 0; i < size; i++) {
		a[n-1].data[0][i] = '\0';
		a[n-1].data[1][i] = '\0';
	}
	return a;
}

temp* fstruct(temp* a, FILE* fptr, int* n){
 int z = *n;
	for (int i = 0; !feof(fptr); i++) {
		char* str = (char*)calloc(81, sizeof(char));
		int j = 0; int k = 0;
		z++; a = recalloc(a, z);
		fgets(str, 80, fptr);
		if (str[0] != ' ') {
			do {
				a[i].data[0][k] = str[j];
				j++; k++;
			} while (str[j] != ' ');

			k = 0;
			while (!isalpha(str[j + 1])) j++;
			j++;
			do {
				a[i].data[1][k] = str[j];
				j++; k++;
			} while (str[j] != ' ');

			while (!isdigit(str[j])) j++;
			char* temp = (char*)calloc(size, sizeof(char));
			for (k = 0; isdigit(str[j]) && j < strlen(str); k++ && j++)
				temp[k] = str[j];
			temp[0] = '0';
			a[i].amount = atoi(temp);
			free(temp);
		}
		free(str);
	}
	*n = z;
	return a;
}

temp* bin_read(int n, FILE*fptr) {
	temp* a = (temp*)calloc(n, sizeof(temp));
	for (int i = 0; i < n && !feof(fptr); i++) {
		for (int j = 0; j < 2; j++) {
			do { a[i].data[j][0] = fgetc(fptr); } while (!isalpha(a[i].data[j][0]));
			for (int k = 1; k < size; k++)
				a[i].data[j][k] = fgetc(fptr);
		}
	 fscanf_s(fptr, "%d", &a[i].amount);
	}
	return a;
}