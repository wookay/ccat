// TypeExt.h
//                           wookay.noh at gmail.com

#ifndef __TYPEEXT_H__
#define __TYPEEXT_H__

#define true 1
#define false 0


typedef struct Element {
  void* data;
} Element;

typedef struct Array {
  int count;
  Element* elements;
} Array;

typedef struct String {
  int length;
  char* chars;
} String;


#endif
