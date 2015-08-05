#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *hello = "hello world\n";
    write(1, hello, strlen(hello));
    return 0;
}

