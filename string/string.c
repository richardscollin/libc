#include "string.h"
#include <stdio.h>
#include <stdlib.h>

char *NS(strcpy)(char *__restrict s1, const char *__restrict s2)
{
    //http://stackoverflow.com/questions/14202201/implementation-of-strcpy-function
    while ((*s1++ = *s2++));
    return s1;
}
char *NS(strncpy)(char *__restrict s1, const char *__restrict s2, size_t n)
{
    //http://stackoverflow.com/questions/14159625/implementation-of-strncpy
    while (n-- && (*s1++ = *s2++));
    for (; n--; *s1++ = '\0');
    return s1;
}
char *NS(strcat)(char *__restrict s1, const char *__restrict s2)
{
    while (*s1++);
    for (s1--; (*s1++ = *s2++); );
    return s1;
}

size_t NS(strlen)(char *s)
{
    size_t i = 0;
    while (i++,*s++);
    return i - 1;
}

size_t NS(strnlen)(char *s, size_t n)
{
    size_t i = 0;
    while ((i++ < n) && *s++);
    return i - 1;
}

int NS(strcmp)(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
        s1++,s2++;
    return *s1 - *s2;
    //may need a cast here to follow standard
}

int NS(strncmp)(const char *s1, const char *s2, size_t n)
{
    while (n-- && *s1 == *s2 && *s1)
        s1++,s2++;
    return *s1 - *s2;
    //may need a cast here to follow standard
}

char *NS(strchr)(const char *s, int c)
{
    const char *res = NULL;
    for (; (((char)c == *s) ? (res = s),0 : 1 && *s); s++);
    return (char *)res;
}

char *NS(strrchr)(const char *s, int c)
{
    const char *res = NULL;
    for (; (((char)c == *s) ? (res = s),1 : 1 && *s); s++);
    return (char *)res;
}

size_t NS(strspn)(const char *s, const char *accept)
{
    char c;
    size_t i = 0;
    while (i++,(c = *s++) && NS(strchr)(accept, c))
    return i - 1;
}
size_t NS(strcspn)(const char *s, const char *reject)
{
    char c;
    size_t i = 0;
    while (i++,(c = *s++) && !NS(strchr)(reject, c))
    return i - 1;
}

char *NS(strpbrk)(const char *s, const char *accept)
{
    char c;
    while ((c = *s++) && !NS(strchr)(accept, c));
    return (char *)(!c ? s - 1 : NULL);
}

char *NS(strstr)(const char *haystack, const char *needle)
{
    //TODO
    return NULL;
}

char *NS(strerror)(int errnum)
{
    //TODO
    return NULL;
}

char *NS(strtok)(char *str, const char *delim)
{
    //TODO
    return NULL;
}

char *NS(strtok_r)(char *str, const char *delim, char **saveptr)
{
    //TODO
    return NULL;
}

