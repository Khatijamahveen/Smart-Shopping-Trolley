# Design and Implementation of a Low-Power RFID-Based Smart Shopping Trolley with Real-Time Automated Billing

### Embedded Systems • RFID • Low-Power Design • Real-Time Automated Billing • Retail Automation • IoT

> **This repository presents the design, implementation, and rigorous quantitative validation of a self-contained, battery-operated smart shopping trolley that resolves product identity and computes the running bill entirely at the point of shopping, removing the need for a separate checkout stage.**

---

## 📄 Research Publication
**Khatija Mahveen** (with co-authors Neeraja B. and Dr. T. Nagalaxmi). 
*“Design and Implementation of a Low-Power RFID-Based Smart Shopping Trolley with Real-Time Automated Billing.”* 
**Submitted to the 1st International Emerging Research and Technology Conference (INERTCON 2026).** 
*Manuscript submitted, August 2026.*

---

## 💻 Hardware Components
| Component | Specification | Purpose |
| :--- | :--- | :--- |
| Arduino Nano | ATmega328P | Main controller |
| RFID Reader | MFRC522 (13.56 MHz) | Product identification |
| RFID Tags | Passive Tags | Product data storage |
| LCD Display | 16x2 I2C | Real-time billing display |
| Push Buttons | Normally Open | Item addition/removal control |
| Buzzer | 5V | Audio feedback |
| LEDs | Red/Green | Visual status indication |
| Battery | 18650 Li-ion | Portable power supply |
| Charging Module | Type-C TP4056 | Battery charging |

---

## ⚙️ Operational Algorithm
The system follows a straightforward yet effective loop:

1. Initialize Nano, RFID reader, LCD, and peripherals.
2. Set running total to zero.
3. Wait for RFID tag to appear.
4. Read tag ID and look it up in the local EEPROM product table.
5. **If found:**
   - Retrieve product name and price.
   - Add price to running total.
   - Display on LCD.
   - Trigger buzzer + LED.
6. **If remove button is pressed:**
   - Read tag again.
   - Subtract price from total.
   - Refresh LCD display.
7. Repeat until shopping session ends.
8. Display final bill.

---

## 🧮 Mathematical Model
Let \( P_i \) be the price of the i-th product and \( N \) be the total number of products. The total bill \( T \) is:

\[
T = \sum_{i=1}^{N} P_i
\]

For item removal:

\[
T_{new} = T - P_r
\]

where \( P_r \) is the price of the removed product.

---

## 📊 Experimental Results & Validation
The prototype was tested under realistic conditions: 50 unique tags, 500 total scan attempts, with each tag presented at varying angles and distances to stress-test reliability.

**Key Metrics:**
- **Detection Accuracy:** 99.6% (498 correct out of 500 scans)
- **Billing Accuracy:** 99.8% (Verified across baskets of 3 to 15 items)
- **Checkout Time Reduction:** 77.5% (8.0 min under conventional billing → 1.8 min with prototype)
- **Power Consumption:** 65 mA total draw
- **Battery Runtime:** ~8 hours continuous operation on a 2600mAh 18650 cell

**Performance Comparison:**

| Parameter | Conventional Billing | Existing RFID System | **Proposed System** |
| :--- | :--- | :--- | :--- |
| Checkout Time (min) | 8.0 | 4.0 | **1.8** |
| Billing Accuracy (%) | 95.2 | 98.4 | **99.8** |
| RFID Detection (%) | — | 98.9 | **99.6** |
| Power Consumption (mA) | — | 90 | **65** |
| Battery Operation | No | Limited | **Yes** |
| Item Removal | Manual | No | **Yes** |

---

## 🎓 Why This Matters for Research
This project applies core embedded systems theory to a real-world problem with **actual, rigorous quantitative validation**. It demonstrates:

- **Low-Power Embedded Design:** Achieving 65mA operation ensures all-day untethered use.
- **Fault-Tolerant User Logic:** The two-step removal mechanism prevents user errors.
- **Edge Computing:** Running the entire billing loop locally without cloud dependency is a critical IoT research direction.
- **Scalable Platform:** The hardware base leaves clear room for future IoT connectivity, digital payments, and AI-driven analytics.

---

## 🔮 Future Scope
This design is meant to be a stepping stone, not an endpoint:

- **Cloud Integration:** Adding Wi-Fi or Bluetooth would allow real-time synchronization with store inventory databases.
- **Digital Payments:** Integrating UPI, QR, or NFC support would enable fully cashier-less checkout.
- **Fleet Management:** A central dashboard could monitor multiple trolleys simultaneously.
- **Enhanced Verification:** Adding weight sensors would catch misplaced items that RFID alone might miss.

---

## 🧑‍💻 Author
**Khatija Mahveen**
- M.E. Embedded Systems & IoT | PhD Aspirant
- Research Intern at DRDO - Research Centre Imarat (RCI)
- Rank 1 in M.E. Embedded Systems
- Paper submitted to INERTCON 2026

## 📜 License
This project is licensed for academic and research purposes.
