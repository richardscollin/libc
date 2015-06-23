
#include "ns.h"
#include "common/null.h"
#include "common/size_t.h"

#define EOF (-1)

#define FOPEN_MAX 16
#define FILENAME_MAX 256

#define L_tmpnam 20

#define _IOFBF
#define _IOLBF
#define _IONBF

#define SEEK_CUR
#define SEEK_END
#define SEEK_SET


#define TMP_MAX 16

#define stdin ((FILE*)0)
#define stdout ((FILE*)1)
#define stderr ((FILE*)2)

#define BUFSIZ 256

int NS(remove)(const char *filename);


