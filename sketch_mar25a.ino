#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10  // RFID SS pin
#define RST_PIN 9  // RFID RST pin
#define SERVO_PIN 6  // Servo signal pin
#define RED_LED 3  // Red LED pin
#define GREEN_LED 4 // Green LED pin
#define BUZZER 2  // Buzzer pin

Servo myservo;
MFRC522 mfrc522(SS_PIN, RST_PIN);

// ✅ Allowed Card UID (Change this if needed)
byte allowedUID[] = {0x13, 0xCE, 0x59, 0xFB}; 

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  myservo.attach(SERVO_PIN);
  myservo.write(0);  // Servo start position (closed)

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(RED_LED, HIGH); // Red LED blink by default
  Serial.println("Scan Your Card...");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    return;
  }

  Serial.print("Card UID: ");
  bool isAllowed = true;

  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    
    // ✅ UID Verification
    if (mfrc522.uid.uidByte[i] != allowedUID[i]) {
      isAllowed = false;  // Agar koi bhi byte match nahi karti to card invalid
    }
  }
  Serial.println(); // New line for better readability

  if (isAllowed) {
    Serial.println("✅ Access Granted! Gate Opening...");

    // ✅ Buzzer ON for 200ms (Alert Sound)
    digitalWrite(BUZZER, HIGH);
    delay(200);
    digitalWrite(BUZZER, LOW);

    // ✅ Stop Red LED and Blink Green LED for 5 seconds
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);

    // ✅ Open Gate (Servo moves to 90°)
    myservo.write(90);
    delay(5000); // Gate remains open for 5 seconds

    // ✅ Close Gate (Servo moves back to 0°)
    myservo.write(0);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  } else {
    Serial.println("❌ Access Denied! Wrong Card.");
    
    // 🚫 Wrong Card Alert (Buzzer beep for 500ms)
    digitalWrite(BUZZER, HIGH);
    delay(500);
    digitalWrite(BUZZER, LOW);
  }

  delay(2000); // Delay before next scan
}
 