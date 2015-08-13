
#include <stdlib.h>
#include <ctype.h>

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


