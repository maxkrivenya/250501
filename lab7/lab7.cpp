#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "char2.h"
int main()
{
    char** p;
    char* holder;
    int* size;
    int a = 0;
    a = var(a);
    p = (char**)malloc(a * sizeof(char*));
    rewind(stdin);

    for (int i = 0; i < a; i++)
    {
        p[i] = (char*)malloc(100*sizeof(char));
        printf("Input %d string ", i);
        fgets(p[i], 100, stdin);

        for (int j = 0; p[i][0] == ' '; j++)
            p[i][j] = p[i][j + 1];
       // for (int j = strlen(p[i]) - 1; p[i][j] = 0; j--)                                      //deleting ' ' at the end of strings 
         //   p[i][]
    }

    for (int i = 0; i < a; i++)
    {
        int x = strlen(p[i]);
        printf("%d ", x);
        p[i] = (char*)realloc(p[i], x);
        p[i][x] = '\0';
    }
    size = (int*)malloc(a * sizeof(int));
    //end of preparations
    strtoword(p, a, a-1);
    strsort(p, a);
    //printout
    printf("\n");
    for (int i = 0; i < a; i++)
        puts(p[i]);

    for (int i = 0; i < a; i++)
        free(p[i]);
    free(p);
    return 0;
}
