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
    TESTCASE(strtod("0.5", NULL) == 0.5);
    TESTCASE(strtod("1000", NULL) == 1000);
    return 0;
}

