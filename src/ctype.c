
#include "ctype.h"

#define _DEL 0x7F
#define _US 0x1F
#define _CASE_MASK 0x20

int NS(isalnum)(int c)
{
    return NS(isalpha)(c) || NS(isdigit)(c);
}

int NS(isalpha)(int c)
{
    return NS(isupper)(c) || NS(islower)(c);
}

int NS(iscntrl)(int c)
{
    return ('\0' <= c && c <= _US) || c == _DEL;
}

int NS(isdigit)(int c)
{
    return '0' <= c && c <= '9';
}

int NS(isgraph)(int c)
{
    return NS(isprint)(c) && c != ' ';
}

int NS(islower)(int c)
{
    return 'a' <= c && c <= 'z';
}

int NS(isprint)(int c)
{
    return _US < c && c < _DEL;
}

int NS(ispunct)(int c)
{
    return NS(isgraph)(c) && !NS(isalnum)(c);
}

int NS(isspace)(int c)
{
    return c == ' ' || ('\t' <= c && c <= '\r');
}

int NS(isupper)(int c)
{
    return 'A' <= c && c <= 'Z';
}

int NS(isxdigit)(int c)
{
    return NS(isdigit)(c) || ('a' <= c && c <= 'f') || ('A' <= c && c <= 'F');
}

int NS(toupper)(int c)
{
    return NS(islower)(c) ? c ^ _CASE_MASK : c;
}

int NS(tolower)(int c)
{
    return NS(isupper)(c) ? c ^ _CASE_MASK : c;
}

int NS(isascii)(int c)
{
    return 0 <= c && c <= _DEL;
}

int NS(isblank)(int c)
{
    return c == ' ' || c == '\t';
}

#undef _DEL
#undef _US
#undef _CASE_MASK
