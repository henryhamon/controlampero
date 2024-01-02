# ControlAmpero

**Unleash your AMPERO II STOMP's sonic power with this MIDI foot controller**

This project builds a powerful MIDI Foot Controller specifically designed for controlling the AMPERO II STOMP multi-effects pedal with your feet. Ditch the menus and unlock effortless sound exploration with intuitive controls and real-time customization.

## Key Features:

* 128 banks: Access a vast library of 4-preset banks at a tap. No more bending down!
* 8 stomp switches: Control dedicated A1-A4 and B1-B4 STOMPS for instant layering and tweaking.
* 8 OLED displays: See patch names, effect details, and parameter values clearly on stage.
* Arduino-powered: Open-source code for customization and endless possibilities.

## Required Hardware:

* Arduino Mega
* 10 Foot switches
* 8 OLED displays
Additional components (resistors, capacitors, wires)

## Getting Started:

* Clone or download the project files.
* Install the required Arduino libraries (listed in the code comments).
* Connect your hardware according to the schematics provided (included in the project files).
* Upload the Arduino code to your board.
* Start exploring your sonic potential!
* Have fun
  
## Customization:

The Arduino code is fully customizable. You can:

* Modify button assignments to control different STOMPS.
* Adjust OLED display layouts for personalized information.
* Add additional features and functionality based on your needs.

## Community and Support:

Join the project forum or online community to share your experiences, discuss modifications, and get help with any challenges.

**This MIDI Foot Controller is your key to unlocking the full potential of your AMPERO II STOMP, live and on the go. Unleash your inner sonic explorer!**

## Electronics Description:

At the heart of this MIDI Foot Controller lies an Arduino Mega 2560 microcontroller, expertly orchestrating communication between various components. 
It seamlessly handles user input from 10 foot switches, drives the informative OLED displays, and precisely dispatches MIDI messages to the AMPERO II STOMP, ensuring flawless control over your sonic landscapes. 
While currently utilizing the Arduino Mega, future iterations may explore the ESP8266's expanded capabilities, unlocking even greater potential for wireless connectivity and expanded features.

Components:

- Arduino Mega 2560: Processes user input from foot switches and controls the OLED displays and Bluetooth communication.
- Foot switches: 10 momentary switches for selecting presets, activating STOMPS, and other functions.
- OLED displays: 8 individual displays (compatible with SSD1306 library) showcase patch names, effect details, and parameter values.
- Additional components: Resistors, capacitors, and wires provide electrical connections between all components.

**Schematics and wiring diagrams are included in the project files for detailed assembly instructions.**

This detailed description provides electronics enthusiasts with a clear understanding of the hardware components and their roles within the project.
