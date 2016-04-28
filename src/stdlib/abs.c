int abs(int j)
{
    return (j < 0) ? -j : j;
}
long int labs(long int j)
{
    return (j < 0) ? -j : j;
}

#if __STDC_VERSION__ >= 199901L
long long int llabs(long long int j)
{
    return (j < 0) ? -j : j;
}
#endif
