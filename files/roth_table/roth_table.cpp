#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size 5


char* dectobin(char* a) {
    char* temp = (char*)calloc(size, 1);
    int dec = atoi(a);
    for (int i = 0, j = size - 1; i < size; i++ && j--) {
        temp[i] = '0';
        if (dec - 2 ^ j >= 0) {
            dec -= 2 ^ j;
            temp[i] = 1;
        }
    }
    return temp;
}

int main()
{
    FILE* fptr = NULL;
    fopen_s(&fptr, "input.txt", "w");
    if (fptr == NULL) {
        printf("file open error");
        exit(1);
    }
    int C_size = 0;
    char** C = (char**)calloc(1, sizeof(char*));
    C[0] = (char*)calloc(size, 1);
    fgets(C[0], size, fptr);
    C[0] = dectobin(C[0]);
    for (int i = 0; i < size; i++)
        printf("%c", C[i]);
    return 0;
}
