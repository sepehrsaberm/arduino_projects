#include "SevSeg.h"
SevSeg sevseg;
int buttonState = 0;
void setup() {
  //Set to 1 for single digit display
  byte numDigits = 1;
  randomSeed(analogRead(0));
  Serial.begin(9600);
  //defines common pins while using multi-digit display. Left empty as we have a single digit display
  byte digitPins[] = {};
  pinMode(12, INPUT);
  //Defines arduino pin connections in order: A, B, C, D, E, F, G, DP
  byte segmentPins[] = { 3, 2, 8, 7, 6, 4, 5, 9 };
  bool resistorsOnSegments = true;

  //Initialize sevseg object. Uncomment second line if you use common cathode 7 segment
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
}

void loop() {
  buttonState = digitalRead(12);
  sevseg.setNumber(1);
  Serial.println(buttonState);
 if (buttonState == 1) {
    int randomNumber = random(5)+1;
    sevseg.setNumber(randomNumber);
    // Display numbers one by one with 2 seconds delay
    // for (int i = 0; i < 10; i++) {
    //   sevseg.setNumber(i);
      sevseg.refreshDisplay();
    //   delay(2000);
    // }
  }
  else {
    // turn LED off:
    sevseg.setNumber(2);
    // digitalWrite(ledPin, LOW);
  }
  // int randomNumber = random(6) + 1;
  //Display numbers one by one with 2 seconds delay
  // for (int i = 0; i < 10; i++) {
  //   sevseg.setNumber(i);
  //   sevseg.refreshDisplay();
  //   delay(2000);
  // }
}