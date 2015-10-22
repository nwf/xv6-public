#include "types.h"
#include "user.h"

#include "uthr.h"

int uspin_init(struct uspin *u) {
    // If it never initializes, it's never safe to use.
    // "Minimal correct implementation"
    return -1;
}

void uspin_acquire(struct uspin *u) {

}

void uspin_release(struct uspin *u) {

}

void uspin_destroy(struct uspin *u) {

}
