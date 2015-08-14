
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>

#include <math.h>

#include <string.h>

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

double atof(const char *s)
{
    return strtod(s, (char **)NULL);
}

void *bsearch(const void *key, const void *base,
        size_t nmemb, size_t size,
        int (*compar)(const void *, const void *))
{
    size_t target = nmemb / 2;
    uintptr_t center = (uintptr_t) base + target;
    int ans = compar(key, (void*)center);

    if (ans < 0) {
        return bsearch(key, base, target, size, compar);
    } else if (ans > 0) {
        return bsearch(key, (void*)center, target, size, compar);
    } else { /* ans == 0 */
        return (void*)center;
    }
}


