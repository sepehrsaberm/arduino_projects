#include <Keypad.h>

const byte ROWS = 4; // four rows
const byte COLS = 4; // four columns

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'C', '0', '=', '/'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};    // connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9};    // connect to the column pinouts of the keypad

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

String currentNumber = ""; // to keep track of the entered number
int firstOperand = 0;
int secondOperand = 0;
char currentOperator = '\0';
bool isOperatorPressed = false;
bool isResultDisplayed = false;

void setup() {
  Serial.begin(9600);
}

void loop() {
  char customKey = customKeypad.getKey();

  if (customKey) {
    // Check if the key is a number
    if (customKey >= '0' && customKey <= '9') {
      if (isResultDisplayed) {
        currentNumber = "";
        isResultDisplayed = false;
      }
      currentNumber += customKey;
      Serial.println(customKey);
    }
    // Check if the key is an operator
    else if (customKey == '+' || customKey == '-' || customKey == '*' || customKey == '/') {
      if (!isOperatorPressed && currentNumber != "") {
        firstOperand = currentNumber.toInt();
        currentOperator = customKey;
        isOperatorPressed = true;
        currentNumber = "";
        Serial.println(customKey);
      }
    }
    // Check if the key is equals (=)
    else if (customKey == '=') {
      if (isOperatorPressed && currentNumber != "") {
        secondOperand = currentNumber.toInt();
        int result = 0;
        switch (currentOperator) {
          case '+':
            result = firstOperand + secondOperand;
            break;
          case '-':
            result = firstOperand - secondOperand;
            break;
          case '*':
            result = firstOperand * secondOperand;
            break;
          case '/':
            if (secondOperand != 0) {
              result = firstOperand / secondOperand;
            }
            break;
        }
        Serial.println(result);
        currentNumber = String(result);
        isOperatorPressed = false;
        isResultDisplayed = true;
      }
    }
    // Check if the key is clear (C)
    else if (customKey == 'C') {
      firstOperand = 0;
      secondOperand = 0;
      currentOperator = '\0';
      currentNumber = "";
      isOperatorPressed = false;
      Serial.println("C");
    }
  }
}