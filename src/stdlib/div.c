div_t div(int num, int denom)
{
    div_t result;
    result.quot = num / denom;
    result.rem = num - (result.quot * denom);
    return result;
}

ldiv_t ldiv(long num, long denom)
{
    ldiv_t result;
    result.quot = num / denom;
    result.rem = num - (result.quot * denom);
    return result;
}

#if __STDC_VERSION__ >= 199901L
lldiv_t lldiv(long long num, long long denom)
{
    lldiv_t result;
    result.quot = num / denom;
    result.rem = num - (result.quot * denom);
    return result;
}
#endif

