#include "StringExt.h"
#include "Memory.h"
#include "TypeExt.h"
#include <string.h>
#include <stdio.h>

typedef struct List {
  void* data;
  struct List* next;
} List;


List* list_prepend(List* list, void* data) {
  List* node = malloc(sizeof(List));
  node->data = data;
  if (NULL == list) {
    node->next = NULL;
  } else {
    node->next = list;
  }
  return node;
}

// glib g_strsplit
Array string_split(char* str, char* sep) {
  Array ary;

  const char* remainder = str;
  char* s = strstr(remainder, sep);
  int sep_length = strlen(sep);
  int cnt = 0;

  List* list = NULL;
  if (NULL != s) {
    while (NULL != s) {
      int len = s - remainder;
      char* buf = memory_alloc(len + 1);
      memcpy(buf, remainder, len);
      buf[len] = NULL_CHAR;
      list = list_prepend(list, buf);
      remainder = s + sep_length;
      s = strstr(remainder, sep);
      cnt += 1;
    } 
  }
  if (*remainder) {
    list = list_prepend(list, strdup(remainder));
    cnt += 1;
  }

  ary.count = cnt;
  Element* elements = memory_alloc(sizeof(Element) * cnt);
  cnt -= 1;
  if (NULL != list) {
    List* l = list;
    while (true) {
      elements[cnt].data = l->data;
      if (NULL == l->next) {
        break;
      } else {
        l = l->next;
      }
      cnt -= 1;
    }
  }
  ary.elements = elements;
  return ary;
}

int string_length(char* str) {
  return strlen(str);
}
