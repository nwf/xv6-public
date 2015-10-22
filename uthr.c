#include "types.h"
#include "user.h"

#include "uthr.h"

int
uthr_init(uint ss) {
    return -1;
}

int
uthr_create(void (*f)(void *), void *arg) {
    return -1;
}

void
uthr_exit(void *baton) {
    texit();
}

int
uthr_join(int tid, void **hand) {
    return -1;
}

void *
uthr_malloc(int sz) {
    return malloc(sz);
}

void
uthr_free(void *p) {
    free(p);
}
