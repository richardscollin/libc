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
