#include "please_work.h"
#define n 30

int mystrlen(char* str) {
	int a = 0;
	while (str[a] != '\0')
		a++;
	return a;
}

char* mystrcpy(char* str1, char* str2) {

	char* tmp = (char*)calloc(mystrlen(str2), sizeof(char));
	tmp[mystrlen(str2)-1] = '\0';

	for (int i = 0; i < strlen(str2); i++)
		tmp[i] = str2[i];
	str1 = tmp;

	return str1;
}

void strswitch(char** str1, char** str2) {
	char* temp = *str2;
	*str2 = *str1;
	*str1 = temp;
}


















//void mygets(char* str) {
//	int i = 0;
//	scanf_s(" %c", str);
//	i++;
//	while (str[i-1] != ' ');
//	{
//		scanf_s("%c", str + i);
//		i++;
//	}
//}
//
//void myputs(char* str) {
//	int a = 0;
//	while (str[a] != '\0')
//		printf("%c", *(str + a));
//}