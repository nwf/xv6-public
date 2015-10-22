#include "types.h"
#include "user.h"
#include "uthr.h"

#define TEST_NAME "318_main_te"
#include "318_test-tapish.h"

void f(void *a) {
  sleep(5);
  TEST_FINI();
  uthr_exit(0);
}

int main() {
  TEST_STRT(1);
  TEST_EXIT_IF(uthr_init(1024) < 0, "thr_init");
  TEST_EXIT_IF(uthr_create(f, 0) < 0, "thr_create");
  uthr_exit(0);
}
