#define Buzzer D0 // Define the pin connected to the buzzer

void setup() {
  pinMode(Buzzer, OUTPUT); // Set the buzzer pin as an output

  // Turn the buzzer on
  digitalWrite(Buzzer, HIGH);
  delay(1000); // Keep the buzzer on for 1 second (1000 milliseconds)

  // Turn the buzzer off
  digitalWrite(Buzzer, LOW);
  delay(1000); // Wait for 1 second

  // Turn the buzzer on again
  digitalWrite(Buzzer, HIGH);
  delay(1000); // Keep the buzzer on for another 1 second

  // Turn the buzzer off again
  digitalWrite(Buzzer, LOW);
}

void loop() {
  // Empty loop
}
