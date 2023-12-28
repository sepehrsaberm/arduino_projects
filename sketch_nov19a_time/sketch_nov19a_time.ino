#include <TimeLib.h>

void setup() {
  Serial.begin(9600);

  // Set the initial time (adjust as needed)
  setTime(10, 25, 0, 1, 1, 2023);
}

void loop() {
  // Get the current time
  time_t t = now();

  // Format the time as HH:MM:SS
  char buffer[9];
  sprintf(buffer, "%02d:%02d:%02d", hour(t), minute(t), second(t));

  // Display the time on the Serial Monitor
  Serial.println(buffer);

  delay(1000); // Update the display every second
}
