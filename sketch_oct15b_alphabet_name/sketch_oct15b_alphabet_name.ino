#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const byte armsDown[8] = {
  B00100,
  B01110,
  B00100,
  B01110,
  B10101,
  B00100,
  B01010,
  B10001
};

const byte armsUp[8] = {
  B00100,
  B01110,
  B10101,
  B01110,
  B00100,
  B00100,
  B01010,
  B10001
};
int thisChar = 'a';


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.createChar(0, armsDown);
  lcd.createChar(1, armsUp);
}
int count = 0;
void loop() {
  
  lcd.setCursor(count, 0);
  if (thisChar == 'p') {
    lcd.rightToLeft();
    lcd.write(thisChar);
    delay(200);
  }

  if (thisChar > 'z') {
    lcd.home();
    lcd.leftToRight();
    thisChar = 'a';
    lcd.write(thisChar);
    delay(200);
    lcd.clear();
  }

  lcd.write(thisChar);
  delay(200);
  thisChar++;


  
  lcd.setCursor(count, 1);
  lcd.print("sepehr");
  delay(200);
  lcd.scrollDisplayRight();
  lcd.clear();
  count++;
}
