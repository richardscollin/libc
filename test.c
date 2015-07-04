#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "string.h"

#include <unistd.h>
#include <syscall.h>

static char abcde[] = "abcde";
static char abcdx[] = "abcdx";
static char teststring[] = "1234567890\nABCDEFGHIJKLMNOPQRSTUVWXYZ\nabcdefghijklmnopqrstuvwxyz\n";
static int TEST_RESULTS = 0;

#define REGTEST

/* TESTCASE() - generic test */
#define TESTCASE(X) if (X) {} \
                      else { TEST_RESULTS += 1; _exit(1);}

/*also copies null terminator*/
static void _strcpy(char *s1, char *s2)
{
    while ((*s1++ = *s2++));
}

static void reset_strings(void)
{
    _strcpy(abcde, "abcde");
    _strcpy(abcdx, "abcdx");
    _strcpy(teststring, "1234567890\nABCDEFGHIJKLMNOPQRSTUVWXYZ\nabcdefghijklmnopqrstuvwxyz\n");
}


#define TEST_CASES \
    X(test_memchr) \
    X(test_memcmp) \
    X(test_memcpy) \
    X(test_memmove) \
    X(test_memset) \
    X(test_strcat) \
    X(test_strchr) \
    X(test_strcmp) \
    X(test_strcoll) \
    X(test_strcpy) \
    X(test_strcspn) \
    X(test_strdup) \
    X(test_strlen) \
    X(test_strncat) \
    X(test_strncmp) \
    X(test_strncpy) \
    X(test_strndup) \
    X(test_strnlen) \
    X(test_strpbrk) \
    X(test_strtchr) \
    X(test_strspn) \
    X(test_strstr) \
    X(test_strtok) \

#define X(test) int test(void);
TEST_CASES
#undef X

int main()
{
#define X(test) reset_strings(); test();
    TEST_CASES
#undef X
    return 0;
}


int test_memchr( void )
{
    TESTCASE( memchr( abcde, 'c', 5 ) == &abcde[2] );
    TESTCASE( memchr( abcde, 'a', 1 ) == &abcde[0] );
    TESTCASE( memchr( abcde, 'a', 0 ) == NULL );
    TESTCASE( memchr( abcde, '\0', 5 ) == NULL );
    TESTCASE( memchr( abcde, '\0', 6 ) == &abcde[5] );
    return TEST_RESULTS;
}
int test_memcmp( void )
{
    char const xxxxx[] = "xxxxx";
    TESTCASE( memcmp( abcde, abcdx, 5 ) < 0 );
    TESTCASE( memcmp( abcde, abcdx, 4 ) == 0 );
    TESTCASE( memcmp( abcde, xxxxx, 0 ) == 0 );
    TESTCASE( memcmp( xxxxx, abcde, 1 ) > 0 );
    return 0;
}

int test_memcpy( void )
{
    char s[] = "xxxxxxxxxxx";
    TESTCASE( memcpy( s, abcde, 6 ) == s );
    TESTCASE( s[4] == 'e' );
    TESTCASE( s[5] == '\0' );
    TESTCASE( memcpy( s + 5, abcde, 5 ) == s + 5 );
    TESTCASE( s[9] == 'e' );
    TESTCASE( s[10] == 'x' );
    return TEST_RESULTS;
}

int test_memmove( void )
{
    char s[] = "xxxxabcde";
    TESTCASE( memmove( s, s + 4, 5 ) == s );
    TESTCASE( s[0] == 'a' );
    TESTCASE( s[4] == 'e' );
    TESTCASE( s[5] == 'b' );
    TESTCASE( memmove( s + 4, s, 5 ) == s + 4 );
    TESTCASE( s[4] == 'a' );
    return TEST_RESULTS;
}

int test_memset( void )
{
    char s[] = "xxxxxxxxx";
    TESTCASE( memset( s, 'o', 10 ) == s );
    TESTCASE( s[9] == 'o' );
#pragma GCC diagnostic ignored "-Wmemset-transposed-args"
    TESTCASE( memset( s, '_', 0 ) == s );
    TESTCASE( s[0] == 'o' );
    TESTCASE( memset( s, '_', 1 ) == s );
    TESTCASE( s[0] == '_' );
    TESTCASE( s[1] == 'o' );
    return TEST_RESULTS;
}

