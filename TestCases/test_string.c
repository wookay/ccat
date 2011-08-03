// test_string.c
//                           wookay.noh at gmail.com

#include "ccat.h"

void test_string_split() {
  char* str = "a b c";
  Array ary = string_split(str, SPACE);
  assert_true(3 == ary.count);
  assert_true(string_equal("a", ary.elements[0].data));
  assert_true(string_equal("b", ary.elements[1].data));
  assert_true(string_equal("c", ary.elements[2].data));
  array_release(ary);

  ary = string_split("", SPACE);
  assert_true(0 == ary.count);
  array_release(ary);

  ary = string_split(NULL, SPACE);
  assert_true(0 == ary.count);
  array_release(ary);

  ary = string_split(NULL, NULL);
  assert_true(0 == ary.count);
  assert_true(0 == ary.count);
  array_release(ary);
}

void test_chars() {
  char chars[] = {'a','b','c','\0'};
  assert_true(string_equal("abc", chars));

  assert_true(3 == string_length("abc"));

  assert_true(4 == sizeof("abc"));
  assert_true(4 == sizeof(chars));

  assert_true('a' == "abc"[0]);
  assert_true('b' == "abc"[1]);
  assert_true('c' == "abc"[2]);
  assert_true('\0'== "abc"[3]);
}

int main() {
  unittest_setup();
  unittest_run(test_string_split);
  unittest_run(test_chars);
  unittest_report();
  return 0;
}
