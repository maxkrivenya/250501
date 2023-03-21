#include "structs.h"

int main() {
	int cont = 1; int n = 1; temp* a_new = NULL; int a_new_size = 0;
	FILE* fptr = file("input.txt", "r"); fileprint(fptr);					//открытие файла с проверкой
	//temp* a = alloc();
	temp* a = fstruct(fptr, &n);											//чтение массива структур из текстового файла
	do {
		//a_new_size = 0;
		a_new = labstep1(a, n, &cont, &a_new_size);							//основная функция программы
	} while (!cont);
	bout(a, "structs.bin", n);												//запись и чтение из бинарного файла массива структур
	free(a_new);
	return 0;
}