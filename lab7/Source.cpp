#include "char2.h"

void var(int* d)
{
    printf("Input char value ");
    scanf_s("%d", d);
    printf("c = %d \n", *d);
}

char** char2fill(int a) {
    char** p = (char**)malloc(a * sizeof(char*));
    for (int i = 0; i < a; i++)
    {
        rewind(stdin);
        p[i] = (char*)calloc(100, sizeof(char));
        fgets(p[i], 99, stdin);
    }
    return p;
}

char** char2adjust(char** p, int a) {
    for (int i = 0; i < a; i++)
    {
        int x = strlen(p[i]);
        printf("%d ", x);
        p[i] = (char*)realloc(p[i], x * sizeof(char));
        p[i][x-1] = '\0';
        puts(p[i]);
    }
    return p;
}


//array of strings sort by size (bubble method)
void strsort(char** p, int n)
{
    char* holder;
    for (int i = 0; i < n; i++)
        for (int j = n - 1; j > i; j--)
            if (strlen(p[j - 1]) > strlen(p[j]))
            {
                holder = (char*)calloc(strlen(p[j]) + 2, sizeof(char));
                strcpy(holder, p[j]);
                p[j] = (char*)realloc(p[j], strlen(p[j - 1])  + 1);
                strcpy(p[j], p[j - 1]);
                p[j - 1] = (char*)realloc(p[j - 1], strlen(holder) + 1);
                strcpy(p[j - 1], holder);
                free(holder);
            }
}

void finishup(char** p, int A){
    for (int i = 0; i < A; i++) {
        puts(p[i]);
        free(p[i]);
    }
    free(p);
}

int exitf(int a) {
    printf("If you wish to proceed, type 0 ");
    scanf_s("%d", &a);
    return a;
}

//void strsortf(char** p, int a, ...) {
//    int n = 1;
//    int* size = NULL;
//    int* poi = &a;
//    while(*poi) {
//        printf("%d ", *poi);
//        n++;
//        poi++;
//    }
//    size = (int*)malloc(n * sizeof(int));
//    poi = &a;
//    for (int i = 0; *poi; i++, poi++)
//        size[i] = *poi;
//    for (int i = 0; i < n; i++)
//        printf("\n%d, %d ", size[i], *(poi+i));
//    for (int i = 0; i < n; i++)
//        for(int j = n-1; j > i; j--)
//            if (strlen(p[size[j] - 1]) > strlen(p[size[j]])) {
//                int temp = size[j];
//                size[j] = size[j - 1];
//                size[j - 1] = temp;
//            }
//    for (int i = 0; i < n; i++)
//        puts(p[size[i]]);
//}