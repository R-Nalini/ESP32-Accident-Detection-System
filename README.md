# ESP32-Accident-Detection-System
IoT based accident detection system using ESP32, MPU6050 and GPS
📖 Project Overview

This project presents an IoT-based accident detection system using ESP32, MPU6050 accelerometer, and GPS module.

The system continuously monitors vehicle motion and detects sudden changes in acceleration that may indicate an accident.

When an accident is detected, the ESP32 retrieves real-time GPS coordinates (latitude and longitude) and displays them through the Serial Monitor. The system can be extended for real-time emergency alert applications.

🎯 Objective

Detect vehicle accidents automatically
Obtain real-time GPS location
Reduce emergency response time
🛠 Components Used

ESP32
MPU6050 (Accelerometer & Gyroscope)
GPS Module
Power Supply
⚙ Working Principle

MPU6050 monitors acceleration values.
If acceleration exceeds a threshold (e.g., 2.5g), accident is detected.
GPS module fetches location.
Location is displayed on Serial Monitor.
🚀 Future Scope

Add GSM for SMS alerts
Cloud integration
Mobile application support
📚 Required Libraries

Wire.h
MPU6050
TinyGPS++
WiFi.h (optional)
float accidentThreshold = 2.5; // g-force threshold
