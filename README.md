# ESP32 Web LED Control

A project to control an LED connected to an ESP32 using a web application. This repository contains the necessary code and instructions to set up and run the project.

## Table of Contents

- [Introduction](#introduction)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Wiring](#wiring)
- [Usage](#usage)
- [Troubleshooting](#troubleshooting)

## Introduction

This project demonstrates how to control an LED using an ESP32 microcontroller and a web application. By accessing a web page hosted on the ESP32, you can toggle the state of the LED on and off.

## Prerequisites

Before you begin, make sure you have the following:

- An ESP32 development board
- A USB cable to connect the ESP32 to your computer
- An LED and a resistor (typically 220Ω)
- Jumper wires
- A breadboard (optional)
- Arduino IDE or PlatformIO installed on your computer

## Installation

1. **Clone this repository:**

   ```bash
   git clone https://github.com/yourusername/esp32-web-led-control.git
   cd esp32-web-led-control

2. **Open the project with your preferred development environment:**

   - If using the Arduino IDE, open the .ino file.
   - If using PlatformIO, open the project folder.

3. **Install the required libraries:**

   Make sure you have the WiFi and WebServer libraries installed. These are typically included with the ESP32 board support package.

4. **Replace the Wi-Fi Credentials:**

   Update the following lines in the code (`main.cpp` or equivalent) with your network credentials:

     - const char* ssid = "your_SSID";
     - const char* password = "your_PASSWORD";

## Wiring
Connect the LED to the ESP32 as follows:

1. **Connect the longer leg (anode) of the LED to GPIO 2 on the ESP32.**
2. **Connect the shorter leg (cathode) of the LED to one end of the resistor.**
3. **Connect the other end of the resistor to GND on the ESP32.**

## Usage
1. **Upload the code to your ESP32:**

   In the Arduino IDE, select the appropriate board and port, then click on the "Upload" button.
   In PlatformIO, use the "PlatformIO: Upload" command.

2. **Open the Serial Monitor:**

   In the Arduino IDE, click on the "Serial Monitor" button.

   
   In PlatformIO, use the "PlatformIO: Monitor" command.

4. **Check the IP address:**

   Once the ESP32 connects to the Wi-Fi network, it will display its IP address in the Serial Monitor.

5. **Access the web page:**

   Open a web browser and enter the IP address of the ESP32. You should see a web page with a button to toggle the LED.

6. **Toggle the LED:**

   Click the "Toggle LED" button to change the state of the LED.

## Troubleshooting
   1. **ESP32 Not Connecting to Wi-Fi:** Ensure the SSID and password are correct and that the Wi-Fi network is in range.
   2. **IP Address Not Displayed:** Make sure the ESP32 is properly connected and that the Serial Monitor baud rate matches the one set in the code (115200).
