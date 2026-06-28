# 🐾 Smart Pet Feeder Control System

<p align="center">

![HTML](https://img.shields.io/badge/HTML5-E34F26?style=for-the-badge&logo=html5&logoColor=white)
![CSS](https://img.shields.io/badge/CSS3-1572B6?style=for-the-badge&logo=css3&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)
![ESP32](https://img.shields.io/badge/ESP32-IoT-blue?style=for-the-badge)
![Supabase](https://img.shields.io/badge/Supabase-3ECF8E?style=for-the-badge&logo=supabase&logoColor=white)

</p>

---

## 📖 Overview

The Smart Pet Feeder Control System is an IoT-based solution that enables pet owners to remotely feed their pets through a modern web application.

The system combines a responsive frontend, a cloud database powered by Supabase, and an ESP32 microcontroller controlling a servo motor and relay module for automatic food dispensing.

---

## ✨ Features

🐱 Pet Selection

🍖 Feed Instantly

⏰ Meal Scheduling

📅 Scheduled Meal Management

❌ Cancel Scheduled Meals

📊 Live Feeding Status

☁️ Supabase Cloud Synchronization

📱 Responsive Design

🔌 ESP32 Integration

⚡ Automatic WiFi Reconnection

🛡 Input Validation

---

## 🛠 Technologies

### Frontend

- HTML5
- CSS3
- JavaScript (ES6)

### Backend

- Supabase REST API
- PostgreSQL

### Embedded System

- ESP32
- Servo Motor
- Relay Module

### Libraries

- WiFi
- HTTPClient
- ArduinoJson
- ESP32Servo

---

## 🏗 System Architecture

```
Website
      │
      ▼
Supabase Database
      │
      ▼
ESP32 Firmware
      │
 ┌────┴────┐
 ▼         ▼
Relay    Servo
      │
      ▼
 Pet Food Dispensed
```

---

## 📂 Project Structure

```
pet-feeder-control-system
│
├── assets/
├── css/
├── docs/
├── firmware/
├── js/
├── index.html
├── README.md
├── LICENSE
└── .gitignore
```

---

## 🚀 Future Improvements

- User Authentication
- Mobile App
- Push Notifications
- Camera Monitoring
- Feeding Analytics
- Dark Mode
- Voice Assistant
- ESP32 OTA Updates

---
Made with ❤️ for pet owners who want the best for their furry friends
---

## 📜 License

Licensed under the MIT License.
