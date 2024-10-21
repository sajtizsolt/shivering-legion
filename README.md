# Shivering Legion

Shivering Legion is a command line application written in C, which enables the Extreme Cooling feature of Lenovo Nerve Sense on some Lenovo laptops.

## Installation

### From source code

To install the application simply clone the source code and use `make`. Please note, that you will need root privileges to install, because the executable will be copied into your `/usr/bin` directory as well.

```
$ git clone https://github.com/sajtizsolt/shivering-legion
$ cd shivering-legion
$ sudo make all
```

### Uninstall

To uninstall the application, you can also use `make`. You will also need root privileges to remove the executable from `/usr/bin`. Thanks for giving it a try!

```
$ sudo make clean
$ cd ..
$ rm -rf shivering-legion
```

## Usage

To start using the application you should execute a simple command. You will need root privileges because the program will communicate with the embedded controller of your system.

```
$ sudo shivering-legion [help|info|start|stop]
```

## Acknowledgement

Despite of creating a tool like this was an original idea, during my research I've found a great Python application called [ExtremeCooling4Linux](https://gitlab.com/OdinTdh/extremecooling4linux) which already allows the feature. It's a nice desktop app created by Alberto Vicente, maybe it's the easier choice for most people.

## Compatibility

The application was tested on my Lenovo Legion Y530, but it should work on all Y520, Y720 and similar models as well. I appreciate every form of feedback!

This application will only work on Linux, on Windows please stick with Lenovo Nerve Sense.
