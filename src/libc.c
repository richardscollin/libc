
/* I have no idea what these are supposed to do I
 * just wanted it to link properly
 */
extern int main();
extern void exit(int);
int __libc_start_main(void)
{
    exit(main());
    return 1;/* should not execute*/
}
