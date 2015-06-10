
#include <stddef.h>

#define NS(NAME) CAR_ ## NAME

// hack to make this work on gcc
#define restrict 

char *NS(strcpy)(char *restrict s1, const char *restrict s2);
char *NS(strncpy)(char *restrict s1, const char *restrict s2, size_t n);

char *NS(strcat)(char *restrict s1, const char *restrict s2);
char *NS(strncat)(char *restrict s1, const char *restrict s2, size_t n);

int NS(strcmp)(const char *s1, const char *s2);
int NS(strncmp)(const char *s1, const char *s2, size_t n);

char *NS(strchr)(const char *s, int c);
char *NS(strrchr)(const char *s, int c);


size_t NS(strspn)(const char *s, const char *accept);
size_t NS(strcspn)(const char *s, const char *reject);

char *NS(strpbrk)(const char *s, const char *accept);

char *NS(strstr)(const char *haystack, const char *needle);

size_t NS(strlen)(char *s);
size_t NS(strnlen)(char *s, size_t n);

char *NS(strerror)(int errnum);

char *NS(strtok)(char *str, const char *delim);
char *NS(strtok_r)(char *str, const char *delim, char **saveptr);

