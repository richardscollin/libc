#ifdef NDEBUG
#define assert(ignore) ((void) 0)
#else
void __assert(int assertion, char *str_assertion, char *file, int line);
#define assert(ASSERTION) __assert((ASSERTION), #ASSERTION, __FILE__, __LINE__)
#endif
