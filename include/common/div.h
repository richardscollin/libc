#ifdef __need_div_t
#ifndef __div_t
#define __div_t
typedef struct {
    int quot;
    int rem;
} div_t;
#endif /* __div_t*/
#undef __need_div_t
#endif /* __need_div_t */

#ifdef __need_ldiv_t
#ifndef __ldiv_t
#define __ldiv_t
typedef struct {
    long quot;
    long rem;
} ldiv_t;
#endif /* __ldiv_t*/
#undef __need_ldiv_t
#endif /* __need_ldiv_t */

#ifdef __need_lldiv_t
#ifndef __lldiv_t
#define __lldiv_t
typedef struct {
    long long quot;
    long long rem;
} lldiv_t;
#endif /* __lldiv_t*/
#undef __need_lldiv_t
#endif /* __need_lldiv_t */
