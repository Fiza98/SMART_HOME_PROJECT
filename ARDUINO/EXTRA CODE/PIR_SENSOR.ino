#define PIR D6  // Define the pin connected to the PIR sensor
#define LED D7  // Define an LED pin to indicate motion (optional)

void setup() {
  pinMode(PIR, INPUT);  // Set PIR sensor pin as input
  pinMode(LED, OUTPUT); // Set LED pin as output (optional)
  Serial.begin(9600);   // Start serial communication at 9600 baud rate
}

void loop() {
  int pirState = digitalRead(PIR);  // Read the PIR sensor input

  if (pirState == HIGH) {  // If motion is detected
    Serial.println("Motion detected!");
    digitalWrite(LED, HIGH); // Turn on the LED (optional)
  } else {
    digitalWrite(LED, LOW);  // Turn off the LED (optional)
  }

  delay(500);  // Small delay to avoid overwhelming the serial output
}
