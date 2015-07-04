#include <stdio.h>
#include <stdlib.h>

void __assert(int assertion, char *str_assertion, char *file, int line)
{
    if(!assertion) {
        fprintf(stderr, "%s:%d Assertion `%s' failed.\n", file, line, str_assertion);
        abort();
    }
}
