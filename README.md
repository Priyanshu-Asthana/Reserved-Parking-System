# Reserved-Parking-System
The RFID-Based Reserved Parking System is an Arduino-controlled automated parking system that allows entry only to authorized vehicles using RFID authentication. When an authorized RFID card or token is scanned, the servo motor-controlled gate opens for 5 seconds, while an LED and buzzer indicate successful access. Unauthorized attempts trigger a buzzer alert and deny entry.

🔹 Key Features:
✔️ RFID Authentication – Only registered RFID cards can access the parking area.
✔️ Automated Gate Control – Servo motor operates the barrier gate upon successful scan.
✔️ LED Indicators – Red LED blinks continuously, stops on valid scan, and green LED blinks for 5 seconds.
✔️ Buzzer Alerts – Short beep for valid access, long beep for unauthorized attempts.
✔️ Security & Automation – Ensures restricted entry, making parking more secure and efficient.

🔹 Technologies & Components Used:
🔹 Hardware: Arduino Uno, RFID Module (MFRC522), Servo Motor, LEDs (Red & Green), Buzzer, Breadboard, Resistors, Jump Wires
🔹 Software: Arduino IDE (C++ for programming)
🔹 Libraries Used: MFRC522.h, SPI.h, Servo.h

🔹 How It Works?
1️⃣ User scans an RFID card near the RFID reader.
2️⃣ System checks the card's unique ID (UID).

✅ If the card is authorized:

Red LED stops blinking, Green LED blinks.

Gate opens via servo motor for 5 seconds.

Short beep from the buzzer confirms access.

❌ If the card is unauthorized:

Red LED continues blinking.

Buzzer gives a long alert sound.

Gate remains closed.
3️⃣ After 5 seconds, the gate automatically closes and the red LED starts blinking again.

🔹 Applications:
✅ Smart Parking Systems – Automating reserved parking for offices, apartments, and malls.
✅ Access Control Systems – Restricting entry to authorized vehicles only.
✅ Security Enhancement – Preventing unauthorized access to parking areas.

🔹 Why This Project?
🚀 Enhances security & automation by preventing unauthorized access.
🚀 Reduces human intervention in parking management.
🚀 Cost-effective & scalable solution for modern smart parking systems.

