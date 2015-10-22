#include "types.h"
#include "user.h"
#include "uthr.h"

#define TEST_NAME "318_tcj1"
#include "318_test-tapish.h"

int x;

void f(void *a) {
  TEST_EXIT_IF(a != &x, "f addr mismatch (%p != %p)", a, &x);
  TEST_DIAG("Inside thread: %p == %p", a, &x);
  uthr_exit(a+1);  // pass baton!
}

int main() {
  void *hand;

  TEST_STRT(1);
  TEST_EXIT_IF(uthr_init(1024) < 0, "thr_init");

  // This is so much nicer than the assembler!
  int ctid = uthr_create(f, &x);
  uthr_join(ctid, &hand);
  TEST_EXIT_IF(hand != ((void *)&x)+1, "baton pass");
  TEST_DIAG("baton pass ok: %p == %p", hand, ((void *)&x)+1);

  TEST_FINI();
  exit();
}
