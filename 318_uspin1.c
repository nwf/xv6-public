#include "types.h"
#include "stat.h"
#include "user.h"

#include "uthr.h"
#include "uthrdefs.h"

#define TEST_NAME "318_uspin1"
#include "318_test-tapish.h"

#define LOCK_TYPE struct uspin
#define LOCK_INIT(u) uspin_init(u)
#define LOCK_ACT(act, u) uspin_##act(u)

#include "318_usync1.i"
