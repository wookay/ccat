// String.h
//                           wookay.noh at gmail.com

#include "TypeExt.h"

#define string_equal(a,b) (0==strcmp(a,b))

#define NULL_CHAR '\0'
#define LF_CHAR '\n'
#define SPACE_CHAR ' '

#define LF "\n"
#define SPACE " "

int string_length(char* str) ;
String empty_string() ;
Array string_split(char* str, char* sep) ;
String string_concat(char* a, char* b) ;
void string_release(String str) ;
