#ifndef _Noreturn

#if __STDC_VERSION__ >= 201101L
/*C11*/
#else
/*C89 or C99*/
#define _Noreturn
#endif /* STDC_VERSION */

#endif /* _Noreturn */
