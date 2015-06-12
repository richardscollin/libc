
#include "locale.h"
#include "string.h"

//static struct NS(lconv) NS(_)

char *NS(setlocale)(int category, const char *locale)
{
    if (NS(strcmp)(locale, "") ||
            NS(strcmp)(locale, "C") ||
            NS(strcmp)(locale, "POSIX")) {
    }
}

struct NS(lconv) *NS(localeconv)(void)
{
}
