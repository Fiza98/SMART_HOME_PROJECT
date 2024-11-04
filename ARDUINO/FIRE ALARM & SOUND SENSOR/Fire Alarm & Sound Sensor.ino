const int flamePin = A2;       // Flame sensor connected to analog pin A2
const int flameLedPin = 13;    // LED for flame sensor feedback connected to digital pin 13
const int buzPin = 11;         // Buzzer connected to digital pin 11
const int flameThreshold = 200; // Threshold for flame sensor

const int soundSensorPin = A0; // Sound sensor connected to analog pin A0
const int soundLedPin1 = 8;    // First sound LED connected to digital pin 8
const int soundLedPin2 = 9;    // Second sound LED connected to digital pin 9
const int soundLedPin3 = 10;   // Third sound LED connected to digital pin 10
const int soundThreshold = 500; // Threshold for sound sensor
const int debounceDelay = 200; // Debounce delay for sound sensor

int flameSensorValue = 0;      // Variable to store the flame sensor reading
bool soundLedState = false;    // Variable to keep track of the LED state for sound sensor
unsigned long lastClapTime = 0; // Variable to store the last clap time

void setup() {
  Serial.begin(9600);
  pinMode(flameLedPin, OUTPUT);
  pinMode(flamePin, INPUT);
  pinMode(buzPin, OUTPUT);
  pinMode(soundLedPin1, OUTPUT);
  pinMode(soundLedPin2, OUTPUT);
  pinMode(soundLedPin3, OUTPUT);
  digitalWrite(flameLedPin, LOW);
  digitalWrite(soundLedPin1, LOW);
  digitalWrite(soundLedPin2, LOW);
  digitalWrite(soundLedPin3, LOW);
}

void loop() {
  // Read the flame sensor
  flameSensorValue = analogRead(flamePin);

  if (flameSensorValue <= flameThreshold) {
    digitalWrite(flameLedPin, HIGH); // Turn on the flame LED
    tone(buzPin, 100);              // Turn on the buzzer
  } else {
    digitalWrite(flameLedPin, LOW);  // Turn off the flame LED
    noTone(buzPin);                  // Turn off the buzzer
  }

  // Read the sound sensor
  int soundSensorValue = analogRead(soundSensorPin);

  if (soundSensorValue > soundThreshold && millis() - lastClapTime > debounceDelay) {
    soundLedState = !soundLedState; // Toggle the sound LED state
    digitalWrite(soundLedPin1, soundLedState ? HIGH : LOW); // Control first sound LED
    digitalWrite(soundLedPin2, soundLedState ? HIGH : LOW); // Control second sound LED
    digitalWrite(soundLedPin3, soundLedState ? HIGH : LOW); // Control third sound LED
    lastClapTime = millis();       // Update the last clap time
  }
}
