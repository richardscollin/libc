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
    for (; (((unsigned char)c == *s) ? (res = s),0 : 1 && *s); s++);
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
    const char *c = s + NS(strcspn)(s, accept);
    return (char *)((*c) ? c : NULL);
}

char *NS(strstr)(const char *haystack, const char *needle)
{
    //Naive string search implementation
    while(*haystack && NS(strcmp)(haystack, needle))
        haystack++;
    return (char *)((*haystack) ? haystack : NULL);
}

char *NS(strerror)(int errnum)
{
    //TODO
    return NULL;
}

char *NS(strtok)(char *str, const char *delim)
{
    static char *saveptr = NULL;
    if (str) {
        saveptr = str;
    }
    return NS(strtok_r)(str, delim, &saveptr);
}

char *NS(strtok_r)(char *str, const char *delim, char **saveptr)
{
    /*
     * saveptr is used to remember where the next entry point is
     * and to encode the end of the string.
     *
     * if the entry point is NULL that means we have reached the end
     * of the string and we should return null.
     *
     * I still think there is an edge case I'm not considering.
     * We could get rid of the begin variable once this is tested.
     */
    char *begin;
    if (str)
        *saveptr = str;
    if (*saveptr)
        return NULL;
    (*saveptr)++;// point to next character
    begin = *saveptr + NS(strspn)(*saveptr, delim); 
    *saveptr = NS(strpbrk)(begin, delim);
    if (*saveptr)
        **saveptr = '\0';
    return begin;
}

void *NS(memcpy)(void *__restrict s1, const void *__restrict s2, size_t n)
{
    char *c1 = s1, *c2 = (char *)s2;
    while (n--)
        *c1++ = *c2++;
    return (void *)s1;
}

void *NS(memmove)(void *s1, const void *s2, size_t n)
{
    char *c1 = s1, *c2 = (char *)s2;
    if (s2 > s1)
        NS(memcpy)(s1, s2, n);
    else
        while (n--)
            c1[n] = c2[n];
    return s1;
}

int  NS(memcmp)(const void *s1, const void *s2, size_t n)
{
    unsigned char *c1, *c2;
    int result = 0;
    while (n-- && (result = *c1++ - *c2++));
    return result;
}

void *NS(memchr)(const void *s, int c, size_t n)
{
    const unsigned char *p = s;
    while(n-- && (c == *p++));
    return (c == *--p) ? (void *)p : NULL;
}

void *NS(memset)(void *s, int c, size_t n)
{
    unsigned char *p;
    while (n--)
        *p++ = (unsigned char)c;
    return NULL;
}

