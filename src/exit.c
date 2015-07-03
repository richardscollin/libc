
#include <unistd.h>

#include <sys/syscall.h>
extern long __syscall();

static void (*cb[_SC_ATEXIT_MAX])(void);/*array of exit callbacks*/
static int num_cb;/*number of exit callbacks*/

int atexit(void (*func)(void))
{
    /*this is not thread-safe*/
    return ((num_cb < _SC_ATEXIT_MAX) ? (cb[num_cb++] = func),0 : 1);
}

void exit(int status)
{
    int i = 0;
    while (cb[i])
        cb[i++]();/*call all callbacks*/
    /*TODO flush and close all filehandles*/
    _exit(status);
}

void _Noreturn _exit(int status)
{
    __syscall(__NR_exit, status);
    while(1);/*gets rid of spurios warning*/
}

