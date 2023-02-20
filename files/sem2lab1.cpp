#include "sem2lab1.h"

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

char** alloc(int a, int b) {
	char** c = (char**)calloc(a, sizeof(char*));
	for (int i = 0; i < a; i++)
		c[i] = (char*)calloc(b, 1);

	return c;
}	  
//text alloc function

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

char** wordlist_add(char** wordlist, char* word, int word_amt) {

	wordlist = (char**)realloc(wordlist, word_amt * sizeof(char*));
	wordlist[word_amt - 1] = (char*)calloc(strlen(word), sizeof(char));
	strcpy(wordlist[word_amt - 2], word);

	return wordlist;
}
//adding str_word to the list

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

void result_print(char** wordlist, int* wordcount, int word_amt) {
	printf("num\tamt\tword\n");
	for (int a = 0; a < word_amt - 1; a++)
		printf("\n%d\t%d\t%s", a, wordcount[a], wordlist[a]);
	printf("\n");
}
//printing out the program results

void sort_and_print(char** wordlist, int* wordcount, int word_amt) {
	for(int i = 0; i < word_amt; i++)
		for(int j = word_amt - 1; j > i; j--)
			if (wordcount[j-1] < wordcount[j]) {
				str_switch(wordlist + j, wordlist + j - 1);
				int c = wordcount[j - 1];
				wordcount[j - 1] = wordcount[j];
				wordcount[j] = c;
			}
	result_print(wordlist, wordcount, word_amt);
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