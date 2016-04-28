#ifndef __stdlib_h
#define __stdlib_h

#define __need_EXIT_STATUS
#define __need_NULL
#define __need_RAND_MAX
#define __need_div_t
#define __need_ldiv_t
#define __need_lldiv_t
#define __need_size_t
#define __need_wchar_t
#include "common/feature.h"

/* Note read the bottom of man stdlib.h
 * inclusion of stdlib.h may result in
 * exposing all symbols in stddef.h limits.h
 * math.h and sys/wait.h
 * It might be easier to just include those
 * than do the whole feature macro thing.*/

double strtod(const char *nptr, char **endptr);

double atof(const char *s);
#define atof(s) (strtod(s, (char **)NULL))



void *bsearch(const void *key, const void *base,
        size_t nmemb, size_t size,
        int (*compar)(const void *, const void *));

void qsort(void *base, size_t nmemb, size_t size,
        int (*compar)(const void *, const void *));

div_t div(int num, int denom);
ldiv_t ldiv(long num, long denom);

int abs(int n);
long labs(long n);
#if __STDC_VERSION__ >= 199901L
long long llabs(long long n);
#endif

#endif
