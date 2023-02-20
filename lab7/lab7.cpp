struct letters {
	char a;
	char b;
};
#include <stdio.h>

int main() {
	letters poshel[6];
	poshel[0].a = 'p';
	poshel[0].b = 'o';
	poshel[1].a = 's';
	poshel[1].b = 'h';
	poshel[2].a = 'e';
	poshel[2].b = 'l';
	poshel[3].a = ' ';
	poshel[3].b = 'n';
	poshel[4].a = 'a';
	poshel[4].b = 'h';
	poshel[5].a = 'u';
	poshel[5].b = 'i';
	for (int i = 0; i < 6; i++)
		printf("%c%c", poshel[i].a, poshel[i].b);
	return 0;
}