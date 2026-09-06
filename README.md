# Smart Shopping Trolley with Automated Billing

### Embedded Systems • RFID • Low-Power Design • Real-Time Automated Billing • Retail Automation

> **This repository documents the design, implementation, and rigorous quantitative validation of a self-contained, battery-operated smart shopping trolley that resolves product identity and computes the running bill entirely at the point of shopping—removing the need for a separate checkout stage.**

---

## 📄 Research Publication
This work has been submitted for peer review at the **1st International Emerging Research and Technology Conference (INERTCON 2026)**.

> **Khatija Mahveen**, Neeraja B., and Dr. T. Nagalaxmi. *“Design and Implementation of a Low-Power RFID-Based Smart Shopping Trolley with Real-Time Automated Billing.”* Manuscript submitted August 2026.

---

## 🔍 The Problem with Traditional Checkout
Long checkout lines are a major friction point in physical retail. Barcode scanners require direct line-of-sight, which slows everything down, especially during peak hours. Manual billing also introduces human errors in price entry, product recognition, and item counting.

## 💡 The Core Idea
RFID (Radio Frequency Identification) solves this bottleneck. Because passive RFID tags don't require line-of-sight scanning, a reader can identify a product instantly as soon as it enters the trolley. By embedding an RFID reader into a standard shopping cart, the billing process happens *while* the customer shops—eliminating the wait at the counter entirely.

This design focuses on **fully local, untethered operation**. It does not depend on Wi-Fi, cloud servers, or external computing infrastructure. It runs entirely on a sub-$10 microcontroller and a rechargeable battery.

---

## 🛠️ System Architecture
The system is built around an **Arduino Nano (ATmega328P)** as the central processing unit. The hardware stack includes:

- **MFRC522 RFID Reader (13.56 MHz)** – Detects passive tags on products.
- **16x2 LCD with I2C Interface** – Displays real-time billing updates.
- **18650 Li-ion Battery + Type-C TP4056 Charging Module** – Provides untethered, portable power.
- **Push Button, Buzzer, and LEDs** – Provide user feedback and item removal control.

```text
RFID Tag (Passive)
      ↓
MFRC522 Reader (SPI Protocol)
      ↓
Arduino Nano (Local EEPROM Lookup)
      ↓
16x2 I2C LCD (Real-Time Bill Display)
      ↓
Buzzer + LED (Audio-Visual Confirmation)


### 🧠 The "Two-Step" Removal Mechanism
A key feature of this design is the two-step item removal process. Unlike other RFID trolleys where a single scan can accidentally remove an item, this system requires:

1. Pressing the dedicated remove button.
2. Re-scanning the same tag.

This deliberate protocol prevents the false-additions and false-removals that often occur due to accidental or duplicate scans in single-action systems.

---

### 📊 Experimental Validation
The prototype was tested under realistic conditions:

- 50 unique RFID tags
- 500 total scan attempts
- Tags presented at varying angles and distances to stress-test reliability.
- Billing manually verified across baskets of 3 to 15 items.

#### Key Quantitative Results
| Metric | Result |
| :--- | :--- |
| **RFID Detection Accuracy** | 99.6% (498 out of 500) |
| **Billing Accuracy** | 99.8% (Verified against manual totals) |
| **Checkout Time Reduction** | 77.5% (8.0 mins → 1.8 mins) |
| **Power Consumption** | 65 mA (Continuous operation) |
| **Battery Runtime** | ~8 hours (On 2600mAh 18650 cell) |

#### 🏆 Performance Comparison
| Parameter | Conventional Billing | Existing RFID System | Proposed System |
| :--- | :--- | :--- | :--- |
| Checkout Time (min) | 8.0 | 4.0 | 1.8 |
| Billing Accuracy (%) | 95.2 | 98.4 | 99.8 |
| RFID Detection (%) | — | 98.9 | 99.6 |
| Power Consumption (mA) | — | 90 | 65 |
| Battery Operation | No | Limited | Yes |
| Item Removal | Manual | No | Yes |

---

### 🎓 Why This Matters for Research
This project demonstrates a practical, low-power embedded solution to a real-world retail problem. It validates:

- **Edge Computing:** Running the entire billing loop locally without cloud dependency.
- **Fault-Tolerant User Logic:** Preventing accidental billing errors through the two-step removal protocol.
- **Hardware Efficiency:** Achieving high accuracy (99.6%) and long battery life (8 hours) on a sub-$10 microcontroller.

### 🔮 Future Scope
This prototype serves as a stepping stone for commercial deployment. Future work includes:

- **Cloud Connectivity:** Adding Wi-Fi or Bluetooth for live inventory sync.
- **Digital Payments:** Integrating UPI, QR, or NFC for fully cashier-less checkout.
- **Fleet Management:** A central dashboard to monitor multiple trolleys.
- **Enhanced Verification:** Weight sensors and lightweight vision to catch misplaced items.

---

### 🧑‍💻 Author
**Khatija Mahveen**  
M.E. Embedded Systems & IoT | PhD Aspirant  
Research Intern at DRDO - Research Centre Imarat (RCI)  
Rank 1 in M.E. Embedded Systems  
Paper submitted to INERTCON 2026

### 📜 License
This project is licensed for academic and research purposes.
