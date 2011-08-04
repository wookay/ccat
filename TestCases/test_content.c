// test_content.c
//                           wookay.noh at gmail.com

#include "ccat.h"
#include "Content.h"

void test_content() {
  String str = string_for_current_directory_file(__FILE__); 
  //printf("str length: %d", str.length);
  assert_true(397 == str.length);
  string_release(str);
}

int main() {

  unittest_setup();
  unittest_run(test_content);
  unittest_report();

  return 0;
}
