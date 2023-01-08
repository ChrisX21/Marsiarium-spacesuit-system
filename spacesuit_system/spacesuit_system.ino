#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>
MFRC522 mfrc522(10, 9);
LiquidCrystal_I2C lcd(0x27, 16, 2);
char s = 219;
bool isEmpty = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.init();
  lcd.backlight();
  lcd.rightToLeft();

  delay(1000);
  lcd.clear();

  usingOxygen();
}

void loop() {
  // put your main code here, to run repeatedly
 
  //delay(12000);
  
  rechargeOxygen();

}

void usingOxygen() {
  lcd.print(s);
  lcd.print(" ");
  lcd.print(s);
  lcd.print(" ");
  lcd.print(s);
  lcd.print(" ");
  lcd.print(s);

  delay(2000);
  lcd.clear();
  lcd.print(s);
  lcd.print(" ");
  lcd.print(s);
  lcd.print(" ");
  lcd.print(s);

  delay(2000);
  lcd.clear();
  lcd.print(s);
  lcd.print(" ");
  lcd.print(s);

  delay(2000);
  lcd.clear();
  lcd.print(s);

  delay(5000);
  lcd.clear();
  isEmpty = true;
}

void rechargeOxygen() {
  
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "93 4A 97 14" || content.substring(1) == "F3 3E C7 16") 
  {
    Serial.println("Authorized access");
    if(isEmpty = true){
      isEmpty = false;
    lcd.clear();
    lcd.print(s);
    delay(2000);

    lcd.clear();
    lcd.print(s);
    lcd.print(" ");
    lcd.print(s);
    delay(2000);

    lcd.clear();
    lcd.print(s);
    lcd.print(" ");
    lcd.print(s);
    lcd.print(" ");
    lcd.print(s);
    delay(2000);

    lcd.clear();
    lcd.print(s);
    lcd.print(" ");
    lcd.print(s);
    lcd.print(" ");
    lcd.print(s);
    lcd.print(" ");
    lcd.print(s);
    
    }
    else{
      lcd.clear();
      lcd.print("oxygen tank is full!");
    }
  }
 
 else   {
    lcd.print("Access denied");
    delay(3000);
  }
} 
