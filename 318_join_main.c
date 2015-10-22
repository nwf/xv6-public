#include "types.h"
#include "user.h"
#include "uthr.h"

#define TEST_NAME "318_join_main"
#include "318_test-tapish.h"

int x;

void f(void *a) {
  int mtid = (int)a;
  void *hand;

  TEST_DIAG("in thread");
  sleep(5);
  TEST_EXIT_IF(uthr_join(mtid, &hand) < 0, "join");
  TEST_EXIT_IF(hand != &x, "hand mismatch");
  TEST_FINI();
}

int main() {
  TEST_STRT(1);
  TEST_EXIT_IF(uthr_init(1024) < 0, "uthr_init");

  uthr_create(f, (void*)gettid());
  uthr_exit(&x);
}
