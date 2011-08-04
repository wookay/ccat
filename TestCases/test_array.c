// test_array.c
//                           wookay.noh at gmail.com

#include "ccat.h"

void test_array_join() {
  char* s = "a b c";
  Array ary = string_split(s, SPACE);
  String str = array_join(ary, ",");
  assert_true(3 == ary.count);
  assert_not_null(ary.elements);
  assert_true(5 == str.length);
  assert_true(string_equal("a,b,c", str.chars));
  array_release(ary);
  string_release(str);

  ary = empty_array();
  str = array_join(ary, ",");
  assert_true(0 == str.length);
  assert_true(string_equal("", str.chars));
  array_release(ary);
  string_release(str);
}

void test_empty_array() {
  Array ary = empty_array();
  assert_true(0 == ary.count);
  assert_null(ary.elements);
  array_release(ary);
}

int main() {
  unittest_setup();
  unittest_run(test_empty_array);
  unittest_run(test_array_join);
  unittest_report();
  return 0;
}
