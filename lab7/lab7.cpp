#include "char2.h"
int main()
{
    char** p = NULL;   
    int a = 0;
    int* A = &a;
    int again = 0;

    do {
        a = var(a);
        rewind(stdin);
        p = char2fill(p, a);
        p = char2adjust(p, a);

        p = strtoword(p, a, A, a - 1);
        strsort(p, *A);
        finishup(p, *A);

        again = exitf(again);
    } while (!again);
    return 0;
}
