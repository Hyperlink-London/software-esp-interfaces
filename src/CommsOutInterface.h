#ifndef COMMS_OUT_INTERFACE_H
#define COMMS_OUT_INTERFACE_H

#include <Arduino.h>

// Abstract interface for comms output modules
class CommsOutInterface {
public:
    virtual void send(const String& sensorName, float value) = 0;
    virtual ~CommsOutInterface() = default;
};

#endif
