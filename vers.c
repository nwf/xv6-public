#include "types.h"
#include "defs.h"
#include "vers.h"

void
announce_startup(void)
{
  cprintf("The better part of valor is discretion,\n");
  cprintf("in the which better part I have sav'd my life\n");
  cprintf("  -- Henry IV, Part 1, Act 5, Scene 4\n");

  cprintf("xv6 build " XV6_BUILD_STRING " initialized...\n");
}
