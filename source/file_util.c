#include "file_util.h"

#include <stdio.h>
#include <stdlib.h>

const char * const SYSTEM_DMI_PATH_LINUX = "/sys/devices/virtual/dmi/id";

char* getFileContent(const char* filepath) {
  char* buffer = NULL;
  unsigned long length;
  FILE* file = fopen(filepath, "rb");
  if (file == NULL) {
    printf("Failed to open file: %s\n", filepath);
    exit(1);
  }
  fseek(file, 0, SEEK_END);
  length = (unsigned) ftell(file);
  fseek(file, 0, SEEK_SET);
  buffer = malloc(length);
  if (buffer == NULL) {
    printf("Failed to allocate memory before reading file: %s\n", filepath);
    exit(1);
  }
  fread(buffer, 1, length, file);
  fclose (file);
  if (buffer == NULL) {
    printf("Error occured during reading file: %s\n", filepath);
    exit(1);
  }
  return buffer;
}
