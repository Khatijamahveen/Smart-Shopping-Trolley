#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9
#define BUTTON_PIN 6
#define RED_LED 8
#define GREEN_LED 5
#define BUZZER 4

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adjust I2C address if needed

double total = 0;
int count_prod = 0;
int p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0;

// Replace with your actual tag UIDs (use Serial.print to find them)
byte butterUID[4] = {0x03, 0xD2, 0x18, 0x22};
byte milkUID[4]   = {0xC3, 0xCB, 0x2E, 0x22};
byte teaUID[4]    = {0x73, 0xD1, 0x1C, 0x22};
byte riceUID[4]   = {0x83, 0x55, 0x75, 0x22};
byte soapUID[4]   = {0x13, 0x67, 0x2B, 0x22};

void setup() {
  Wire.begin();
  lcd.begin();
  lcd.backlight();

  SPI.begin();
  mfrc522.PCD_Init();

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("AUTOMATIC BILL");
  delay(2000);
  lcd.clear();
  lcd.print("SHOPPING CART");
  delay(2000);
  lcd.clear();
  lcd.print("WELCOME TO");
  lcd.setCursor(3, 1);
  lcd.print("SUPERMARKET");
  delay(2000);
  lcd.clear();
  lcd.print("Scan Item...");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial())
    return;

  byte* scannedUID = mfrc522.uid.uidByte;
  bool removeMode = digitalRead(BUTTON_PIN) == LOW;

  if (!removeMode) p1++; else if (p1 > 0) p1--;
  } 
  if (compareUID(scannedUID, butterUID)) {
    handleItem("Butter", 47.0, p1, removeMode);
  else if (compareUID(scannedUID, milkUID)) {
    handleItem("Milk", 33.0, p2, removeMode); 
    if (!removeMode) p2++; else if (p2 > 0) p2--;
  }
  else if (compareUID(scannedUID, teaUID)) {
    handleItem("Tea", 29.0, p3, removeMode);
     if (!removeMode) p3++; else if (p3 > 0) p3--;
  }
  else if (compareUID(scannedUID, riceUID)) {
    handleItem("Rice", 50.0, p4, removeMode); 
    if (!removeMode) p4++; else if (p4 > 0) p4--;
  }
  else if (compareUID(scannedUID, soapUID)) {
    handleItem("Soap", 45.0, p5, removeMode); 
    if (!removeMode) p5++; else if (p5 > 0) p5--;
  }
  else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Unknown Item!");
    buzz(300);
    delay(2000);
  }

  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
}

void handleItem(const char* name, float price, int quantity, bool removeMode) {
  lcd.clear();
  if (removeMode) {
    if (quantity > 0) {
      lcd.print(name);
      lcd.print(" Removed");
      total -= price;
      count_prod--;
      buzz(300);
    } else {
      lcd.print("Not in cart!");
      buzz(300);
    }
  } else {
    lcd.print(name);
    lcd.print(" Added");
    total += price;
    count_prod++;
    buzz(300);
  }
  lcd.setCursor(0, 1);
  lcd.print("Total: Rs ");
  lcd.print(total);
  delay(4000);
  lcd.clear();
  lcd.print("Scan Item...");
}

bool compareUID(byte* a, byte* b) {
  for (byte i = 0; i < 4; i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

void buzz(int duration) {
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BUZZER, HIGH);
  delay(duration);
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BUZZER, LOW);
}
