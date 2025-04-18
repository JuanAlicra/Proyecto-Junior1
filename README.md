# Rasmobile

**Rasmobile** is a modular mobile robot based on ROS 2, developed as part of the **RAS Junior Program** by IEEE RAS Javeriana, Pontificia Universidad Javeriana (Bogotá, Colombia). The project introduces students to robotics through hands-on experience, from simulation to real hardware integration.

## 🤖 Introduction

Rasmobile is an educational differential-drive mobile robot capable of performing basic autonomous navigation tasks using reactive obstacle avoidance. It was designed and built by first-year students in Mechatronics, Electronics, and Systems Engineering as a learning platform for the complete development cycle of a robot using ROS 2.

The robot uses an ESP32 microcontroller for low-level control, integrates sensors for obstacle detection, and communicates with ROS 2 nodes running on a host machine. Simulation is done with `turtlesim`, and the code for ROS 2 packages is written in Python and C++.

This project emphasizes **learning by doing**, introducing students to publish/subscribe patterns, services, firmware deployment, and system integration.

---

## 🧩 Project Structure

```
Rasmobile/
├── esp_firmware/              --> Code for the ESP32 microcontroller
├── ras2_services/             --> ROS 2 nodes controlling robot behavior
├── ros2_communication/        --> Serial communication between ROS and hardware
├── media/                     --> (Optional) Images and videos for documentation
└── README.md                  --> Project documentation
```

---

## 🚀 How to Run

### Requirements

- ROS 2 Humble  
- Python 3.8+  
- Arduino IDE or PlatformIO  
- USB connection to ESP32  
- Python package `pyserial`  

### 1. Upload Firmware to ESP32

```bash
cd esp_firmware/
pio run --target upload
```

### 2. Source ROS 2 and Run the Nodes

```bash
source /opt/ros/humble/setup.bash

# Run ROS 2 services and communication nodes
ros2 run ras2_services movement_service.py
ros2 run ros2_communication serial_node.py
```

---

## ⚙️ ROS 2 Architecture

```
[ROS 2 Service Node] ---> [Serial Node] ---> [ESP32 Firmware] ---> [Motors]
                                     ↑                        ↓
                              [Sensor feedback] <-------------
```

---

## 🎯 Educational Objective

This project was developed by first-semester students with the goal of understanding:

- ROS 2 architecture (nodes, services, pub/sub)
- Microcontroller communication via serial (ESP32)
- Real-time sensor feedback
- System integration from simulation (Turtlesim) to real hardware

It serves as a foundation for more advanced robotics development and contributions to the ROS ecosystem.

---

## 🖼️ Media

Robot Design Sketch

Initial sketch showing the modular design and layout of the Rasmobile components.


Assembled Rasmobile Prototype

Final prototype of Rasmobile, built and wired by first-semester students during the RAS Junior Program.
---

## 📄 License

This project is licensed under the MIT License.

```
MIT License

Copyright (c) 2025 Juan Sebastian Arcila Morales

```

---

## 👥 Contributors

Developed by students of the **RAS Junior Program** – IEEE RAS Javeriana  
Pontificia Universidad Javeriana – Bogotá, Colombia  
Mechatronics, Electronics, and Systems Engineering – 3rd semester

> Submitted as part of the ROSCon 2025 Bursary Application
