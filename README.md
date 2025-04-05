# 🚁 Autonomous Agricultural Drone for Crop Monitoring

This is an autonomous agricultural drone designed to monitor crop health, altitude, and avoid obstacles in real-time using ultrasonic sensors, Arduino microcontroller, and motor control.

---

## 📍 Project Overview

The drone:
- Maintains a constant altitude (2 meters).
- Avoids obstacles automatically.
- Stabilizes a mounted camera for real-time crop imaging.

---

## ⚙️ Hardware Requirements

| Component               | Specification/Details         |
|--------------------------|--------------------------------|
| Microcontroller          | Arduino Uno or Mega            |
| Brushless Motors         | 4 × 1000KV with ESCs           |
| Ultrasonic Sensors       | 2 × HC-SR04                    |
| Servo Motor              | 1 × SG90 for Camera Stabilization |
| LiPo Battery             | 11.1V 2200mAh                  |
| Propellers               | 10x4.5 or similar              |
| Frame                    | Lightweight Drone Frame        |
| Jumper Wires             | Male to Male                   |

---

## 🔌 Circuit Connections

| Purpose                  | Pin Connections                |
|---------------------------|---------------------------------|
| Motor 1 (Front Left)       | PWM Pin 3                      |
| Motor 2 (Front Right)      | PWM Pin 5                      |
| Motor 3 (Rear Left)        | PWM Pin 6                      |
| Motor 4 (Rear Right)       | PWM Pin 9                      |
| Altitude Sensor TRIG       | Digital Pin 7                  |
| Altitude Sensor ECHO       | Digital Pin 8                  |
| Obstacle Sensor TRIG       | Digital Pin 10                 |
| Obstacle Sensor ECHO       | Digital Pin 11                 |
| Camera Stabilization Servo | PWM Pin 12                     |

---

## 🚀 How It Works

1. **Takeoff & Maintain Altitude**:
    - Drone tries to maintain a 2-meter altitude.
    - If it drops below/above ±20cm, motor speeds are adjusted.

2. **Obstacle Detection**:
    - Front ultrasonic sensor detects obstacles within 1 meter.
    - If detected, drone hovers to avoid collision.

3. **Camera Stabilization**:
    - Servo ensures a steady camera angle while flying.

---

## 🎯 Future Improvements

- GPS integration for waypoint navigation.
- Crop health analysis via NDVI imaging.
- Soil moisture and environmental sensing.

---

## 🙌 Contributions

This project is maintained by:

- GitHub ID: [@your-github-username](https://github.com/your-github-username)

Feel free to contribute by submitting issues or pull requests! 🤝

---
