#ifndef __ARRAY_H__
#define __ARRAY_H__

typedef struct Element {
  void* data;
} Element;

typedef struct Array {
  int count;
  Element* elements;
} Array;

void array_release(Array ary) ;

#endif
