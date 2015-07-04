
#ifdef __need_Noreturn
#if __STDC_VERSION__ >= 201101L
/*C11*/
#else
/*C89 or C99*/
#define _Noreturn
#endif /* STDC_VERSION */
#undef __need_Noreturn
#endif /* _Noreturn */

#ifdef __need_NULL
#ifndef NULL
#define NULL ((void*)0)
#endif /* NULL */
#undef __need_NULL
#endif /*__need_NULL */

#ifdef __need_restrict
#ifndef __restrict
#if __STDC_VERSION__ >= 199901L
#define __restrict restrict
#else
#define __restrict
#endif /* STDC_VERSION */
#endif /* __restrict */
#undef __need_restrict
#endif /* ___need_restrict */

#ifdef __need_size_t
#ifndef __size_t
#define __size_t
typedef unsigned long int size_t;
#endif /* __size_t */
#undef __need_size_t
#endif /* __need_size_t */

#ifdef __need__syscall
extern long __syscall(long n, long p1, long p2, long p3, long p4, long p5);
#undef __need__syscall
#endif /* __need__syscall */

#ifdef __need_syscall
extern long syscall(long, ...);
#undef __need_syscall
#endif /* __need_syscall */

