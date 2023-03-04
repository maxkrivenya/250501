#include "sem2lab1.h"
int main() {
	int word_amt = 1; int a = 0; int b = 0; int n = getnum();
	int* wordcount = (int*)calloc(1, sizeof(int));
	char* p = (char*)calloc(255, sizeof(char));
	char** wordlist = alloc(word_amt, 10);
	FILE* fptr = file("text.txt.txt", "r");

	do {
		fgets(p, 255, fptr); puts(p);

		int i = 0; while (!isalpha(p[i])) i++;													//word search

		while (i < strlen(p)) {

			while (!isalpha(p[i])) i++;
			int j = i;
			while (isalpha(p[j])) j++;

			char* word = fword(p, j, i);
			bool word_found = word_search(wordlist, word_amt, wordcount, word);
			if (word_found) {																//if 1st time found, amt++, write down
				word_amt++;
				wordlist = wordlist_add(wordlist, word, word_amt);
				wordcount = (int*)realloc(wordcount, word_amt * sizeof(int));
				wordcount[word_amt - 2] = 1;
			}
			i = j;
			if (j == strlen(p) - 1)
				i = strlen(p);
		}
	} while (!feof(fptr));
	free(p);
	sort_and_print(wordlist, wordcount, word_amt, n);
	fclose(fptr);
	return 0;
}