#ifndef ARGUMENT_PARSER_H
#define ARGUMENT_PARSER_H

enum Command {
  HELP,
  INFO,
  START,
  STOP
};

int isArgumentValid(const int argc, const char* argv[]);
int getCommand(const char* argument);
void showHelp(void);
void showSystemInfo(const char* dmiPath);

#endif /* ARGUMENT_PARSER_H */
