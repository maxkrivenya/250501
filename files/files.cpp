#include "sem2lab1.h"
int main() {
	int word_amt = 1;  int i = 1;
	int* wordcount = (int*)calloc(1, sizeof(int));
	char* word = (char*)calloc(20, 1);
	char** wordlist = alloc(word_amt, 10);
	FILE* fptr = file("text.txt.txt", "r");	file_print(fptr); rewind(fptr);

	do {
		i = 1;
		do {																			//������������ ���������� �� �����
			word[0] = fgetc(fptr);
		} while (!isalpha(word[0]) and !feof(fptr));

		for (i; isalpha(word[i-1]); i++)	word[i] = fgetc(fptr);						//������������ ���������� ����
		word[i-1] = '\0';
		for (i = 0; i < strlen(word); i++)	word[i] = tolower(word[i]);					//��������� ����� ��� ��������� ��������

		bool word_found = word_search(wordlist, word_amt, wordcount, word);				//�������� ������� ����� � wordlist
		if (word_found) {																//���� ����� �� �������:
			word_amt++;																	//���������������� ���������� ���-�� ��������� ����
			wordlist = wordlist_add(wordlist, word, word_amt);							//�������� ����� � wordlist
			wordcount = (int*)realloc(wordcount, word_amt * sizeof(int));				//��������� wordcount ��� ����� �����
			wordcount[word_amt - 2] = 1;												//������� 1 � ������ �����
		}
	} while (!feof(fptr));

	result_print(wordlist, wordcount, word_amt);
	sort_and_print(wordlist, wordcount, word_amt);										//����� ����������� �� �����
	fclose(fptr);  free(wordlist); free(wordcount); free(word);
	return 0;
}