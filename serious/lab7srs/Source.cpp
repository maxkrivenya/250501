#include "please_work.h"
void strinput(char* mom, int a, int num) {  
	printf("input string %d ", a-1);
	rewind(stdin);
	fgets(mom, num, stdin);
}   
//считывание строки

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
//выделение памяти под массив строк переменного размера

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
//выделение памяти под массив строк через аргументы командной строки

char** strtoword(char** p, int* A, int i)
{
    int j = 0, end = 0, j = strlen(p[i]) - 1;
    if (j == 0)
        i--;
    else
        while (j > 0) {

            while (!isalpha(p[i][j]))
                j--;
            end = j; 

            //for (j; j > 0 && isalpha(p[i][j - 1]); j--);
            //j = j;

            if (j > 0) {
                (*A)++;
                p = (char**)realloc(p, *A * sizeof(char*));
                p[*A - 1] = (char*)calloc(end - j + 3, sizeof(char));
                for (int k = 0; k < end - j + 2; k++)
                    p[*A - 1][k] = p[i][j + k];
                p[*A - 1][end - j + 2] = '\0';
                p[i][j] = '\0';
                p[i] = (char*)realloc(p[i], (j + 1) * sizeof(char));
            }

            if (j == 0)
                i--;

            j--;
        }

    if (i >= 0)
        p = strtoword(p, A, i);

    return p;
}
//преобразование массива строк в массив слов

void arrprint(char** str, int n) {

    printf("Printing out the array...\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", mystrlen(str[i]));
        for (int j = 0; j < strlen(str[i]) - 1; j++) 
            printf("%c", str[i][j]);
        printf("\n");
    }
}
//вывод массива на экран

void strsort(char** p, int n)
{
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (strlen(p[j]) > strlen(p[j + 1]))
            {
                strswitch(&p[j], &p[j+1]);
            }

}
//сортировка массива строк по длине

void bye() {
    printf("\nEnd of program.");
}
//функция прощания с пользователем