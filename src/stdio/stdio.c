
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


int puts(const char *s)
{
    write(1, s, strlen(s));
    write(1, "\n", 1);
}

/* %[flags][width][.precision][length]specifier */

char *specifiers = "diuoxXfFeEgGaAcspn";

void format(char *format_str, char *output, .../* generic arg */)
{
    char * format_char = strpbrk(format_str, specifiers);
    switch (*format_char) {
        case 'd':
        case 'i': /* signed decimal */
        case 'u': /* unsigned decimal*/
        case 'o': /* unsigned octal */
        case 'x': /* unsigned hex */
        case 'X': /* unsigned hex */
        case 'f': /* decimal floating point */
        case 'F': /* decimal floating point */
        case 'e': /* scientific notation lower */
        case 'E': /* scientific notation upper */
        case 'g': /* use shortest representation */
        case 'G': /* use shortest representation */
        case 'a': /* hex floating point lower */
        case 'A': /* hex floating point upper */
        case 'c': /* character */
        case 's': /* string */
        case 'p': /* pointer address */
        case 'n': /* nothing printed: characters printed stored in variable */
        case '%': /* print a % */
        default: return;
    }
}

char *to_decimal(int n)
{
    int radix = 10;

    n % radix

}
