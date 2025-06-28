# Flammable Gas Detection with Blynk IoT

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Circuit Diagram](#circuit-diagram)
- [Setup and Installation](#setup-and-installation)
  - [Hardware Connections](#hardware-connections)
  - [Blynk Setup](#blynk-setup)
  - [Arduino IDE Setup](#arduino-ide-setup)
- [How it Works](#how-it-works)
- [Troubleshooting](#troubleshooting)
- [Future Enhancements](#future-enhancements)
- [Contributing](#contributing)

## Overview

This project demonstrates a real-time flammable gas detection system utilizing an ESP8266 Wi-Fi module, a MQ-2 gas sensor, and the Blynk IoT platform. The system is designed to continuously monitor for the presence of combustible gases (like LPG, propane, methane, hydrogen, etc.) and alert users through the Blynk mobile application when gas levels exceed a predefined threshold. This makes it an ideal solution for enhancing safety in homes, industrial environments, or any location where gas leaks could pose a risk.

## Features

* **Real-time Gas Monitoring:** Continuously monitors gas concentration using the MQ-2 sensor.
* **Blynk Integration:** Seamlessly integrates with the Blynk IoT platform for remote monitoring and notifications.
* **Threshold Alerts:** Triggers alerts on the Blynk app when gas levels surpass a safe limit.
* **Visual Indication:** (If applicable, based on hardware. If there's an LED or buzzer) Provides visual/audible alerts on the device itself.
* **Cost-Effective:** Built with readily available and affordable components.
* **Easy to Deploy:** Simple setup process for quick deployment.

## Hardware Requirements

To build this project, you will need the following components:

* **ESP8266 NodeMCU (or similar ESP8266 development board):** 1 unit
* **MQ-2 Gas Sensor Module:** 1 unit
* **Buzzer (Optional, for audible alerts):** 1 unit
* **Jumper Wires:** M-M, M-F
* **Breadboard:** 1 unit
* **Micro USB Cable:** For programming the ESP8266

## Software Requirements

* **Arduino IDE:** For programming the ESP8266.
* **Blynk Application:** Installed on your smartphone (Android/iOS).
* **Libraries for Arduino IDE:**
    * `ESP8266WiFi.h` (comes with ESP8266 board package)
    * `BlynkSimpleEsp8266.h`

## Circuit Diagram

The following diagram illustrates the connections between the ESP8266 NodeMCU and the MQ-2 gas sensor.

<p align="center">
  <img src="https://github.com/AwkJay/Flammable-Gas-Detection-with-Blynk-IoT/blob/main/Images/Circuit%20Diagram.jpeg?raw=true" alt="Circuit Diagram" width="600"/>
</p>

**Pin Connections:**

| Component       | ESP8266 Pin |
| :-------------- | :---------- |
| MQ-2 VCC        | VIN (5V)    |
| MQ-2 GND        | GND         |
| MQ-2 A0 (Analog)| A0          |
| Buzzer (Optional)| D2 (GPIO 4) |

*Note: The MQ-2 sensor requires 5V, so connect its VCC to the VIN pin of the NodeMCU which provides 5V. The analog output of the MQ-2 should be connected to the A0 pin of the NodeMCU.*

## Setup and Installation

Follow these steps to get your Flammable Gas Detection system up and running:

### Hardware Connections

1.  Connect the **VCC** pin of the MQ-2 sensor to the **VIN** (5V) pin of the NodeMCU.
2.  Connect the **GND** pin of the MQ-2 sensor to any **GND** pin of the NodeMCU.
3.  Connect the **A0** (analog output) pin of the MQ-2 sensor to the **A0** pin of the NodeMCU.
4.  *(Optional)* If using a buzzer, connect its positive terminal to a digital pin (e.g., D2/GPIO 4) and its negative terminal to GND.

### Blynk Setup

1.  **Download and Install Blynk:** Download the Blynk app from the Google Play Store or Apple App Store.
2.  **Create New Project:**
    * Open the Blynk app and create a new account or log in.
    * Tap on "New Project".
    * Give your project a name (e.g., "Gas Detector").
    * Select "NodeMCU" as the device.
    * Choose "Wi-Fi" as the connection type.
    * An **Auth Token** will be sent to your registered email address. Keep this token safe, you'll need it for the Arduino code.
3.  **Add Widgets:**
    * Tap anywhere on the canvas to open the Widget Box.
    * Add a **Gauge** widget and set its input pin to `Analog A0`. Configure the range (e.g., 0-1023, or a calibrated range based on gas concentration).
    * Add a **Notification** widget to receive alerts.
    * Add a **LED** widget (optional) to visually represent the alarm state, linked to a digital pin (e.g., V1).
    * Add a **History Graph** widget (optional) to view gas level trends over time.

### Arduino IDE Setup

1.  **Install ESP8266 Board Manager:**
    * Open Arduino IDE.
    * Go to `File > Preferences`.
    * In "Additional Boards Manager URLs", add: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
    * Go to `Tools > Board > Boards Manager...`. Search for "esp8266" and install the "esp8266 by ESP8266 Community" package.
2.  **Install Blynk Library:**
    * Go to `Sketch > Include Library > Manage Libraries...`.
    * Search for "Blynk" and install the "Blynk by Volodymyr Shymanskyy" library.
3.  **Open the Sketch:**
    * Download the `Flammable_Gas_Detector.ino` file from this repository.
    * Open it in Arduino IDE.
4.  **Configure Credentials:**
    * Replace `YourAuthToken`, `YourWiFiSSID`, and `YourWiFiPassword` with your actual Blynk Auth Token, Wi-Fi network SSID, and password respectively.

    ```cpp
    char auth[] = "YourAuthToken";
    char ssid[] = "YourWiFiSSID";
    char pass[] = "YourWiFiPassword";
    ```
5.  **Upload Code:**
    * Select your board: `Tools > Board > NodeMCU 1.0 (ESP-12E Module)`.
    * Select the correct COM Port: `Tools > Port`.
    * Click the "Upload" button.

## How it Works

The system operates as follows:

1.  The MQ-2 gas sensor continuously reads the concentration of flammable gases in the air.
2.  The analog output from the MQ-2 sensor is read by the ESP8266's analog input pin (A0).
3.  The ESP8266 processes this analog reading.
4.  If the gas concentration exceeds a predefined threshold (calibrated in the code), the ESP8266 sends a signal to the Blynk server.
5.  Blynk, in turn, triggers notifications on your smartphone, updates the gauge widget, and activates any other configured widgets (e.g., LED, buzzer connected to the ESP8266).
6.  The system constantly monitors, providing real-time updates and alerts.

## Troubleshooting

* **"Auth Token is Invalid" or "Could not connect to Blynk":** Double-check your `auth` token, Wi-Fi SSID, and password in the Arduino code. Ensure your ESP8266 is within range of your Wi-Fi router.
* **No readings on Blynk:** Verify the MQ-2 sensor connections (VCC, GND, A0). Ensure the sensor is powered correctly.
* **False alarms:** Calibrate the gas threshold in your Arduino code. MQ-2 sensors can sometimes give fluctuating readings. Consider adding a small delay or averaging multiple readings.
* **ESP8266 not uploading:** Make sure you have the correct board and COM port selected in the Arduino IDE. Try holding the "Flash" or "BOOT" button on the NodeMCU while uploading.

## Future Enhancements

* **SMS/Email Notifications:** Integrate with services like IFTTT for more robust notification options.
* **Data Logging:** Store gas concentration data on a cloud platform (e.g., Google Sheets, Adafruit IO) for historical analysis.
* **Multiple Sensors:** Expand the system to include multiple gas sensors for broader coverage.
* **Automated Action:** Integrate with relays to control external devices like exhaust fans or shut-off valves in case of a gas leak.
* **LCD Display:** Add a small LCD to display real-time gas levels locally.
* **Battery Power:** Optimize for low power consumption to allow for battery-powered deployment.

## Contributing

Contributions are welcome! If you have any improvements, bug fixes, or new features, please feel free to open an issue or submit a pull request.

1.  Fork the repository.
2.  Create a new branch (`git checkout -b feature/AmazingFeature`).
3.  Make your changes.
4.  Commit your changes (`git commit -m 'Add some AmazingFeature'`).
5.  Push to the branch (`git push origin feature/AmazingFeature`).
6.  Open a Pull Request.
