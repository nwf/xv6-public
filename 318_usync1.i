int main() {
 /* Single-threaded test of spinlocks, just to make sure the pieces compile
  * and work at least in the no-contention case!
  */

 LOCK_TYPE u;

 TEST_STRT(1);
 TEST_EXIT_IF(LOCK_INIT(&u) != 0, "Could not initialize spinlock");
 TEST_DIAG("Lock initialized...");

 LOCK_ACT(acquire, &u);
 TEST_DIAG("Lock acquired...");

 LOCK_ACT(release, &u);
 TEST_DIAG("Lock released...");

 LOCK_ACT(acquire, &u);
 TEST_DIAG("Lock acquired 2nd time...");

 LOCK_ACT(release, &u);
 TEST_DIAG("Spinlock released 2nd time...");

 LOCK_ACT(destroy, &u);
 TEST_DIAG("Spinlock destroyed...");

 TEST_FINI();

 exit();
 /* NOTREACHED */
 return 0;
}
