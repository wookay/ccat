ccat
====

unit testing for C.


```c
#include "ccat.h"

void test_numbers() {
  assert_true(1 == 1);
  assert_true(3.14 == 3.14);
}

void test_strings() {
  assert_true(string_equal("abc", "abc"));
  assert_true(string_equal("abcdef", "abcdef"));
  assert_true(string_equal("abcdef", "abcdefg"));
}

int main() {

  unittest_setup();

  unittest_run(test_numbers);
  unittest_run(test_strings);

  unittest_report();

}
```


    $ gcc test_ccat.c ../ccat/UnitTest.c -I../ccat -o test_ccat.out
    $ ./test_ccat.out
    Started
    ....
    Assertion failed in test_ccat.c:14
      string_equal("abcdef", "abcdefg")

    Finished in 0.00011 seconds.
    2 tests, 4 assertions, 1 failures, 0 errors
