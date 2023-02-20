#include "please_work.h"

int mystrlen(char* str) {
	int a = 0;
	while (str[a] != '\0')
		a++;
	return a;
}
//длина строки 

char* mystrcpy(char* str1, char* str2) {

	char* tmp = (char*)calloc(mystrlen(str2), sizeof(char));
	tmp[mystrlen(str2)-1] = '\0';

	for (int i = 0; i < strlen(str2); i++)
		tmp[i] = str2[i];
	str1 = tmp;

	return str1;
}
//копирование строки 

void strswitch(char** str1, char** str2) {
	char* temp = *str2;
	*str2 = *str1;
	*str1 = temp;
}
//перемена местами двух строк
