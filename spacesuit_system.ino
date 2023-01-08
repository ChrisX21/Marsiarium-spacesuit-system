#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
char s = 219;
bool isEmpty = false;
void setup() {
  // put your setup code here, to run once:

  lcd.begin();
  lcd.backlight();  
  lcd.rightToLeft();
  
 delay(1000);
  lcd.clear();
 
 usingOxygen();
}

void loop() {
  // put your main code here, to run repeatedly

 
    
}

void usingOxygen(){
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

void rechargeOxygen(){
  if (isEmpty = true){
  
  }
}
