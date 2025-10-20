#ifndef SERIAL_ALIASES_H
#define SERIAL_ALIASES_H

#include <Arduino.h>

// Header-only aliases mapping to ESP32 Arduino serial instances
// Use macros to avoid multiple-definition/linker issues
#ifndef Serial_0
#define Serial_0 Serial1
#endif

#ifndef Serial_1
#define Serial_1 Serial
#endif

#endif


