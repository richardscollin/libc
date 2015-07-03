#ifdef __restrict_h
#define __restrict_h

#if __STDC_VERSION__ >= 199901L
/*C99*/
#define __restrict restrict
#else
/*C89*/
#define __restrict
#endif /* STDC_VERSION */

#endif /* ___restrict_h */
