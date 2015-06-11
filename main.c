#if 0
clang -Weverything -Werror "$0" && exec ./a.out "$@"
exit 1
#endif

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "assert.h"

int main(int argc, char *argv[])
{
    char my_str[] = "Hello, world!";
    assert(sizeof(my_str) == NS(strlen)(my_str) + 1);
    return 0;
}

