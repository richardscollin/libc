#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>

double strtod(const char *s, char **endptr)
{
    size_t i = 0;
    int seen_decimal = 0;
    int sign = 1;
    double total = 0.0;
    double divisor = 10;

    /* ignore leading whitespace*/
    while (*s != '\0' && isspace(*s))
        s++;

    /* optional leading sign */
    if (*s == '-') {
        sign = -1;
        i++;
    } else if (*s == '+') {
        i++;
    }

    while (s[i] != '\0') {

        if (s[i] == '.') {
            if (seen_decimal) {
                /* done - seen two decimals*/
                goto done;
            }
            seen_decimal = 1;
            i++;
        }
        if (tolower(s[i]) == 'e') {
            /* TODO fix this terrible hack*/
            double multiplier = 1;
            int exponent = (int)strtod(s + ++i, endptr);
            int j;
            if (exponent > 0)
                for (j = 0; j < exponent; j++, multiplier *= 10);
            else
                for (j = 0; j < -exponent; j++, multiplier /= 10);
            total *= multiplier;
            goto done;
        } else if (!isdigit(s[i])) {
            /* done - saw something that isn't a digit*/
            goto done;
        }

        if (!seen_decimal) {
            /* TODO check for overflow */
            total *= 10;
            total += sign * (s[i] - '0');
        } else {
            /* TODO check for underflow */
            total += sign * (s[i] - '0') / divisor; /* TODO
            this is a very naive way to do this
            it is prone to errors because IEEE division
            is not exact
            */
            divisor *= 10;
        }
        i++;
    }
done:
    if (endptr != NULL)
        *endptr = (char *)(s + i);
    return total;
}

#undef atof
double atof(const char *s)
{
    return strtod(s, (char **)NULL);
}


void *bsearch(const void *key, const void *base,
        size_t nmemb, size_t size,
        int (*compar)(const void *, const void *))
{
    while (1) {
        size_t mid = nmemb / 2;
        uintptr_t center = (uintptr_t) base + mid * size;
        int ans = compar(key, (void*)center);

        if (ans < 0) {
            nmemb = mid;
        } else if (ans > 0) {
            base = (void*)(center + size);
            nmemb = nmemb - mid;
        } else { /* ans == 0 */
            return (void*)center;
        }
    }
}

static void memswap(void *a, void *b, size_t size)
{
    /* swap a char at a time */
    char *p1 = a, *p2 = b;
    char buf;
    size_t i;

    if (a == b) return; /* this case is pretty common */

    for (i = 0; i < size; i++) {
        buf = p1[i];
        p1[i] = p2[i];
        p2[i] = buf;
    }
}

static size_t partition(void *base, size_t nmemb,
        size_t size,
        int (*compar)(const void *, const void *))
{
    /* Using Lomuto's Partitioning Scheme as described in
     * Introduction to Algorithms by Cormen et al.
     */
    void *elem = base, *pivot = (void *)((uintptr_t)base + (nmemb - 1) * size);
    size_t i /* index of partition divider */, j /* looping variable */;
    for (i = j = 0; j < nmemb - 1; j++, elem = (void*)((uintptr_t)elem + size))
        if (compar(elem, pivot) < 0)
            memswap((void*)((uintptr_t)base + size * i++), elem, size);
    memswap((void*)((uintptr_t)base + size * i), pivot, size);
    return i;
}

void qsort(void *base, size_t nmemb, size_t size,
        int (*compar)(const void *, const void *))
{
    if (nmemb > 1) {
        size_t pivot = partition(base, nmemb, size, compar);
        qsort(base, pivot, size, compar);
        qsort((void *)((uintptr_t)base + size * (pivot + 1)),
                nmemb - (pivot + 1), size, compar);
    }
}

int abs(int j)
{
    return (j < 0) ? -j : j;
}
long int labs(long int j)
{
    return (j < 0) ? -j : j;
}
#if __STDC_VERSION__ >= 199901L
long long int llabs(long long int j)
{
    return (j < 0) ? -j : j;
}
#endif

div_t div(int num, int denom)
{
    div_t result;
    result.quot = num / denom;
    result.rem = num - (result.quot * denom);
    return result;
}

ldiv_t ldiv(long num, long denom)
{
    ldiv_t result;
    result.quot = num / denom;
    result.rem = num - (result.quot * denom);
    return result;
}

