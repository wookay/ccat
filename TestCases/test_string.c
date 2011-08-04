// test_string.c
//                           wookay.noh at gmail.com

#include "ccat.h"

void test_string_concat() {
  char* a = "a";
  char* b = "b";
  String str = string_concat(a, b);
  assert_true(2 == str.length);
  assert_true(string_equal("ab", str.chars));
  string_release(str);

  str = string_concat("", "");
  assert_true(0 == str.length);
  assert_true(string_equal("", str.chars));
  string_release(str);
}

void test_empty_string() {
  String str = empty_string();
  assert_true(0 == str.length);
  assert_true(string_equal("", str.chars));
  string_release(str);
}

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

  ary = string_split("hello", SPACE);
  assert_true(1 == ary.count);
  assert_true(string_equal("hello", ary.elements[0].data));
  array_release(ary);

  ary = string_split("hello", "");
  assert_true(5 == ary.count);
  assert_true(string_equal("h", ary.elements[0].data));
  assert_true(string_equal("e", ary.elements[1].data));
  assert_true(string_equal("l", ary.elements[2].data));
  assert_true(string_equal("l", ary.elements[3].data));
  assert_true(string_equal("o", ary.elements[4].data));
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
  unittest_run(test_string_concat);
  unittest_run(test_empty_string);
  unittest_run(test_string_split);
  unittest_run(test_chars);
  unittest_report();
  return 0;
}
