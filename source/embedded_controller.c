#include "embedded_controller.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/io.h>
#include <unistd.h>

const unsigned char EMBEDDED_CONTROLLER_DATA_REGISTER = 0x62;
const unsigned char EMBEDDED_CONTROLLER_COMMAND_REGISTER = 0x66;
const unsigned char EMBEDDED_CONTROLLER_READ_COMMAND = 0x80;
const unsigned char EMBEDDED_CONTROLLER_WRITE_COMMAND = 0x81;

const unsigned char INPUT_BUFFER_EMPTY = 0;
const unsigned char INPUT_BUFFER_FULL = 1;
const unsigned char OUTPUT_BUFFER_EMPTY = 0;
const unsigned char OUTPUT_BUFFER_FULL = 1;

int getPermissionToAccessPort(const unsigned char * const portAddress) {
  switch (ioperm(*portAddress, 1, 1)) {
    case 0:
      printf("Successfully gained permission to access %hhu port.\n", *portAddress);
      return 0;
    case EINVAL:
      printf("Error while requesting permission to access %hhu port: Invalid values for from or num.\n", *portAddress);
      break;
    case EIO:
      printf("Error while requesting permission to access %hhu port: This call is not supported.\n", *portAddress);
      break;
    case ENOMEM:
      printf("Error while requesting permission to access %hhu port: Out of memory.\n", *portAddress);
      break;
    case EPERM:
      printf("Error while requesting permission to access %hhu port: The calling thread has insufficient privilege.\n", *portAddress);
      break;
    default:
      printf("Unknown error while requesting permission to access %hhu port.\nThe software needs root permission to access ports.\n", *portAddress);
      break;
  }
  return -1;
}

int getPermissionToAccessEmbeddedControllerRegisters(void) {
  if (getPermissionToAccessPort(&EMBEDDED_CONTROLLER_DATA_REGISTER) != 0) {
    return -1;
  }
  if (getPermissionToAccessPort(&EMBEDDED_CONTROLLER_COMMAND_REGISTER) != 0) {
    return -1;
  }
  return 0;
}

int wait(const unsigned char * const portAddress, const unsigned char * const bufferFlag, const unsigned char value) {
  const unsigned short SLEEP_MILLISECONDS = 1;
  unsigned int counter = 0;
  while(1) {
    if (((inb(*portAddress) >> *bufferFlag) & 0x1) == value) {
      break;
    }
    usleep(SLEEP_MILLISECONDS);
    ++counter;
    if (counter > 2500) {
      printf("Error! Suspending process is taking suspiciously long.\n");
      return -1;
    }
  }
  printf("Process suspended for %d milliseconds.\n", SLEEP_MILLISECONDS * counter);
  return 0;
}

int readPortValue(const unsigned char * const portAddress) {
  if (wait(&EMBEDDED_CONTROLLER_COMMAND_REGISTER, &INPUT_BUFFER_FULL, 0) != 0) {
    exit(2);
  }
  outb(EMBEDDED_CONTROLLER_READ_COMMAND, EMBEDDED_CONTROLLER_COMMAND_REGISTER);
  if (wait(&EMBEDDED_CONTROLLER_COMMAND_REGISTER, &INPUT_BUFFER_FULL, 0) != 0) {
    exit(2);
  }
  outb(*portAddress, EMBEDDED_CONTROLLER_DATA_REGISTER);
  if (wait(&EMBEDDED_CONTROLLER_COMMAND_REGISTER, &OUTPUT_BUFFER_EMPTY, 1) != 0) {
    exit(2);
  }
  return inb(EMBEDDED_CONTROLLER_DATA_REGISTER);
}

void writePortValue(const unsigned char * const portAddress, const unsigned char * const value) {
  if (wait(&EMBEDDED_CONTROLLER_COMMAND_REGISTER, &INPUT_BUFFER_FULL, 0) != 0) {
    exit(2);
  }
  outb(EMBEDDED_CONTROLLER_WRITE_COMMAND, EMBEDDED_CONTROLLER_COMMAND_REGISTER);
  if (wait(&EMBEDDED_CONTROLLER_COMMAND_REGISTER, &INPUT_BUFFER_FULL, 0) != 0) {
    exit(2);
  }
  outb(*portAddress, EMBEDDED_CONTROLLER_DATA_REGISTER);
  if (wait(&EMBEDDED_CONTROLLER_COMMAND_REGISTER, &INPUT_BUFFER_FULL, 0) != 0) {
    exit(2);
  }
  outb(*value, EMBEDDED_CONTROLLER_DATA_REGISTER);
  if (wait(&EMBEDDED_CONTROLLER_COMMAND_REGISTER, &INPUT_BUFFER_FULL, 0) != 0) {
    exit(2);
  }
}
