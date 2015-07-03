
#include "ctype.h"

#define _DEL 0x7F
#define _US 0x1F
#define _CASE_MASK 0x20

int isalnum(int c)
{
    return isalpha(c) || isdigit(c);
}

int isalpha(int c)
{
    return isupper(c) || islower(c);
}

int iscntrl(int c)
{
    return ('\0' <= c && c <= _US) || c == _DEL;
}

int isdigit(int c)
{
    return '0' <= c && c <= '9';
}

int isgraph(int c)
{
    return isprint(c) && c != ' ';
}

int islower(int c)
{
    return 'a' <= c && c <= 'z';
}

int isprint(int c)
{
    return _US < c && c < _DEL;
}

int ispunct(int c)
{
    return isgraph(c) && !isalnum(c);
}

int isspace(int c)
{
    return c == ' ' || ('\t' <= c && c <= '\r');
}

int isupper(int c)
{
    return 'A' <= c && c <= 'Z';
}

int isxdigit(int c)
{
    return isdigit(c) || ('a' <= c && c <= 'f') || ('A' <= c && c <= 'F');
}

int toupper(int c)
{
    return islower(c) ? c ^ _CASE_MASK : c;
}

int tolower(int c)
{
    return isupper(c) ? c ^ _CASE_MASK : c;
}

int isascii(int c)
{
    return 0 <= c && c <= _DEL;
}

int isblank(int c)
{
    return c == ' ' || c == '\t';
}

#undef _DEL
#undef _US
#undef _CASE_MASK
