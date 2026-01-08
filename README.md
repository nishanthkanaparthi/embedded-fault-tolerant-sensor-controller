# Embedded Fault-Tolerant Sensor Controller

A small C project that simulates an embedded sensor controller using a finite state machine (FSM). The controller reads sensor values, classifies them into different safety states (OK, WARNING, ERROR, RESET), and prints the current state to the console.

This project is written as a PC simulation, but the same logic could be ported to a microcontroller.

---

## Features

- Finite State Machine (FSM) with four states:
  - **OK** – sensor reading is in a safe range  
  - **WARNING** – sensor is high but still acceptable  
  - **ERROR** – sensor is above the error threshold  
  - **RESET** – recovering after an error before going back to OK
- Configurable warning and error thresholds
- Counts how many times an error has occurred
- Simple, well-commented C code focused on readability

---

## Project Structure

```text
sensor-controller/
│
├── src/
│   ├── sensor_controller.c   # FSM implementation
│   ├── sensor_controller.h   # Public functions & type definitions
│   └── main.c                # Example / test program
│
└── README.md
