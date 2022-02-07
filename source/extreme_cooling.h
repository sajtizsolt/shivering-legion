#ifndef EXTREME_COOLING_H
#define EXTREME_COOLING_H

extern const unsigned char EXTREME_COOLING_REGISTER;
extern const unsigned char EXTREME_COOLING_ACTIVE;
extern const unsigned char EXTREME_COOLING_INACTIVE;

int isExtremeCoolingSupported(const char* dmiPath);
int getExtremeCoolingStatus(void);
void startExtremeCooling(void);
void stopExtremeCooling(void);

#endif /* EXTREME_COOLING_H */
