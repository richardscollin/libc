#include <string.h>
#include <errno.h> /* for strerror */

char *strcpy(char *__restrict s1, const char *__restrict s2)
{
    char *c = s1;
    while ((*s1++ = *s2++));
    return c;
}
char *strncpy(char *__restrict s1, const char *__restrict s2, size_t n)
{
    char *c = s1;
    while (n-- && (*s1++ = *s2++));
    for (; n--; *s1++ = '\0');
    return c;
}
char *strcat(char *__restrict s1, const char *__restrict s2)
{
    char *c = s1;
    while (*s1++);
    for (s1--; (*s1++ = *s2++); );
    return c;
}

char *strncat(char *__restrict s1, const char *__restrict s2, size_t n)
{
    /* TODO check this */
    char *s = s1 + strlen(s1);
    for (; n && *s2; (*s = *s2), n--, s++, s2++);
    *s = '\0';
    return s1;
}

size_t strlen(const char *s)
{
    size_t i = 0;
    while (i++,*s++);
    return i - 1;
}

size_t strnlen(const char *s, size_t n)
{
    size_t i = 0;
    while ((i++ < n) && *s++);
    return i - 1;
}

int strcmp(const char *s1, const char *s2)
{
    for (; *s1 && (*s1 == *s2); s1++,s2++);
    return (unsigned char)*s1 - (unsigned char)*s2;
}

int strncmp(const char *s1, const char *s2, size_t n)
{
    if (!n--) return 0;
    for (; n && *s1++ == *s2++ && *s1; n--);
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

char *strchr(const char *s, int c)
{
    const char *res = NULL;
    for (; (((unsigned char)c == *s) ? (res = s),0 : 1 && *s); s++);
    return (char *)res;
}

char *strrchr(const char *s, int c)
{
    const char *res = NULL;
    for (; (((char)c == *s) ? (res = s),1 : 1 && *s); s++);
    return (char *)res;
}

size_t strspn(const char *s, const char *accept)
{
    char c;
    size_t i = 0;
    while (i++,(c = *s++) && strchr(accept, c));
    return i - 1;
}
size_t strcspn(const char *s, const char *reject)
{
    char c;
    size_t i = 0;
    while (i++,(c = *s++) && !strchr(reject, c));
    return i - 1;
}

char *strpbrk(const char *s, const char *accept)
{
    const char *c = s + strcspn(s, accept);
    return (char *)((*c) ? c : NULL);
}

char *strstr(const char *haystack, const char *needle)
{
    const size_t n = strlen(needle);
    for(; *haystack && strncmp(haystack, needle, n); haystack++);
    return (char *)((*haystack) ? haystack : NULL);
}

char *strerror(int errnum)
{
    static char *__str_EINVAL = "Invalid argument";
    switch (errnum) {
        case EINVAL: return __str_EINVAL;
        default: return NULL;
    }
}

char *strtok(char *str, const char *delim)
{
    static char *saveptr = NULL;
    if (str && (saveptr = str)) {}
    return strtok_r(str, delim, &saveptr);
}

char *strtok_r(char *str, const char *delim, char **saveptr)
{
    /*
     * saveptr is used to remember where the next entry point is
     * and to encode the end of the string.
     *
     * if the entry point is NULL or points to the NULL character 
     * that means we have reached the end of the string and 
     * we should return null.
     *
     */
    if (str) *saveptr = str;
    if (!*saveptr || **saveptr == '\0') return NULL;
    str = *saveptr + strspn(*saveptr, delim); 
    *saveptr = strpbrk(str, delim);
    if (*saveptr) *(*saveptr)++ = '\0';
    return str;
}

void *memcpy(void *__restrict s1, const void *__restrict s2, size_t n)
{
    char *c1 = s1, *c2 = (char *)s2;
    for (; n--; *c1++ = *c2++);
    return (void *)s1;
}

void *memmove(void *s1, const void *s2, size_t n)
{
    char *c1 = s1, *c2 = (char *)s2;
    if (s2 > s1) memcpy(s1, s2, n);
    else while (n--) c1[n] = c2[n];
    return s1;
}

int memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned const char *c1 = s1, *c2 = s2;
    int result = 0;
    while (n-- && !(result = *c1++ - *c2++));
    return result;
}

void *memchr(const void *s, int c, size_t n)
{
    unsigned const char *p = s;
    while(n-- && (c != *p++));
    return (c == *--p) ? (void *)p : NULL;
}

void *memset(void *s, int c, size_t n)
{
    unsigned char *p = s;
    for (;n--; *p++ = (unsigned char)c);
    return s;
}