int test_strcat( void )
{
    char s[] = "xx\0xxxxxx";
    TESTCASE( strcat( s, abcde ) == s );
    TESTCASE( s[2] == 'a' );
    TESTCASE( s[6] == 'e' );
    TESTCASE( s[7] == '\0' );
    TESTCASE( s[8] == 'x' );
    s[0] = '\0';
    TESTCASE( strcat( s, abcdx ) == s );
    TESTCASE( s[4] == 'x' );
    TESTCASE( s[5] == '\0' );
    TESTCASE( strcat( s, "\0" ) == s );
    TESTCASE( s[5] == '\0' );
    TESTCASE( s[6] == 'e' );
    return TEST_RESULTS;
}

int test_strchr( void )
{
    char abccd[] = "abccd";
    TESTCASE( strchr( abccd, 'x' ) == NULL );
    TESTCASE( strchr( abccd, 'a' ) == &abccd[0] );
    TESTCASE( strchr( abccd, 'd' ) == &abccd[4] );
    TESTCASE( strchr( abccd, '\0' ) == &abccd[5] );
    TESTCASE( strchr( abccd, 'c' ) == &abccd[2] );
    return TEST_RESULTS;
}

int test_strcmp( void )
{
    char cmpabcde[] = "abcde";
    char cmpabcd_[] = "abcd\xfc";
    char empty[] = "";
    TESTCASE( strcmp( abcde, cmpabcde ) == 0 );
    TESTCASE( strcmp( abcde, abcdx ) < 0 );
    TESTCASE( strcmp( abcdx, abcde ) > 0 );
    TESTCASE( strcmp( empty, abcde ) < 0 );
    TESTCASE( strcmp( abcde, empty ) > 0 );
    TESTCASE( strcmp( abcde, cmpabcd_ ) < 0 );
    return TEST_RESULTS;
}

int test_strcoll( void )
{
    char cmpabcde[] = "abcde";
    char empty[] = "";
    TESTCASE( strcmp( abcde, cmpabcde ) == 0 );
    TESTCASE( strcmp( abcde, abcdx ) < 0 );
    TESTCASE( strcmp( abcdx, abcde ) > 0 );
    TESTCASE( strcmp( empty, abcde ) < 0 );
    TESTCASE( strcmp( abcde, empty ) > 0 );
    return TEST_RESULTS;
}

int test_strcpy( void )
{
    char s[] = "xxxxx";
    TESTCASE( strcpy( s, "" ) == s );
    TESTCASE( s[0] == '\0' );
    TESTCASE( s[1] == 'x' );
    TESTCASE( strcpy( s, abcde ) == s );
    TESTCASE( s[0] == 'a' );
    TESTCASE( s[4] == 'e' );
    TESTCASE( s[5] == '\0' );
    return TEST_RESULTS;
}

int test_strcspn( void )
{
    TESTCASE( strcspn( abcde, "x" ) == 5 );
    TESTCASE( strcspn( abcde, "xyz" ) == 5 );
    TESTCASE( strcspn( abcde, "zyx" ) == 5 );
    TESTCASE( strcspn( abcdx, "x" ) == 4 );
    TESTCASE( strcspn( abcdx, "xyz" ) == 4 );
    TESTCASE( strcspn( abcdx, "zyx" ) == 4 );
    TESTCASE( strcspn( abcde, "a" ) == 0 );
    TESTCASE( strcspn( abcde, "abc" ) == 0 );
    TESTCASE( strcspn( abcde, "cba" ) == 0 );
    return TEST_RESULTS;
}

