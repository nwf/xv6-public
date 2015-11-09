#include "types.h"
#include "user.h"
#include "uthr.h"

#define TEST_NAME "318_tc1"
#include "318_test-tapish.h"

int x;

void f(void *a) {
  TEST_EXIT_IF(a != &x, "f addr mismatch (%p != %p)", a, &x);
  TEST_DIAG("Inside thread! (%p == %p)", a, &x);
  TEST_FINI();
  exit();
}

int main() {
  TEST_STRT(1);

  TEST_EXIT_IF(uthr_init(1024) < 0, "uthr_init");

  // This is so much nicer than the assembler!
  // Note that we ignore the tid for this simple test...
  uthr_create(f, &x);

  while(1) { yield(-1); }

  // NOTREACHED
  return 0;
}
