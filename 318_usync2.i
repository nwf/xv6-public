int main() {
 /* Single-threaded test of locks deadlocking when acquired twice
  * when acquired twice by a single thread.
  */

 TEST_STRT(1);

 int f = fork();
 if (f < 0) {
   TEST_EXIT("Fork failed");
 } else if (f == 0) {
   LOCK_TYPE u;
   TEST_EXIT_IF(LOCK_INIT(&u) != 0, "Could not initialize spinlock");
   LOCK_ACT(acquire, &u);
   LOCK_ACT(acquire, &u);
   TEST_EXIT("Acquired successfully!  That's not right!");
 } else {
   TEST_DIAG("Waiting around for 'forever'...");

   sleep(10);
   kill(f);

   TEST_EXIT_IF(wait() != f, "wait() error");
   TEST_FINI();
 }

 exit();
 /* NOTREACHED */
 return 0;
}
