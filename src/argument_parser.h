#ifndef ARGUMENT_PARSER_H
#define ARGUMENT_PARSER_H

enum Command {
  HELP,
  START,
  STOP
};

int isArgumentValid(const int argc, const char* argv[]);
int getCommand(const char* argument);
void showHelp(void);

#endif /* ARGUMENT_PARSER_H */
