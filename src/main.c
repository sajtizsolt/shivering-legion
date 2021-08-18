#include "argument_parser.h"
#include "file_util.h"
#include "embedded_controller.h"
#include "extreme_cooling.h"
#include <stdio.h>
int main(const int argc, const char* argv[]) {
  if (isArgumentValid(argc, argv) != 0) {
    return -1;
  }

  if (isExtremeCoolingSupported(SYSTEM_DMI_PATH_LINUX) != 0) {
    return -1;
  }

  if (getPermissionToAccessEmbeddedControllerRegisters() != 0) {
    return -1;
  }
  switch (getCommand(argv[1])) {
    case HELP:
      showHelp();
      break;
    case START:
      startExtremeCooling();
      break;
    case STOP:
      stopExtremeCooling();
      break;
    default:
      return -1;
      break;
  }

  return 0;
}