int test_strdup( void )
{
#ifndef REGTEST
    const char *teststr  = "Hello, world";
    const char *teststr2 = "An alternative test string with non-7-bit characters \xFE\x8C\n";
    char *testres, *testres2;

    TESTCASE(testres  = strdup(teststr));
    TESTCASE(testres2 = strdup(teststr2));
    TESTCASE(strcmp(testres, teststr) == 0);
    TESTCASE(strcmp(testres2, teststr2) == 0);
    free(testres);
    free(testres2);
#endif
    
    return TEST_RESULTS;
}

int test_strlen( void )
{
    TESTCASE( strlen( abcde ) == 5 );
    TESTCASE( strlen( "" ) == 0 );
    return TEST_RESULTS;
}
int test_strncat( void )
{
    char s[] = "xx\0xxxxxx";
    TESTCASE( strncat( s, abcde, 10 ) == s );
    TESTCASE( s[2] == 'a' );
    TESTCASE( s[6] == 'e' );
    TESTCASE( s[7] == '\0' );
    TESTCASE( s[8] == 'x' );
    s[0] = '\0';
    TESTCASE( strncat( s, abcdx, 10 ) == s );
    TESTCASE( s[4] == 'x' );
    TESTCASE( s[5] == '\0' );
    TESTCASE( strncat( s, "\0", 10 ) == s );
    TESTCASE( s[5] == '\0' );
    TESTCASE( s[6] == 'e' );
    TESTCASE( strncat( s, abcde, 0 ) == s );
    TESTCASE( s[5] == '\0' );
    TESTCASE( s[6] == 'e' );
    TESTCASE( strncat( s, abcde, 3 ) == s );
    TESTCASE( s[5] == 'a' );
    TESTCASE( s[7] == 'c' );
    TESTCASE( s[8] == '\0' );
    return TEST_RESULTS;
}
int test_strncmp( void )
{
    char cmpabcde[] = "abcde\0f";
    char cmpabcd_[] = "abcde\xfc";
    char empty[] = "";
    char x[] = "x";
    TESTCASE( strncmp( abcde, cmpabcde, 5 ) == 0 );
    TESTCASE( strncmp( abcde, cmpabcde, 10 ) == 0 );
    TESTCASE( strncmp( abcde, abcdx, 5 ) < 0 );
    TESTCASE( strncmp( abcdx, abcde, 5 ) > 0 );
    TESTCASE( strncmp( empty, abcde, 5 ) < 0 );
    TESTCASE( strncmp( abcde, empty, 5 ) > 0 );
    TESTCASE( strncmp( abcde, abcdx, 4 ) == 0 );
    TESTCASE( strncmp( abcde, x, 0 ) == 0 );
    TESTCASE( strncmp( abcde, x, 1 ) < 0 );
    TESTCASE( strncmp( abcde, cmpabcd_, 10 ) < 0 );
    return TEST_RESULTS;
}

int test_strncpy( void )
{
    char s[] = "xxxxxxx";
    TESTCASE( strncpy( s, "", 1 ) == s );
    TESTCASE( s[0] == '\0' );
    TESTCASE( s[1] == 'x' );
    TESTCASE( strncpy( s, abcde, 6 ) == s );
    TESTCASE( s[0] == 'a' );
    TESTCASE( s[4] == 'e' );
    TESTCASE( s[5] == '\0' );
    TESTCASE( s[6] == 'x' );
    TESTCASE( strncpy( s, abcde, 7 ) == s );
    TESTCASE( s[6] == '\0' );
    TESTCASE( strncpy( s, "xxxx", 3 ) == s );
    TESTCASE( s[0] == 'x' );
    TESTCASE( s[2] == 'x' );
    TESTCASE( s[3] == 'd' );
    return TEST_RESULTS;
}

int test_strndup( void )
{
#ifndef REGTEST
    /* Missing on Windows. Maybe use conditionals? */
    const char *teststr  = "Hello, world";
    const char *teststr2 = "\xFE\x8C\n";
    char *testres, *testres2;

    TESTCASE(testres  = strndup(teststr, 5));
    TESTCASE(testres2 = strndup(teststr2, 1));
    TESTCASE(strcmp(testres, teststr) != 0);
    TESTCASE(strncmp(testres, teststr, 5) == 0);
    TESTCASE(strcmp(testres2, teststr2) != 0);
    TESTCASE(strncmp(testres2, teststr2, 1) == 0);
    free(testres);
    free(testres2);
    TESTCASE(testres  = strndup(teststr, 20));
    TESTCASE(testres2 = strndup(teststr2, 5));
    TESTCASE(strcmp(testres, teststr) == 0);
    TESTCASE(strcmp(testres2, teststr2) == 0);
    free(testres);
    free(testres2);
#endif
    return TEST_RESULTS;
}

