#include "types.h"
#include "stat.h"
#include "user.h"

#include "uthr.h"
#include "uthrdefs.h"

#define TEST_NAME "318_usem3"
#include "318_test-tapish.h"

#define LOCK_TYPE struct usem
#define LOCK_INIT(u) usem_init(u, 1)
#define LOCK_ACT(act, u) usem_##act(u)

#include "318_usync3.i"
