# EMBEDDED-ALARM
![image](https://github.com/user-attachments/assets/9e778ed8-dbaf-4749-a1fd-7cf0959fa752)
# Embedded Clock with Alarm - MPLAB XC8 + Proteus 8

## Overview
This project is an embedded system implementation of a real-time clock with an alarm feature using a PIC microcontroller. The firmware is developed using MPLAB XC8, and the system is simulated in Proteus 8. The clock is displayed on a 16x2 LCD, and users can set the time and alarm using push buttons.

## Features
- Real-time clock functionality (hours, minutes, seconds)
- Configurable alarm with user-defined time
- LCD display for real-time monitoring of time and alarm status
- Push buttons for time and alarm adjustment
- LED indicator for alarm activation
- Interrupt-driven timing using Timer0

## Hardware Requirements
- PIC Microcontroller (e.g., PIC16F877A)
- 16x2 LCD display
- Push buttons (for setting time and alarm)
- LED (to indicate alarm activation)
- Resistors, Capacitors, and Crystal oscillator (4MHz)
- Proteus 8 (for simulation)

## Software Requirements
- MPLAB X IDE
- XC8 Compiler
- Proteus 8 for simulation

## Circuit Connections
### LCD (4-bit Mode)
| LCD Pin | Microcontroller Pin |
|---------|---------------------|
| RS      | RC0                 |
| EN      | RC2                 |
| D4      | RD4                 |
| D5      | RD5                 |
| D6      | RD6                 |
| D7      | RD7                 |

### Push Buttons
| Button | Function | Pin |
|--------|----------|-----|
| RB0    | Increase time/alarm value | RB0 |
| RB1    | Decrease time/alarm value | RB1 |
| RB2    | Toggle alarm on/off | RB2 |
| RB3    | Switch between fields | RB3 |

### LED Indicator
| LED | Function | Pin |
|-----|----------|-----|
| RD0 | Alarm activation | RD0 |

## Code Explanation
- **Timer0 Interrupt:** Handles the real-time clock update every second.
- **LCD Functions:** Display the time and alarm on the 16x2 LCD using 4-bit communication.
- **Button Handling:** Allows users to set the clock and alarm through button presses.
- **Alarm Check:** Compares the real-time clock with the set alarm time and toggles the LED when activated.

## How to Use
1. Load the code into MPLAB X and compile it using XC8.
2. Simulate the circuit in Proteus 8.
3. Adjust the time and alarm using the push buttons.
4. Observe the real-time clock updating on the LCD.
5. When the alarm time is reached, the LED will toggle to indicate activation.

## Future Enhancements
- Adding a buzzer for alarm notification
- EEPROM storage for time and alarm settings
- Real-time clock module (RTC) integration for improved accuracy

## License
This project is open-source and available for modification and improvement.

