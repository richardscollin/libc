
#ifndef __stdlib_h
#define __stdlib_h

#ifndef NULL
#define NULL ((void*) 0)
#endif

typedef struct {
    int quot;
    int rem;
} div_t;

typedef struct {
    long quot;
    long rem;
} ldiv_t;

typedef unsigned long size_t;

double strtod(const char *nptr, char **endptr);

double atof(const char *s);
#define atof(s) (strtod(s, (char **)NULL))



void *bsearch(const void *key, const void *base,
        size_t nmemb, size_t size,
        int (*compar)(const void *, const void *));

div_t div(int num, int denom);
ldiv_t ldiv(long num, long denom);

int abs(int n);
long labs(long n);
#if __STDC_VERSION__ >= 199901L
long long llabs(long long n);
#endif

#endif
