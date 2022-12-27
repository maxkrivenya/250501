#include "char2.h"
int main()
{
    int a;
    char** p = NULL;
    int again = 0;
    do {
        var(&a);
       p = char2fill(a);
       p = char2adjust(p, a);
       p = strtoword(p, a, &a, a - 1);
       strsort(p, a);
       finishup(p, a);
       again = exitf(again);
    } while (!again);
    return 0;
}
