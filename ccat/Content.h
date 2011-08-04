#include "TypeExt.h"

typedef struct Path {
  char* full_path;
} Path;

Path path_for_current_directory_file(char* name) ;
String string_for_current_directory_file(char* name) ;
String string_for_path(Path path) ;
