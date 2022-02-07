#ifndef EMBEDDED_CONTROLLER_H
#define EMBEDDED_CONTROLLER_H

extern const unsigned char EMBEDDED_CONTROLLER_DATA_REGISTER;
extern const unsigned char EMBEDDED_CONTROLLER_COMMAND_REGISTER;
extern const unsigned char EMBEDDED_CONTROLLER_READ_COMMAND;
extern const unsigned char EMBEDDED_CONTROLLER_WRITE_COMMAND;

extern const unsigned char INPUT_BUFFER_EMPTY;
extern const unsigned char INPUT_BUFFER_FULL;
extern const unsigned char OUTPUT_BUFFER_EMPTY;
extern const unsigned char OUTPUT_BUFFER_FULL;

int getPermissionToAccessPort(const unsigned char * const portAddress);
int getPermissionToAccessEmbeddedControllerRegisters(void);
int wait(const unsigned char * const portAddress, const unsigned char * const bufferFlag, const unsigned char value);
int readPortValue(const unsigned char * const portAddress);
void writePortValue(const unsigned char * const portAddress, const unsigned char * const value);

#endif /* EMBEDDED_CONTROLLER_H */
