#include "sem2lab1.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////	files

FILE* file(const char* a, const char* b) {

	FILE* fptr;
	fopen_s(&fptr, a, b);
	if (fptr == NULL) {
		printf("file open error");
		exit(1);
	}

	return fptr;
}
//file open function

FILE* file_choice(const char* a, const char* b) {
	bool yourself; FILE* f; int temp;
	printf("if wish to input text yourself, type 1. ");
	scanf_s("%d", &temp);
	yourself = temp;
	if (yourself) {
		bool end = false;
		char* str = (char*)calloc(100, 1);
		f = file(a, "w");
		do {
			rewind(stdin);
			printf("Input row or 0 for end ");
			fgets(str, 100, stdin);
			if (str[0] != '0')
				fprintf(f, str);
			else end = true;
		} while (!end);
		fclose(f);
		f = file(a, b);
		return f;
	}
	else {
		f = file(a, b);
		return f;
	}
}
//???????? ????? ? ????????? ??????? ?????? ? ????

//////////////////////////////////////////////////////////////////////////////////////////////////////	char

char** alloc(int a, int b) {
	char** c = (char**)calloc(a, sizeof(char*));
	for (int i = 0; i < a; i++)
		c[i] = (char*)calloc(b, 1);

	return c;
}	  
//text alloc function

char** wordlist_add(char** wordlist, char* word, int word_amt) {

	wordlist = (char**)realloc(wordlist, word_amt * sizeof(char*));
	wordlist[word_amt - 1] = (char*)calloc(strlen(word), sizeof(char));
	strcpy(wordlist[word_amt - 2], word);

	return wordlist;
}
//adding str_word to the list

char* fword(char* p, int j, int i) {
	int a;
	char* word = (char*)calloc(20, 1);
	for (a = 0; a < j - i; a++)
		word[a] = p[a + i];
	word[j - i] = '\0';
	for (a = 0; a < strlen(word); a++)
		word[a] = tolower(word[a]);
	return word;
}
//copying a word from a string

//////////////////////////////////////////////////////////////////////////////////////////////////////	int

int* wordcount_add(int* wordcount, int word_amt) {
	wordcount = (int*)realloc(wordcount, word_amt * sizeof(int));
	wordcount[word_amt - 2] = 1;
	return wordcount;
}
//?????????? ??????? ????????? ????? ? wordcount

int getnum() {
	int c;
	printf("input number ");
	scanf_s("%d", &c);
	return c;
}
//?????????? ????? ? ??????????

//////////////////////////////////////////////////////////////////////////////////////////////////////	bool

bool word_search(char** wordlist, int word_amt, int* wordcount, char* word) {
	int a = 0;
	for (a = 0; a < word_amt; a++)														//word compare
		if (!strcmp(wordlist[a], word)) {
			wordcount[a]++;
			a = word_amt + 1;
		}
	if (a == word_amt)
		return true;
	else
		return false;
}
//checking if the word has already been found

//////////////////////////////////////////////////////////////////////////////////////////////////////	void

void result_print(char** wordlist, int* wordcount, int word_amt, int n, FILE* fp) {
	if (n == 0)
		n = word_amt;
	fprintf(fp, "num\tamt\tword\n");
	for (int a = 0; a < word_amt - 1 && a < n; a++)
		fprintf(fp, "\n%d\t%d\t%s", a, wordcount[a], wordlist[a]);
	printf("\n");
}
//printing out the program results

void sort_and_print(char** wordlist, int* wordcount, int word_amt, int n) {
	for(int i = 0; i < word_amt; i++)
		for(int j = word_amt - 1; j > i; j--)
			if (wordcount[j-1] < wordcount[j]) {
				str_switch(wordlist + j, wordlist + j - 1);
				int c = wordcount[j - 1];
				wordcount[j - 1] = wordcount[j];
				wordcount[j] = c;
			}
	FILE* fp = file("result.txt", "w");
	result_print(wordlist, wordcount, word_amt, n, stdout);
	result_print(wordlist, wordcount, word_amt, n, fp);
}
//sorting the arrays and printing the results

void str_switch(char** a, char** b) {
	char* c = *b;
	*b = *a;
	*a = c;
}
//switching two strings

void file_print(FILE* fptr) {
	char* str = (char*)calloc(255, 1);
	do {
		fgets(str, 255, fptr);
		puts(str);
	} while (!feof(fptr));
	free(str);
	printf("\n");
	return;
}
//????? ?????? ????? ?? ?????


