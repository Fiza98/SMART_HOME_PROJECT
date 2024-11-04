const int sensorPin = A0; 
const int ledPin = 10; 
const int threshold = 500;  
const int debounceDelay = 200; 

bool ledState = false; 
unsigned long lastClapTime = 0; 

void setup() {
  pinMode(ledPin, OUTPUT);  
  digitalWrite(ledPin, LOW); 
}

void loop() {
  int sensorValue = analogRead(sensorPin);

  if (sensorValue > threshold && millis() - lastClapTime > debounceDelay) {
    ledState = !ledState;
    digitalWrite(ledPin, ledState ? HIGH : LOW);
    lastClapTime = millis();
  }
}