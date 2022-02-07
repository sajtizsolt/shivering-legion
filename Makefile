VERSION=1
SUBVERSION=2

COMPILER=gcc
COMPILER_FLAGS=-Wall -Wextra -Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wstrict-overflow=5 -Wwrite-strings -Waggregate-return -Wcast-qual -Wswitch-default -Wswitch-enum -Wconversion -Wunreachable-code

TARGET_EXECUTABLE=shivering-legion

SOURCE_FILES=source/main.c source/argument_parser.c source/file_util.c source/embedded_controller.c source/extreme_cooling.c

all:
	compile
	install

clean:
	$(RM) $(TARGET_EXECUTABLE)
	sudo $(RM) $(DESTDIR)/usr/bin/$(TARGET_EXECUTABLE)

compile:
	$(COMPILER) $(COMPILER_FLAGS) -o $(TARGET_EXECUTABLE) $(SOURCE_FILES)

install:
	sudo cp $(TARGET_EXECUTABLE) $(DESTDIR)/usr/bin/
