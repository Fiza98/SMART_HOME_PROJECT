#define relay2 D8 // Define relay2 as the pin connected to IN2

void setup() {
  pinMode(relay2, OUTPUT); // Set relay2 pin as an output
  digitalWrite(relay2, LOW); // Activate relay2 (assuming it's active-low)
  delay(2000); // Wait for 2 seconds
  digitalWrite(relay2, HIGH); // Deactivate relay2
}

void loop() {
  // Empty loop
}
