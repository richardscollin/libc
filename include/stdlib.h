
struct div_t {
    int quot;
    int rem;
};

typedef unsigned long size_t;

double strtod(const char *nptr, char **endptr);

void *bsearch(const void *key, const void *base,
        size_t nmemb, size_t size,
        int (*compar)(const void *, const void *));

