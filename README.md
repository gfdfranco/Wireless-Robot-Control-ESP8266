# Wireless-Robot-Control-ESP8266
Control a robot wirelessly using an ESP8266 module with a web-based interface. Features directional controls and stop functionality accessible via any WiFi-enabled device.

This project demonstrates how to control a robot wirelessly using an ESP8266 module. The robot can be controlled through a web interface with buttons for movements including forward, reverse, left, right, and stop.

## Features

- Web-based control panel with large buttons for easy interaction.
- ESP8266 acts as an access point allowing direct connection without needing an external WiFi network.
- Real-time command execution and feedback through the serial monitor.

## Prerequisites

Before starting, ensure you have the following:
- NodeMCU ESP8266 module
- Arduino IDE installed
- Basic understanding of electronics and programming microcontrollers

## Setup

### Hardware Setup

Refer to the wiring and setup guide on [Techatronic](https://techatronic.com/wifi-controlled-robot-nodemcu-esp8266/#google_vignette) for details on connecting the motors and configuring the ESP8266 hardware.

### Software Setup

1. **Install Arduino IDE**: Follow the instructions on [Instructables](https://www.instructables.com/Steps-to-Setup-Arduino-IDE-for-NODEMCU-ESP8266-WiF/) to setup your Arduino IDE for NodeMCU.
2. **Library Installation**:
   - Use the ESP8266WiFi library included with the ESP8266 board manager in the Arduino IDE.
   - Additional details on the library can be found at [GitHub - ESP8266wifi](https://github.com/ekstrand/ESP8266wifi).

## Usage

1. Connect your device (e.g., smartphone or computer) to the "ESP8266_Robot" WiFi network using the password "password123".
2. Open a web browser and navigate to `http://192.168.4.1`.
3. Use the on-screen buttons to control the robot.

## Code Overview

The `ESP8266_Robot.ino` file contains all the necessary code to setup and run the ESP8266 as a WiFi access point and to handle web requests to control the robot.

### Main Components:

- **Web Server Setup**: `setup()` function configures the WiFi and server settings.
- **Command Handling**: `handleCommand()` function processes commands received from the web interface.
- **Web Interface**: HTML and CSS are used to create a user-friendly interface with buttons for controlling the robot.

## Contributing

Feel free to fork this project and contribute your improvements. Any contributions you make are **greatly appreciated**.

## License

Distributed under the MIT License. See `LICENSE` for more information.

## Acknowledgements

- [Techatronic](https://techatronic.com)
- [Instructables NodeMCU Setup Guide](https://www.instructables.com/Steps-to-Setup-Arduino-IDE-for-NODEMCU-ESP8266-WiF/)
- [ESP8266 WiFi Library](https://github.com/ekstrand/ESP8266wifi)
