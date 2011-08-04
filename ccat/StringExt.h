// String.h
//                           wookay.noh at gmail.com

#include "TypeExt.h"


#define NULL_CHAR '\0'
#define LF_CHAR '\n'
#define SPACE_CHAR ' '

#define LF "\n"
#define SPACE " "

String empty_string() ;
void string_release(String str) ;
String string_concat(char* a, char* b) ;
Array string_split(char* str, char* sep) ;

int string_length(char* str) ;
int string_equal(char* a, char* b) ;
