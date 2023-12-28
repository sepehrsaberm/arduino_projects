#include <MaxMatrix.h>

int DIN = 7;
int CLK = 6;
int CS = 5;
int maxInUse = 2;

MaxMatrix m(DIN, CS, CLK, maxInUse);

byte pakman[] = { 8, 8, 0x1c, 0x22, 0x41, 0x49, 0x55, 0x22, 0x00, 0x08 };
byte poker[] = { 8, 8,
                 0xff,
                 0x81,
                 0xa5,
                 0xa1,
                 0xa1,
                 0xa5,
                 0x81,
                 0xff };

void setup() {
  m.init();
  m.setIntensity(2);
}
void loop() {
  m.writeSprite(0, 0, poker);
  delay(300);
  for (int i = 0; i < 8; i++) {
    m.shiftRight(false, true);
    delay(300);
  }
  m.clear();
}