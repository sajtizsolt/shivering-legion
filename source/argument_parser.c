#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "argument_parser.h"
#include "file_util.h"

int isArgumentValid(const int argc, const char* argv[]) {
  if (argc != 2) {
    printf("Please only give one argument: help/info/start/stop\n");
    showHelp();
    return -1;
  }
  if (!(strcmp(argv[1], "help") == 0 || strcmp(argv[1], "info") == 0 || strcmp(argv[1], "start") == 0 || strcmp(argv[1], "stop") == 0)) {
    printf("Invalid argument! Accepted arguments: help/info/start/stop\n");
    return -2;
  }
  return 0;
}

int getCommand(const char* argument) {
  if (strcmp(argument, "help") == 0) {
    return HELP;
  } else if (strcmp(argument, "info") == 0) {
    return INFO;
  } else if (strcmp(argument, "start") == 0) {
    return START;
  } else if (strcmp(argument, "stop") == 0) {
    return STOP;
  } else {
    return -1;
  }
}

void showHelp(void) {
  printf("Usage:\n  sudo shivering-legion <command>\n\nCommands:\n  help  - show help\n  info  - show system info\n  start - start Extreme Cooling\n  stop  - stop Extreme Cooling\n");
}

void showSystemInfo(const char* dmiPath) {
  char* copiedPath = (char*) malloc(strlen(dmiPath));
  strcpy(copiedPath, dmiPath);
  strcat(copiedPath, "/bios_date");
  char* fileContent = getFileContent(copiedPath);
  printf("[BIOS]\n");
  printf("Date: %s", fileContent);
  strcpy(copiedPath, dmiPath);
  strcat(copiedPath, "/bios_release");
  fileContent = getFileContent(copiedPath);
  printf("Release: %s", fileContent);
  strcpy(copiedPath, dmiPath);
  strcat(copiedPath, "/bios_vendor");
  fileContent = getFileContent(copiedPath);
  printf("Vendor: %s", fileContent);
  strcpy(copiedPath, dmiPath);
  strcat(copiedPath, "/bios_version");
  fileContent = getFileContent(copiedPath);
  printf("Version: %s", fileContent);
  printf("[BOARD]\n");
  strcpy(copiedPath, dmiPath);
  strcat(copiedPath, "/board_name");
  fileContent = getFileContent(copiedPath);
  printf("Name: %s", fileContent);
  strcpy(copiedPath, dmiPath);
  strcat(copiedPath, "/board_vendor");
  fileContent = getFileContent(copiedPath);
  printf("Vendor: %s", fileContent);
  printf("[CHASSIS]\n");
  strcpy(copiedPath, dmiPath);
  strcat(copiedPath, "/chassis_type");
  fileContent = getFileContent(copiedPath);
  printf("Type: %s", fileContent);
  strcpy(copiedPath, dmiPath);
  strcat(copiedPath, "/chassis_vendor");
  fileContent = getFileContent(copiedPath);
  printf("Vendor: %s", fileContent);
  printf("[PRODUCT]\n");
  strcpy(copiedPath, dmiPath);
  strcat(copiedPath, "/product_name");
  fileContent = getFileContent(copiedPath);
  printf("Name: %s", fileContent);
  strcpy(copiedPath, dmiPath);
  strcat(copiedPath, "/product_version");
  fileContent = getFileContent(copiedPath);
  free(copiedPath);
  free(fileContent);
}
