#include "types.h"
#include "user.h"
#include "uthr.h"
#include "uthrdefs.h"

#define TEST_NAME "318_tcj2"
#include "318_test-tapish.h"

#define SOME 15
#define DOCTR

int exp_hand[] =
  { 0, 2, 12, 28, 72, 128, 230, 350, 580, 840, 1246
  , 1694, 2394, 3154, 4220, 5364, 7056, 8856};
int exp_ctr [] =
  { 1, 3,  7, 11, 19,  27,  39,  51,  71,  91,  119
  ,  147,  187,  227,  279,  331,  403,  475};

int fails;
#ifdef DOCTR
int ctr;
#endif
struct uspin sl;

void f(void *_ix) {
  void *hand1 = _ix;
  void *hand2 = 0;

  int ix = (int)_ix;

#ifdef DOCTR
  uspin_acquire(&sl);
  // TEST_DIAG("Hello from thread %p", ix);
  ctr++;
  uspin_release(&sl);
#endif
  if(ix < SOME) {
    int ctid1 = uthr_create(f, (void *) (  ix+1));
    int ctid2 = uthr_create(f, (void *) (2*ix+1));
    if(ctid2 >= 0) {
      uthr_join(ctid2, &hand2);
      ix += (int) hand2;
    } else {
      uspin_acquire(&sl); fails++; uspin_release(&sl);
    }
    if(ctid1 >= 0) {
      uthr_join(ctid1, &hand1);
      ix += (int) hand1;
    } else {
      uspin_acquire(&sl); fails++; uspin_release(&sl);
    }
  }
  uthr_exit((void *)ix);
}

int main() {
  void *hand;

  TEST_STRT(1);
#ifdef DOCTR
  TEST_EXIT_IF(uspin_init(&sl) < 0, "spin init");
#endif
  TEST_EXIT_IF(uthr_init(1024) < 0, "uthr_init");

  int ctid = uthr_create(f, 0);
  uthr_join(ctid, &hand);
  TEST_DIAG("Main thread hand=%d fails=%d", hand, fails);
#ifdef DOCTR
  TEST_DIAG("Main thread ctr=%d", ctr);
  TEST_EXIT_IF(ctr != exp_ctr [SOME],
    "Ctr expectation mismatch: %d != %d", ctr, exp_ctr[SOME]);
#endif
  TEST_EXIT_IF((int)hand != exp_hand[SOME],
    "Hand expectation mismatch: %d != %d", hand, exp_hand[SOME]);

  TEST_FINI();
  exit();
}
