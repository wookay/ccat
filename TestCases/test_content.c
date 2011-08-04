// test_content.c
//                           wookay.noh at gmail.com

#include "ccat.h"
#include "Content.h"

void test_content() {
  Content content = content_for_current_directory_file(__FILE__); 
  //printf("content %d", content.length);
  assert_true(413 == content.length);

  content_release(content);
}

int main() {

  unittest_setup();
  unittest_run(test_content);
  unittest_report();

  return 0;
}
