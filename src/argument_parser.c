#include <stdio.h>
#include <string.h>

#include "argument_parser.h"

int isArgumentValid(const int argc, const char* argv[]) {
  if (argc != 2) {
    printf("Please only give one argument: help/start/stop\n");
    showHelp();
    return -1;
  }
  if (!(strcmp(argv[1], "help") == 0 || strcmp(argv[1], "start") == 0 || strcmp(argv[1], "stop") == 0)) {
    printf("Invalid argument! Accepted arguments: help/start/stop\n");
    return -2;
  }
  return 0;
}

int getCommand(const char* argument) {
  if (strcmp(argument, "help") == 0) {
    return HELP;
  } else if (strcmp(argument, "start") == 0) {
    return START;
  } else if (strcmp(argument, "stop") == 0) {
    return STOP;
  } else {
    return -1;
  }
}

void showHelp(void) {
  printf("Usage:\n  sudo shivering-legion <command>\n\nCommands:\n  help  - show help\n  start - start Extreme Cooling\n  stop  - stop Extreme Cooling\n");
}
