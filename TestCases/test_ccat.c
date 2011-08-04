// test_ccat.c
//                           wookay.noh at gmail.com

#include "ccat.h"

void test_numbers() {
  assert_true(1 == 1); 
  assert_true(3.14 == 3.14); 
}

void test_strings() {
  assert_true(string_equal(NULL, NULL));
  assert_false(string_equal(NULL, ""));
  assert_false(string_equal("", NULL));
  assert_true(string_equal("", "")); 
  assert_true(string_equal("abc", "abc")); 
  assert_true(string_equal("abcdef", "abcdef")); 
}

int main() {

  unittest_setup();

  unittest_run(test_numbers);
  unittest_run(test_strings);

  unittest_report();

  return 0;
}
