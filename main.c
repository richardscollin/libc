#if 0
clang -Weverything -Werror "$0" && exec ./a.out "$@"
exit 1
#endif

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//#include "string.h"
//#include "assert.h"

int main(int argc, char *argv[])
{
    //char my_str[] = "Hello, world!";
    //assert(sizeof(my_str) == NS(strlen)(my_str) + 1);
    setlocale(LC_ALL, "en_US.utf8");
    const struct lconv * const lc = localeconv();

    printf("%s %s %s %s %s %s %s %s %s %s | %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
    lc->currency_symbol,
    lc->decimal_point,
    lc->grouping,
    lc->int_curr_symbol,
    lc->mon_decimal_point,
    lc->mon_grouping,
    lc->mon_thousands_sep,
    lc->negative_sign,
    lc->positive_sign,
    lc->thousands_sep,
    lc->frac_digits,
    lc->int_frac_digits,
    lc->int_n_cs_precedes,
    lc->int_n_sep_by_space,
    lc->int_n_sign_posn,
    lc->int_p_cs_precedes,
    lc->int_p_sep_by_space,
    lc->int_p_sign_posn,
    lc->n_cs_precedes,
    lc->n_sep_by_space,
    lc->n_sign_posn,
    lc->p_cs_precedes,
    lc->p_sep_by_space,
    lc->p_sign_posn);


    return 0;
}

