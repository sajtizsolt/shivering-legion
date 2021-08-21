VERSION=1
SUBVERSION=1

COMPILER=gcc
COMPILER_FLAGS=-Wall -Wextra -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wstrict-overflow=5 -Wwrite-strings -Waggregate-return -Wcast-qual -Wswitch-default -Wswitch-enum -Wconversion -Wunreachable-code

TARGET_EXECUTABLE=shivering-legion

SOURCE_FILES=src/main.c src/argument_parser.c src/file_util.c src/embedded_controller.c src/extreme_cooling.c

all:
	$(COMPILER) $(COMPILER_FLAGS) -o $(TARGET_EXECUTABLE) $(SOURCE_FILES)
	sudo cp $(TARGET_EXECUTABLE) /usr/bin/

clean:
	$(RM) $(TARGET_EXECUTABLE)
	sudo $(RM) /usr/bin/$(TARGET_EXECUTABLE)
