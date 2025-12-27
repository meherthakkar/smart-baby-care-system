## 🛒 Bill of Materials
| Component | Quantity | Purpose |
| :--- | :--- | :--- |
| ESP32 Development Board | 1 | Brain of the system |
| Analog Sound Sensor | 1 | Detects baby crying |
| Soil Moisture Sensor | 1 | Detects bed wetness |
| SG90 Servo Motor | 1 | Moves the cradle |
| Jumper Wires | 10+ | Circuit connections |# Smart Baby Care System 👶

This project is an ESP32-based automated system designed to monitor and care for a baby. It detects crying and bed-wetting to provide immediate care and alerts.

## 🚀 Features
* **Automatic Cradle Swing:** When the sound sensor detects a cry (threshold > 2500), the servo motor swings the cradle for 8 seconds.
* **Moisture Detection:** Monitors bed conditions using a moisture sensor to identify if the baby needs a diaper change.
* **Offline Mode:** Designed to work reliably without needing a constant internet connection.

## 🛠️ Hardware Pins
| Component | ESP32 Pin |
| :--- | :--- |
| Microphone (Sound) | GPIO 34 |
| Servo Motor | GPIO 26 |
| Moisture Sensor | GPIO 32 |

![WhatsApp Image 2025-12-27 at 2 11 54 PM](https://github.com/user-attachments/assets/71b2fdc1-7989-4bb2-a284-05a7b21b1fc0)
