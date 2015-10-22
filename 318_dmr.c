#include "types.h"
#include "stat.h"
#include "user.h"

#define TEST_NAME "318_dmr"
#include "318_test-tapish.h"

int main() {
 TEST_STRT(2);

 int f = fork();
 if (f < 0) {
   TEST_EXIT("Fork failed");
 } else if (f == 0) {
   int one = 1;
   desch(&one);
   TEST_FINI("child"); /* success 1 */
 } else {
   /* Allow the child time to deschedule itself */
   sleep(5);

   mkrun(f);

   wait();
   TEST_FINI("parent"); /* success 2 */
 }

 exit();
}
