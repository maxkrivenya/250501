#include "please_work.h"

int main(int argc, char** argv) {

	void (* funct) (void);
	funct = bye;
	int a = argc - 1;
	int* A = &a;
	//char** p = stralloc(3, 50, 50, 50);
	char** p = argalloc(a, argv);

	arrprint(p, *A);
	p = strtoword(p, A, *A - 1);
	arrprint(p, *A);
	strsort(p, *A);
	arrprint(p, *A);

	funct();
	return 0;
}