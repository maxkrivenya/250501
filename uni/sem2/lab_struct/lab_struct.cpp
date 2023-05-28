#include "structs.h"

int main() {
	int cont = 1; int n = 1; temp* a_new = NULL; int a_new_size = 0; temp* a = NULL;
	printf("If wish to input yourself, type 0. ");
	scanf_s("%d", &cont);
	if (cont) {
		FILE* fptr = file("input.txt", "r"); fileprint(fptr);				//открытие файла с проверкой
		a = fstruct(fptr, &n);												//чтение массива структур из текстового файла
	}
	else 
		a = user_input(&n);												//ввод массива структур с клавиатуры

	do {
		a_new = labstep1(a, n, &cont, &a_new_size);							//основная функция программы
	} while (!cont);												
	
	bout(a_new, "output.bin", a_new_size);								//запись и чтение из бинарного файла массива структур
	free(a);
	return 0;
}