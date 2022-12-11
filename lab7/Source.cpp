#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int var(int c)
{
    printf("Input char value ");
    scanf_s("%d", &c);
    printf("c = %d \n", c);
    return c;
}


void strtoword(char** p, int a, int i)
{
    int beg = 0, end = 0, j = strlen(p[i]) - 2;

    while (j > 0) {
        while (!isalpha(p[i][j]))
            j--;
        end = j; beg = j;

        for (j, beg; beg > 0 && isalpha(p[i][j - 1]); j--, beg--);

        a++;
        p = (char**)realloc(p, a);
        p[a - 1] = (char*)calloc(end - beg + 2, sizeof(char));
        for (int k = 0, l = j; k < end - beg + 1; k++, l++)
            p[a - 1][k] = p[i][l];

        j--;
    }
    i--;
    if (i >= 0)
        strtoword(p, a, i);


        //int beg = 0, end = 0, space = 0, wordlength = 0;
        //for (int j = (strlen(p[i]) - 2); j > 0; j--)
        //{
        //    beg = p[i][j]; end = p[i][j];
        //    if (!isalpha(p[i][j]))
        //    {
        //        end = j;
        //        while ((isalpha(p[i][j])) && (j>=0) )
        //            j--;
        //        beg = j;
        //        
        //    }
        //    if(beg >= 0)
        //    {
        //            wordlength = end - beg;
        //            a++;
        //            p = (char**)realloc(p, a);
        //            p[a - 1] = (char*)malloc((wordlength + 1) * sizeof(char));
        //            p[a - 1][wordlength] = '\0';
        //            for (int k = beg, iv = 0; iv < wordlength; k++, iv++)
        //                p[a - 1][iv] = p[i][k];

        //         //   p[i] = (char*)realloc(p[i], strlen(p[i]) - wordlength - 1);
        //            p[i][strlen(p[i]) - wordlength - 1] = '\0';
        //    }
        //}
        //i--;
        //if (i > 0)
        //    strtoword(p, a, i);
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