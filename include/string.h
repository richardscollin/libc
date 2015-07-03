
#include <stddef.h>

#include "ns.h"
//#define __restrict restrict

char *NS(strcpy)(char *__restrict s1, const char *__restrict s2);
char *NS(strncpy)(char *__restrict s1, const char *__restrict s2, size_t n);

char *NS(strcat)(char *__restrict s1, const char *__restrict s2);
char *NS(strncat)(char *__restrict s1, const char *__restrict s2, size_t n);

int NS(strcmp)(const char *s1, const char *s2);
int NS(strncmp)(const char *s1, const char *s2, size_t n);

char *NS(strchr)(const char *s, int c);
char *NS(strrchr)(const char *s, int c);


size_t NS(strspn)(const char *s, const char *accept);
size_t NS(strcspn)(const char *s, const char *reject);

char *NS(strpbrk)(const char *s, const char *accept);

char *NS(strstr)(const char *haystack, const char *needle);

size_t NS(strlen)(const char *s);
size_t NS(strnlen)(char *s, size_t n);

char *NS(strerror)(int errnum);

char *NS(strtok)(char *str, const char *delim);
char *NS(strtok_r)(char *str, const char *delim, char **saveptr);

void *NS(memcpy)(void *__restrict, const void *__restrict, size_t);
void *NS(memmove)(void *, const void *, size_t);

int  NS(memcmp)(const void *, const void *, size_t);

void *NS(memchr)(const void *, int, size_t);
void *NS(memset)(void *, int, size_t);

