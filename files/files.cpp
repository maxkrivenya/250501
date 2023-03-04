#include "sem2lab1.h"
int main() {
	int word_amt = 1; int n = getnum();
	int* wordcount = (int*)calloc(1, sizeof(int));
	char* word = (char*)calloc(20, 1);
	char** wordlist = alloc(word_amt, 10);
	FILE* fptr = file_choice("text.txt.txt", "r");	file_print(fptr); rewind(fptr);

	do {
		int i = 1;
		word = word_get(fptr, i);

		bool word_not_found = word_search(wordlist, word_amt, wordcount, word);			//Проверка наличия слова в массиве wordlist
		if (word_not_found) {															//Инициализация слова в массивах wordlist, wordcount при отсутствии в wordlist 
			word_amt++;
			wordlist = wordlist_add(wordlist, word, word_amt);
			wordcount = wordcount_add(wordcount, word_amt);
		}
	} while (!feof(fptr));
	
	sort_and_print(wordlist, wordcount, word_amt, n);									//параллельная сортировка wordlist, wordcount 
	fclose(fptr);  free(wordlist); free(wordcount); free(word);
	return 0;
}
