#include "file_util.h"
#include "embedded_controller.h"
#include "extreme_cooling.h"

int main(const int argc, const char* argv[]) {
  if (isExtremeCoolingSupported(SYSTEM_DMI_PATH_LINUX) != 0) {
    return -1;
  }

  if (getPermissionToAccessEmbeddedControllerRegisters() != 0) {
    return -1;
  }

  startExtremeCooling();

  return 0;
}
