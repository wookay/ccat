// test_memory.c
//                           wookay.noh at gmail.com

#include "ccat.h"

typedef struct Line {
  char* chars;
} Line;

typedef struct Struct {
  Line* lines;
} Struct;

#define memory_alloc malloc
#define memory_release free

Line* make_lines(int n) {
  Line* lines = memory_alloc(n * sizeof(Line));
  lines[0].chars = "abc"; 
  lines[1].chars = "def"; 
  lines[2].chars = "def"; 
  return lines;
}


void test_null() {
  char* str = NULL;
  assert_true(string_equal(NULL, NULL));
  assert_true(0 == NULL);
}

void test_struct() {
  Struct s;
  Line* lines = make_lines(5);
  s.lines = lines;
  assert_true(string_equal("abc", s.lines[0].chars));
  assert_true(string_equal("def", s.lines[1].chars));
  assert_true(string_equal("def", s.lines[2].chars));
  memory_release(s.lines);

  //assert_true(string_equal("abc", s.line.chars));
//  assert_true(string_equal("abc", s.lines[0].chars));
}


int main() {

  unittest_setup();

  unittest_run(test_struct);
  unittest_run(test_null);

  unittest_report();

  return 0;
}
