# Smart Shopping Trolley with Automated Billing

### Embedded Systems • RFID • Low-Power Design • Real-Time Automated Billing • Retail Automation

> **This project details the design, implementation, and quantitative validation of a self-contained, battery-operated smart shopping trolley that resolves product identity and computes the running bill entirely at the point of shopping, removing the need for a separate checkout stage.**

---

## 🔍 The Core Idea
Long checkout lines remain one of the most persistent friction points in physical retail, especially during peak hours. Traditional barcode-based counters require direct line-of-sight scanning, which slows everything down. 

This prototype uses RFID (Radio Frequency Identification) to bypass that bottleneck. Since RFID reads tags without requiring a direct line of sight, product detection happens faster and with fewer failed reads. The goal was to build a completely local, untethered system that doesn't depend on cloud servers or Wi-Fi—just clean, reliable embedded hardware.

---

## 🛠️ System Architecture
The system is built around an Arduino Nano acting as the central controller. It interfaces with an MFRC522 RFID reader (13.56 MHz), a 16x2 I2C LCD, a rechargeable 18650 Li-ion battery (via a Type-C TP4056 module), a buzzer, and status LEDs.

**Data Flow:**
```text
RFID Tag (Passive) 
   ↓
MFRC522 Reader (SPI Protocol)
   ↓
Arduino Nano (Local EEPROM Product Lookup)
   ↓
16x2 I2C LCD (Real-Time Bill Display)
   ↓
Buzzer + LED (Audio-Visual Feedback)
