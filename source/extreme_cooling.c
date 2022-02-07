#include "extreme_cooling.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_util.h"
#include "embedded_controller.h"

const unsigned char EXTREME_COOLING_REGISTER = 0xBD;
const unsigned char EXTREME_COOLING_ACTIVE = 0x40;
const unsigned char EXTREME_COOLING_INACTIVE = 0x00;

int isExtremeCoolingSupported(const char* dmiPath) {
  char* copiedPath = (char*) malloc(strlen(dmiPath));
  strcpy(copiedPath, dmiPath);
  strcat(copiedPath, "/sys_vendor");
  char* fileContent = getFileContent(copiedPath);
  fileContent[strcspn(fileContent, "\n")] = 0;
  if (strcmp(fileContent, "LENOVO") != 0) {
    printf("Extreme Cooling is only supported by LENOVO laptops. The etected manufacturer is %s.\n", fileContent);
    return -1;
  }
  strcpy(copiedPath, dmiPath);
  strcat(copiedPath, "/chassis_type");
  fileContent = getFileContent(copiedPath);
  fileContent[strcspn(fileContent, "\n")] = 0;
  const int chassisType = atoi(fileContent);
  if (!(chassisType == 9 || chassisType == 10 || chassisType == 14)) {
    printf("Extreme Cooling is only supported by LENOVO laptops with chassis type 9, 10 or 14. The detected chassis type is %d.\n", chassisType);
    return -1;
  }
  // TODO: Check if the register contains sufficient values
  printf("Extreme Cooling support detected.\n");
  free(copiedPath);
  free(fileContent);
  return 0;
}

int getExtremeCoolingStatus(void) {
  const int portValue = readPortValue(&EXTREME_COOLING_REGISTER);
  if (portValue == EXTREME_COOLING_ACTIVE) {
    printf("Extreme Cooling is active.\n");
    return 1;
  } else if (portValue == EXTREME_COOLING_INACTIVE) {
    printf("Extreme Cooling is inactive.\n");
    return 0;
  } else {
    printf("Error while detecting Extreme Cooling status. Unexpected value in register: %d\n", portValue);
    return -1;
  }
}

void startExtremeCooling(void) {
  if (getExtremeCoolingStatus() == 1) {
    printf("Extreme Cooling is already active.\n");
    return;
  }
  writePortValue(&EXTREME_COOLING_REGISTER, &EXTREME_COOLING_ACTIVE);
  printf("Extreme Cooling successfully activated.\n");
}

void stopExtremeCooling(void) {
  if (getExtremeCoolingStatus() != 1) {
    printf("Extreme Cooling is inactive.\n");
    return;
  }
  writePortValue(&EXTREME_COOLING_REGISTER, &EXTREME_COOLING_INACTIVE);
  printf("Extreme Cooling successfully inactivated.\n");
}
