/* Multi-threaded test of basic synchronization functionality */

#define DEBUG 1
#define N 20
  /* printf() really loves its stack space; empirically, 256 might be
   * enough, but only barely, and I'd rather you have some room to
   * spare. :) */
#define STKSIZE 384
#define BAILOUT (*(int *)0x10000) = 3;

LOCK_TYPE u;

void
spawnee(void *_a) {
  LOCK_TYPE *a = _a;
  LOCK_ACT(acquire, a);
  TEST_DIAG_IF(DEBUG, "thread %d arg @ %p", gettid(), &a);
  TEST_FINI();
  LOCK_ACT(release, a);
  texit();
  BAILOUT;
}

char stacks[N][STKSIZE];

int main() {
  int i;
  void *s;
  int tid;

  TEST_STRT(1+N);
  TEST_EXIT_IF(LOCK_INIT(&u) != 0, "Could not initialize spinlock");
  LOCK_ACT(acquire, &u);
  for(i = 0; i < N; i++) {
    s = &stacks[i][0];
    s += STKSIZE;

    TEST_EXIT_IF((tid = tspawn(s, spawnee, &u)) < 0, "spawn");
    TEST_DIAG_IF(DEBUG, "spawned tid %d with stack %p", tid, s);
  }
  TEST_DIAG("thunderbirds are go");
  TEST_FINI();
  LOCK_ACT(release, &u);

  texit();
  BAILOUT;
}
