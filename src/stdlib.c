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
    size_t lo = 0, hi = nmemb;
    while (lo <= hi) {
        size_t mid = nmemb / 2;
        uintptr_t center = (uintptr_t) base + mid * size;
        int ans = compar(key, (void*)center);

        if (ans < 0) {
            hi = lo + (nmemb = mid) - 1;
        } else if (ans > 0) {
            base = (void*)(center + (lo = size));
            nmemb -= mid;
        } else { /* ans == 0 */
            return (void*)center;
        }
    }
    return NULL;
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

