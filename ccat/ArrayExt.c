#include "Memory.h"
#include "ArrayExt.h"
#include "StringExt.h"
#include <string.h>

void array_release(Array ary) {
  int idx;
  for (idx = 0; idx < ary.count; idx++) {
    memory_free(ary.elements[idx].data);
  }
  memory_free(ary.elements);
}

Array empty_array() {
  Array ary;
  ary.count = 0;
  ary.elements = NULL;
  return ary;
}

String array_join(Array ary, char* sep) {
  if (0 == ary.count) {
    return empty_string();
  }
  size_t s_length = 0;
  int idx;
  int sep_length = strlen(sep);
  for (idx = 0; idx < ary.count; idx++) {  
    char* s = ary.elements[idx].data;
    s_length += strlen(s);
    if (idx != ary.count - 1) {
      s_length += sep_length;
    }
  }
  char* join_str = memory_alloc(s_length + 1);
  size_t join_str_offset = 0;
  for (idx = 0; idx < ary.count; idx++) {  
    char* s = ary.elements[idx].data;
    strcpy(join_str + join_str_offset, s);
    join_str_offset += strlen(s);
    if (idx != ary.count - 1) {
      strcpy(join_str + join_str_offset, sep);
      join_str_offset += sep_length;
    }
  }
  String str;
  str.length = s_length;
  str.chars = join_str;
  return str;
}
