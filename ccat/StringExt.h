// String.h
//                           wookay.noh at gmail.com

#include "ArrayExt.h"

#define string_equal(a,b) (0==strcmp(a,b))

#define NULL_CHAR '\0'
#define LF_CHAR '\n'
#define SPACE_CHAR ' '

#define LF "\n"
#define SPACE " "

int string_length(char* str) ;
Array string_split(char* str, char* sep) ;
