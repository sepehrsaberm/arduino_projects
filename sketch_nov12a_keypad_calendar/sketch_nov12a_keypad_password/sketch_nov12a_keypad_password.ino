#include <Keypad.h>

const byte ROWS = 4;  // four rows
const byte COLS = 4;  // four columns

char hexaKeys[ROWS][COLS] = {
  { '1', '2', '3', '+' },
  { '4', '5', '6', '-' },
  { '7', '8', '9', '*' },
  { 'C', '0', '=', '/' }
};

byte rowPins[ROWS] = { 2, 3, 4, 5 };  // connect to the row pinouts of the keypad
byte colPins[COLS] = { 6, 7, 8, 9 };  // connect to the column pinouts of the keypad

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

String currentNumber = "";  // to keep track of the entered number
int firstOperand = 0;
int secondOperand = 0;
char currentOperator = '\0';
bool isOperatorPressed = false;
bool isResultDisplayed = false;
const int ledPin = 12;
String code = "";

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  char customKey = customKeypad.getKey();

  if (customKey) {
    if (customKey == '=') {
      if (code == "123") {
        digitalWrite(ledPin, HIGH);
        Serial.println('1');
      } else {
        Serial.println('wrong code!!');
      }
      code="";
    } else {
      digitalWrite(ledPin, LOW);
      code += String(customKey);
      Serial.println('2');
    }
  }
  // currentNumber += customKey;
  // Serial.println(customKey);
}
