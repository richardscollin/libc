
#include <unistd.h>
#include "stdio.h"

int NS(remove)(const char *filename)
{
    return unlink(filename);
}

