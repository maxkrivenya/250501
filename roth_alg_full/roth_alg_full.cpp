#include"roth.h"

int main (){
	int C_size= 12;
	char** c = (char**)calloc(C_size, sizeof(char*));
	for (int i = 0; i < C_size; i++)
		c[i] = (char*)calloc(size, 1);

	c[0][0] = '0'; c[0][1] = '0'; c[0][2] = '0'; c[0][3] = '0'; c[0][4] = '0';
	c[1][0] = '1'; c[1][1] = '1'; c[1][2] = '0'; c[1][3] = '0'; c[1][4] = '1';
	c[2][0] = '0'; c[2][1] = '0'; c[2][2] = '0'; c[2][3] = '1'; c[2][4] = '0';
	c[3][0] = '1'; c[3][1] = '0'; c[3][2] = '0'; c[3][3] = '1'; c[3][4] = '0';
	c[4][0] = '1'; c[4][1] = '0'; c[4][2] = '1'; c[4][3] = '1'; c[4][4] = '0';
	c[5][0] = '0'; c[5][1] = '1'; c[5][2] = '1'; c[5][3] = '0'; c[5][4] = '1';
	c[6][0] = '0'; c[6][1] = '0'; c[6][2] = '1'; c[6][3] = '0'; c[6][4] = '0';
	c[7][0] = '0'; c[7][1] = '0'; c[7][2] = '0'; c[7][3] = '1'; c[7][4] = '1';
	c[8][0] = '0'; c[8][1] = '0'; c[8][2] = '1'; c[8][3] = '1'; c[8][4] = '0';
	c[9][0] = '0'; c[9][1] = '0'; c[9][2] = '1'; c[9][3] = '1'; c[9][4] = '1';
	c[10][0] = '0'; c[10][1] = '1'; c[10][2] = '1'; c[10][3] = '1'; c[10][4] = '1';
	c[11][0] = '1'; c[11][1] = '1'; c[11][2] = '1'; c[11][3] = '0'; c[11][4] = '1';

	//do {
		int Acount = 0;
		char** A = (char**)calloc(1, sizeof(char*));
		A[0] = (char*)calloc(size, 1);

		char** B = (char**)calloc(C_size, sizeof(char*));
		for (int i = 0; i < C_size; i++)
			B[i] = (char*)calloc(size, 1);



		int* q = (int*)calloc(C_size, sizeof(int));						//проверка на простые импликанты
		for (int i = 0; i < C_size; i++)
			q[i] = 0;

		char*** Cnew = (char***)calloc(C_size, sizeof(char**));			//выделение памяти под таблицу
		for (int i = 0; i < C_size; i++)								
			Cnew[i] = (char**)calloc(C_size, sizeof(char*));
		for (int i = 0; i < C_size; i++)
			for (int j = 0; j < C_size; j++)
				Cnew[i][j] = (char*)calloc(size, 1);

		for (int i = 0; i < C_size; i++)								//заполнение таблицы
			for (int j = i - 1; j >= 0; j--)
				Cnew[i][j] = froth(c[i], c[j], q + i, q + j, &Acount);

		for (int i = 0; i < C_size; i++)								//диагональ
			for (int j = 0; j < size; j++)
				Cnew[i][i][j] = '-';

		printf("C0*C0\t");												//вывод таблицы
		for (int i = 0; i < C_size; i++)								//
			print(c[i]);												//
		printf("\n\n");													//
		for (int i = 0; i < C_size; i++) {								//
			print(c[i]);												//
			for (int j = 0; j < C_size; j++)							//
				print(Cnew[i][j]);										//
			printf("\n");												//
		}																//вывод таблицы

		for (int i = 0; i < C_size; i++)								//вывод проверки на простые импликанты (0 - простая, 1 - нет)
			printf("%d - %d\t", i, q[i]);
		printf("Acount = %d", Acount);
		
	//} while (n > 1);
		return 0;
}