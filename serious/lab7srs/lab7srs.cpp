#include "please_work.h"

int main(int argc, char** argv) {

	void (* funct) (void);
	funct = bye;
	int a = argc - 1;
	int* A = &a;
	//char** p = stralloc(3, 50, 50, 50);		//выделение памяти под массив строк переменного размера
	char** p = argalloc(a, argv);				//выделение памяти под массив строк через аргументы командной строки

	arrprint(p, *A);
	p = strtoword(p, A, *A - 1);				//преобразование массива строк в массив слов
	arrprint(p, *A);
	strsort(p, *A);								//сортировка массива слов по длине
	arrprint(p, *A);

	funct();
	return 0;
}