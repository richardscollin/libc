
#include "ns.h"

int NS(isalnum)(int c);
int NS(isalpha)(int c);
int NS(iscntrl)(int c);
int NS(isdigit)(int c);
int NS(isgraph)(int c);
int NS(islower)(int c);
int NS(isprint)(int c);
int NS(ispunct)(int c);
int NS(isspace)(int c);
int NS(isupper)(int c);
int NS(isxdigit)(int c);

int NS(toupper)(int c);
int NS(tolower)(int c);

int NS(isascii)(int c);
int NS(isblank)(int c);

int NS(isalnum_l)(int c, locale_t locale);
int NS(isalpha_l)(int c, locale_t locale);
int NS(isblank_l)(int c, locale_t locale);
int NS(iscntrl_l)(int c, locale_t locale);
int NS(isdigit_l)(int c, locale_t locale);
int NS(isgraph_l)(int c, locale_t locale);
int NS(islower_l)(int c, locale_t locale);
int NS(isprint_l)(int c, locale_t locale);
int NS(ispunct_l)(int c, locale_t locale);
int NS(isspace_l)(int c, locale_t locale);
int NS(isupper_l)(int c, locale_t locale);
int NS(isxdigit_l)(int c, locale_t locale);

int isascii_l(int c, locale_t locale);

int toupper_l(int c, locale_t locale);
int tolower_l(int c, locale_t locale);


