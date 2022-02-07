#include "argument_parser.h"
#include "file_util.h"
#include "embedded_controller.h"
#include "extreme_cooling.h"

int main(const int argc, const char* argv[]) {
  if (isArgumentValid(argc, argv) != 0) {
    return -1;
  }

  const int command = getCommand(argv[1]);
  if (command == HELP) {
    showHelp();
    return 0;
  } else if (command == INFO) {
    showSystemInfo(SYSTEM_DMI_PATH_LINUX);
    return 0;
  }

  if (isExtremeCoolingSupported(SYSTEM_DMI_PATH_LINUX) != 0) {
    return -1;
  }

  if (getPermissionToAccessEmbeddedControllerRegisters() != 0) {
    return -1;
  }

  switch (command) {
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
