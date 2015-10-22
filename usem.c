#include "types.h"
#include "user.h"

#include "uthr.h"

int usem_init(struct usem *u, uint c) {
    // If it never initializes, it's never safe to use.
    // "Minimal correct implementation"
	return -1;
}

void usem_acquire(struct usem *u) {

}

void usem_release(struct usem *u) {

}

void usem_destroy(struct usem *u) {

}
