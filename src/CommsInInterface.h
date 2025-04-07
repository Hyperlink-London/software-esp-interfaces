#ifndef COMMS_IN_INTERFACE_H
#define COMMS_IN_INTERFACE_H

#include <Arduino.h>

// Abstract interface for comms input modules
class CommsInInterface {
public:
    virtual void receive() = 0;
    virtual ~CommsInInterface() = default;
};

#endif 