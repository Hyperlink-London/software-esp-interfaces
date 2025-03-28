# Interfaces Library

This repository contains the `interfaces` module used in the Hyperlink Firmware systems. It provides abstract interface definitions that decouple major system components such as sensor logic and communication backends.

This library does not contain any implementation logic. Its sole purpose is to define reusable, minimal interfaces that can be used across multiple modules to ensure consistency, promote modular design, and avoid circular dependencies.

## Repository Structure

```
interfaces/
├── src/
│   ├── CommsOutInterface.h
│   └── SensorInterface.h
├── library.properties
└── README.md
```

- `CommsOutInterface.h`: Defines the interface used for outbound communication modules (e.g., `CommsOut`).
- `SensorInterface.h`: Defines the interface used by sensor drivers managed by `SensorManager`.
- `library.properties`: Metadata for Arduino CLI and IDE compatibility.

---

## Purpose

This library exists to define shared contracts (interfaces) used between the `sensors`, `comms`, and other system modules. By placing these abstract definitions in a separate submodule, the system architecture remains modular and avoids tight coupling between concrete implementations.

---

## Defined Interfaces

### CommsOutInterface

Used by components like `SensorManager` to send data outward without depending on a specific communication implementation.

```cpp
class CommsOutInterface {
public:
    virtual void send(const String& sensorName, float value) = 0;
    virtual ~CommsOutInterface() = default;
};
```

Implemented by communication modules such as `CommsOut`.

---

### SensorInterface

Used by `SensorManager` to manage and interact with sensors in a uniform way, regardless of their implementation.

```cpp
class SensorInterface {
public:
    virtual void setup() = 0;
    virtual void update() = 0;
    virtual float getVal() = 0;
    virtual String getName() = 0;
    virtual ~SensorInterface() = default;
};
```

Implemented by all individual sensor drivers.

---

## Usage Notes

- This library should be included by any module that needs to define or use shared interface contracts.
- Do not add any implementation logic or hardware-specific code in this library.
- All components using these interfaces should rely only on the method signatures provided here.

---

## Development Notes

- Keep all interfaces minimal, abstract, and free of dependencies.
- All files should be located in the `src/` directory to remain compatible with Arduino CLI and IDEs.
- This library should be listed before others (e.g., `sensors`, `comms`) in build scripts to ensure availability during compilation.

