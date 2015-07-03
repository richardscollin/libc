
#include <stddef.h>
#include <locale.h>

#define __CX
//#define __XSI

#ifdef __XSI
void    *memccpy(void *__restrict, const void *__restrict, int, size_t);
#endif

void    *memchr(const void *, int, size_t);
int      memcmp(const void *, const void *, size_t);
void    *memcpy(void *__restrict, const void *__restrict, size_t);
void    *memmove(void *, const void *, size_t);
void    *memset(void *, int, size_t);

#ifdef __CX
char    *stpcpy(char *__restrict, const char *__restrict);
char    *stpncpy(char *__restrict, const char *__restrict, size_t);
#endif

char    *strcat(char *__restrict, const char *__restrict);
char    *strchr(const char *, int);
int      strcmp(const char *, const char *);
int      strcoll(const char *, const char *);

#ifdef __CX
int      strcoll_l(const char *, const char *, locale_t);
#endif

char    *strcpy(char *__restrict, const char *__restrict);
size_t   strcspn(const char *, const char *);

#ifdef __CX
char    *strdup(const char *);
#endif

char    *strerror(int);

#ifdef __CX
char    *strerror_l(int, locale_t);
int      strerror_r(int, char *, size_t);
#endif

size_t   strlen(const char *);
char    *strncat(char *__restrict, const char *__restrict, size_t);
int      strncmp(const char *, const char *, size_t);
char    *strncpy(char *__restrict, const char *__restrict, size_t);

#ifdef __CX
char    *strndup(const char *, size_t);
size_t   strnlen(const char *, size_t);
#endif

char    *strpbrk(const char *, const char *);
char    *strrchr(const char *, int);

#ifdef __CX
char    *strsignal(int);
#endif

size_t   strspn(const char *, const char *);
char    *strstr(const char *, const char *);
char    *strtok(char *__restrict, const char *__restrict);

#ifdef __CX
char    *strtok_r(char *__restrict, const char *__restrict, char **__restrict);
#endif

size_t   strxfrm(char *__restrict, const char *__restrict, size_t);

#ifdef __CX
size_t   strxfrm_l(char *__restrict, const char *__restrict, size_t, locale_t);
#endif
