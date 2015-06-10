#ifdef NDEBUG
#define assert(ignore) ((void) 0)
#else
#define assert(ASSERTION) \
    do {\
        if(!(ASSERTION)) {\
            fprintf(stderr, "%s:%d Assertion `%s' failed.\n",__FILE__, __LINE__, # ASSERTION);\
            abort();\
        }\
    } while(0);
#endif
