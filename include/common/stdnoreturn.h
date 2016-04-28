#ifndef __STDNORETURN_H
#define __STDNORETURN_H

#if __STDC_VERSION__ >= 201101L
/*C11*/
#define noreturn _Noreturn
#else
/*C89 or C99*/
#define noreturn
#endif /* STDC_VERSION */

#endif /* __STDNORETURN_H */
