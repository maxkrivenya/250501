#include "please_work.h"
void strinput(char* mom, int a, int num) {
	printf("input string %d ", a-1);
	rewind(stdin);
	fgets(mom, num, stdin);
}

char** stralloc(int n, ...) {
	int a = 1;
	int* p = &n + 2;
	char** str = (char**)calloc(a, sizeof(char*));

	for (p; n > 0 ; n--) {

		str = (char**)realloc(str, a * sizeof(char*));
		*(str + a - 1) = (char*)calloc(*p, sizeof(char));
		str[a-1][*p-1] = '\0';
		strinput(str[a - 1], a, *p);
		
		a++;
		p += 2;
	}

	return str;
}

char** argalloc(int a, char** argv) {
    char** p = (char**)calloc(a, sizeof(char*));
    for (int i = a; i > 0; i--)
    {     
        p[i - 1] = (char*)calloc(atoi(argv[i]), sizeof(char));
        p[i - 1][atoi(argv[i]) - 1] = '\0';
        strinput(p[i - 1], i, atoi(argv[i]));
    }

    return p;
}

char** strtoword(char** p, int* A, int i)
{
    int beg = 0, end = 0, j = strlen(p[i]) - 1;
    if (j == 0)
        i--;
    else
        while (j > 0) {

            while (!isalpha(p[i][j]))
                j--;
            end = j; 

            for (j; j > 0 && isalpha(p[i][j - 1]); j--);
            beg = j;

            if (beg > 0) {
                (*A)++;
                p = (char**)realloc(p, *A * sizeof(char*));
                p[*A - 1] = (char*)calloc(end - beg + 3, sizeof(char));
                for (int k = 0; k < end - beg + 2; k++)
                    p[*A - 1][k] = p[i][beg + k];
                p[*A - 1][end - beg + 2] = '\0';
                p[i][beg] = '\0';
                p[i] = (char*)realloc(p[i], (beg + 1) * sizeof(char));
            }

            if (beg == 0)
                i--;

            j--;
        }

    if (i >= 0)
        p = strtoword(p, A, i);

    return p;
}

void arrprint(char** str, int n) {

    printf("Printing out the array...\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", mystrlen(str[i]));
        for (int j = 0; j < strlen(str[i]) - 1; j++) 
            printf("%c", str[i][j]);
        printf("\n");
    }
}

void strsort(char** p, int n)
{
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (strlen(p[j]) > strlen(p[j + 1]))
            {
                strswitch(&p[j], &p[j+1]);
            }

}

void bye() {
    printf("\nEnd of program.");
}