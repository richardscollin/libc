#include <stdlib.h>
#include <stdint.h>

#include <unistd.h>
#include <syscall.h>


static int TEST_RESULTS = 0;

#define REGTEST

/* TESTCASE() - generic test */
#define TESTCASE(X) if (X) {} \
                      else { TEST_RESULTS += 1; _exit(1);}


#define TEST_CASES \
    X(test_strtod) \


#define X(test) int test(void);
TEST_CASES
#undef X

int test_stdlib()
{
#define X(test) test();
    TEST_CASES
#undef X
    return 0;
}

int test_strtod()
{
    char *endp;
    char * s = "    900.0  ";
    TESTCASE(strtod(s, &endp) == 900.0);
    TESTCASE(endp == s + 9);
    TESTCASE(strtod("1000", NULL) == 1000);
    TESTCASE(strtod("8700", NULL) == 8700);
    TESTCASE(strtod("+500", NULL) == 500);
    TESTCASE(strtod("-500", NULL) == -500);
    TESTCASE(strtod("0.5", NULL) == 0.5);
    TESTCASE(strtod(".5", NULL) == .5);
    TESTCASE(strtod("-.5", NULL) == -.5);
    TESTCASE(strtod("+.5", NULL) == .5);
    TESTCASE(strtod("0.75", NULL) == 0.75);

    /* Tests with Exponents */
    TESTCASE(strtod("1e3", NULL) == 1000);
    TESTCASE(strtod("1E5", NULL) == 100000);
    TESTCASE(strtod("1.5e5", NULL) == 150000);
    TESTCASE(strtod("1.e5", NULL) == 100000);
    TESTCASE(strtod("1.e+5", NULL) == 100000);
    TESTCASE(strtod("5.e-1", NULL) == .5);
    TESTCASE(strtod("1.2345675e5", NULL) == 123456.75);

    return 0;
}

