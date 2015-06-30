
#include <unistd.h>
#include <stdarg.h>
#include "stdio.h"


void NS(minprintf)(const char *restrict format, ...)
{
    va_list ap;

    int i = va_arg(ap, int);

    va_end(ap);
}

