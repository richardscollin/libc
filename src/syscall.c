
#include <stdarg.h>
#include "common/__syscall.h"

long syscall(long n, ...)
{
    va_list ap;
    va_start(ap, n);
    __syscall(n, va_arg(ap, long), va_arg(ap, long), va_arg(ap, long),
            va_arg(ap, long), va_arg(ap, long));
    va_end(ap);
    return 0;
}