int test_strnlen( void )
{
    TESTCASE( strnlen( abcde, 5 ) == 5 );
    TESTCASE( strnlen( abcde, 3 ) == 3 )
    TESTCASE( strnlen( "", SIZE_MAX ) == 0 );
    return TEST_RESULTS;
}

int test_strpbrk( void )
{
    TESTCASE( strpbrk( abcde, "x" ) == NULL );
    TESTCASE( strpbrk( abcde, "xyz" ) == NULL );
    TESTCASE( strpbrk( abcdx, "x" ) == &abcdx[4] );
    TESTCASE( strpbrk( abcdx, "xyz" ) == &abcdx[4] );
    TESTCASE( strpbrk( abcdx, "zyx" ) == &abcdx[4] );
    TESTCASE( strpbrk( abcde, "a" ) == &abcde[0] );
    TESTCASE( strpbrk( abcde, "abc" ) == &abcde[0] );
    TESTCASE( strpbrk( abcde, "cba" ) == &abcde[0] );
    return TEST_RESULTS;
}
int test_strtchr( void )
{
    char abccd[] = "abccd";
    TESTCASE( strrchr( abcde, '\0' ) == &abcde[5] );
    TESTCASE( strrchr( abcde, 'e' ) == &abcde[4] );
    TESTCASE( strrchr( abcde, 'a' ) == &abcde[0] );
    TESTCASE( strrchr( abccd, 'c' ) == &abccd[3] );
    return TEST_RESULTS;
}

int test_strspn( void )
{
    TESTCASE( strspn( abcde, "abc" ) == 3 );
    TESTCASE( strspn( abcde, "b" ) == 0 );
    TESTCASE( strspn( abcde, abcde ) == 5 );
    return TEST_RESULTS;
}
int test_strstr( void )
{
    char s[] = "abcabcabcdabcde";
    TESTCASE( strstr( s, "x" ) == NULL );
    TESTCASE( strstr( s, "xyz" ) == NULL );
    TESTCASE( strstr( s, "a" ) == &s[0] );
    TESTCASE( strstr( s, "abc" ) == &s[0] );
    TESTCASE( strstr( s, "abcd" ) == &s[6] );
    TESTCASE( strstr( s, "abcde" ) == &s[10] );
    return TEST_RESULTS;
}

int test_strtok( void )
{
    char s[] = "_a_bc__d_";
    TESTCASE( strtok( s, "_" ) == &s[1] );
    TESTCASE( s[1] == 'a' );
    TESTCASE( s[2] == '\0' );
    TESTCASE( strtok( NULL, "_" ) == &s[3] );
    TESTCASE( s[3] == 'b' );
    TESTCASE( s[4] == 'c' );
    TESTCASE( s[5] == '\0' );
    TESTCASE( strtok( NULL, "_" ) == &s[7] );
    TESTCASE( s[6] == '_' );
    TESTCASE( s[7] == 'd' );
    TESTCASE( s[8] == '\0' );
    TESTCASE( strtok( NULL, "_" ) == NULL );
    strcpy( s, "ab_cd" );
    TESTCASE( strtok( s, "_" ) == &s[0] );
    TESTCASE( s[0] == 'a' );
    TESTCASE( s[1] == 'b' );
    TESTCASE( s[2] == '\0' );
    TESTCASE( strtok( NULL, "_" ) == &s[3] );
    TESTCASE( s[3] == 'c' );
    TESTCASE( s[4] == 'd' );
    TESTCASE( s[5] == '\0' );
    TESTCASE( strtok( NULL, "_" ) == NULL );
    return TEST_RESULTS;
}

