// UnitTest.c
//                           wookay.noh at gmail.com

#include "UnitTest.h"
#include "TypeExt.h"

void add_passed_count() {
  report.passed += 1;
}

void add_failed_count() {
  report.failed += 1;
}

struct timeval get_current_time() {
  struct timeval t;
  gettimeofday(&t, NULL);
  return t;
}

void unittest_setup() {
  report.dot_if_passed = true;
  report.tests = 0;
  report.passed = 0;
  report.failed = 0;
  report.startedAt = get_current_time();

  printf("Started\n");
}

void unittest_report() {
  struct timeval endedAt = get_current_time();
  float elapsed = (endedAt.tv_sec - report.startedAt.tv_sec) + (endedAt.tv_usec - report.startedAt.tv_usec) / 1000000.0;
  printf("\nFinished in %.5f seconds.\n", elapsed);
  printf("%d tests, %d assertions, %d failures, %d errors\n",
    report.tests, report.passed, report.failed, 0);
}

void _unittest_run(void (*fun)()) {
  report.tests += 1;
  fun();
}
