#include "char2.h"
int main(int argc, char** argv)
{
    char** p = (char**)calloc(argc-1, sizeof(char*));
    int* size = (int*)malloc((argc-1)*sizeof(int));
    for (int i = 1; i < argc; i++) {
        p[i - 1] = (char*)calloc(strlen(argv[i]),sizeof(char));
        p[i - 1] = strcpy(p[i - 1], argv[i]);
        p[i - 1][strlen(argv[i])] = '\0';
        printf("%d ", strlen(p[i-1]));
        puts(p[i - 1]);
    }

    int a = argc - 1;
    //char** p = NULL;
    int again = 0;
    do {
       // var(&a);
       //p = char2fill(a);
       //p = char2adjust(p, a);
       p = strtoword(p, a, &a, a - 1);
       //strsortf(p, 1, 2, 3);
       strsort(p, a);
       finishup(p, a);
       again = exitf(again);
    } while (!again);
    return 0;
}
