
// I have no idea what these are supposed to do I
// just wanted it to link properly
//
extern int main();
extern int exit();
int __libc_start_main(void)
{
    return exit(main());
}
