// UnitTest.h
//                           wookay.noh at gmail.com

#include <stdio.h>
#include <sys/time.h>


void add_passed_count() ;
void add_failed_count() ;

#define assert_true(e)  \
  ((void) ((e) ? _got_passed(#e) : _raise_error(#e, __FILE__, __LINE__)))
#define _got_passed(e) \
  ((void) ((report.dot_if_passed) ? printf(".") : printf("passed: %s\n", e)), add_passed_count())
#define _raise_error(e, file, line) \
  ((void) printf("\nAssertion failed in %s:%u\n  %s\n", file, line, e), add_failed_count())
#define assert_false(e) assert_true(! e)
#define assert_null(e) assert_true(NULL == e)
#define assert_not_null(e) assert_true(NULL != e)

void unittest_setup() ;
void _unittest_run(void (*fun)()) ;
void unittest_report() ;

#define unittest_run(fun) _unittest_run(&fun)

// global structs
struct Report {
  int dot_if_passed;
  int tests;
  int passed;
  int failed;
  struct timeval startedAt;
};

struct Report report;
