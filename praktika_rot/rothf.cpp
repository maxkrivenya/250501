#include "roth.h"

char* froth1(char* a, char* b, int* n, int* n2, int* Acount, int* flg) {
	int y_num = 0; int flag = *flg; int bruh = 0;
	char* str = (char*)calloc(size, 1);

	for (int i = 0; i < size; i++)
		if ((a[i] == 'x' && b[i] != 'x') or (a[i] != 'x' && b[i] == 'x'))
			bruh++;
	if (bruh) {
		for (int i = 0; i < size; i++)
			str[i] = ' ';
		return str;
	}


	for (int i = 0; i < size; i++) {
		str[i] = roth_mult(a[i], b[i]);
		if (str[i] == 'y') {
			y_num++;
			str[i] = 'x';
		}
	}

	if (y_num == 1) {
		flag = 1;
		*flg = flag;
		*n = 1;
		*n2 = 1;
		*Acount = *Acount + 1;
		return str;
	}
	else {
		for (int i = 0; i < size; i++)
			str[i] = ' ';
		return str;
	}

	return str;
}
//
//char* random_z_remove(char* a) {
//	for (int i = 0; i < size; i++)
//		if (a[i] == 'Z')
//			a[i] = 'x';
//	return a;
//}

//int z_count(char* a) {
//	int b = 0;
//	for (int i = 0; i < size; i++)
//		if (a[i] == 'Z')
//			b++;
//	return b;
//}
//
//int x_count(char* a) {
//	int b = 0;
//	for (int i = 0; i < size; i++)
//		if (a[i] == 'x')
//			b++;
//	return b;
//}
//
//int y_count(char* a) {
//	int b = 0;
//	for (int i = 0; i < size; i++)
//		if (a[i] == 'y')
//			b++;
//	return b;
//}
//
//int num_count(char* a) {
//	int b = 0;
//	for (int i = 0; i < size; i++)
//		if (isdigit(a[i]))
//			b++;
//	return b;
//}
//
//char* z_remove(char* a, char* b) {
//	for (int i = 0; i < size; i++)
//		if (a[i] == 'Z') {
//			a[i] = b[i];
//		}
//	return a;
//}
//
//char* z_remove_times(char* _temp, char* _origin, int m) {
//	int c = m;
//	char* d = (char*)calloc(size, 1);
//	for (int i = 0; i < size; i++) {
//		if (isdigit(_temp[i])) {
//			if (c != 0) {
//				c--;
//				d[i] = 'Z';
//			}
//			else {
//				c--;
//				d[i] = _temp[i];
//			}
//		}
//		else
//			d[i] = 'Z';
//	}
//	d = z_remove(d, _origin);
//	return d;
//}

//char** x_sort(char** x, int s) {
//	int j = 0; int max = 0;
//	for (int i = 0; i < s; i++)
//		if (x_count(x[i]) > max) {
//			j = i;
//			max = x_count(x[i]);
//		}
//	for (int i = j - 1; i >= 0; i--)
//		x[i + 1] = x[i];
//	x[0] = strcpyy(x[0], x[j]);
//	return x;
//}
//
