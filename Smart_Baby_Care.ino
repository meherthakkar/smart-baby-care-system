#include <WiFi.h>             // Can remove this too if WiFi not used elsewhere
#include <Arduino.h>
#include <ESP32Servo.h>

// Flags
int cry = 0;
int wet = 0;

// Pin Definitions
const int soundPin = 34;       // Microphone analog pin
const int servoPin = 26;       // Servo motor pin
const int MOISTURE_PIN = 32;   // Moisture sensor pin

// Cry detection threshold
const int threshold = 2500;
bool alertSent = false;

// Servo control
Servo cradleServo;
int soundLevel;
int centerPos = 90;

void setup() {
  Serial.begin(115200);
  pinMode(soundPin, INPUT);

  cradleServo.attach(servoPin);
  cradleServo.write(centerPos);  // Neutral position

  Serial.println("System Initialized (No Internet Mode)");
}

void loop() {
  soundLevel = analogRead(soundPin);
  Serial.println("Sound Level: " + String(soundLevel));

  // Cry detection
  if (soundLevel > threshold && !alertSent) {
    Serial.println("Cry detected!");
    cry = 1;
    alertSent = true;

    swingCradle();
  }

  if (alertSent) {
    delay(1000);
    alertSent = false;
  }

  // Moisture detection
  int moistureValue = analogRead(MOISTURE_PIN);
  Serial.println("Moisture: " + String(moistureValue));

  if (moistureValue < 1500) {
    Serial.println("Baby wets bed! Moisture detected!");
    wet = 1;
    delay(30000); // Avoid repeating immediately
  }

  delay(2000); // Wait between sensor readings
}

void swingCradle() {
  unsigned long start = millis();
  Serial.println("Swinging cradle...");
  while (millis() - start < 8000) {
    cradleServo.write(60);   // swing left
    delay(1000);
    cradleServo.write(120);  // swing right
    delay(1000);
  }
  cradleServo.write(centerPos); // stop swinging
  Serial.println("Cradle stopped.");
}
