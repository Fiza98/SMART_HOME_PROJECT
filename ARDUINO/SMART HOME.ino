/*Full home automation with the New Blynk app
   Home Page
*/

// Refer the blynk website for ID and Name
#define BLYNK_TEMPLATE_ID "XX"  
#define BLYNK_TEMPLATE_NAME "XX"

//Include the library files
#include <LiquidCrystal_I2C.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

//Initialize the LCD display
LiquidCrystal_I2C lcd(0x27, 16, 2);

char auth[] = "xx";  // Enter your Auth token, refer the Blynk website
char ssid[] = "xx";  // Enter your WIFI name
char pass[] = "xx";  // Enter your WIFI password

DHT dht(D3, DHT11); //(sensor pin,sensor type)
BlynkTimer timer;
bool pirbutton = 0;

// Define component pins
#define Buzzer D0
#define MQ2 A0
#define trig D4
#define echo D5
#define PIR D6
#define relay1 D7
#define relay2 D8

//Get buttons values
BLYNK_WRITE(V0) {
  pirbutton = param.asInt();
}

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(Buzzer, OUTPUT);
  pinMode(PIR, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  dht.begin();

  // Center "SMART HOME" on the first line
  lcd.setCursor((16 - 10) / 2, 0);  // 10 is the length of "SMART HOME"
  lcd.print("SMART HOME");

  // Center "IDAMANKU" on the second line
  lcd.setCursor((16 - 8) / 2, 1);  // 8 is the length of "IDAMANKU"
  lcd.print("IDAMANKU");

  delay(4000);
  lcd.clear();

//Call the functions
  timer.setInterval(100L, gassensor);
  timer.setInterval(100L, DHT11sensor);
  timer.setInterval(100L, pirsensor);
  timer.setInterval(100L, ultrasonic);
}

//Get the MQ2 sensor values
void gassensor() {
  int value = analogRead(MQ2);
  Serial.println(value);
  value = map(value, 0, 1024, 0, 100);
  if (value <= 55) {
    digitalWrite(Buzzer, LOW);
  } else if (value > 55) {
    Blynk.logEvent("gas_leak","Warning! Gas leak detected");
    digitalWrite(Buzzer, HIGH);
  }
  Blynk.virtualWrite(V1, value);
  lcd.setCursor(0, 0);
  lcd.print("G:");
  lcd.print(" ");
  lcd.print(value);

}

//Get the DHT11 sensor values
void DHT11sensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V2, t);
  Blynk.virtualWrite(V3, h);

  lcd.setCursor(8, 0);
  lcd.print("T:");
  lcd.print(t);

  lcd.setCursor(0, 1);
  lcd.print("H:");
  lcd.print(h);

}

// Get the PIR sensor values
void pirsensor() {
  bool value = digitalRead(PIR);
  
  static unsigned long lastDetectionTime = 0;
  static bool motionDetected = false;
  
  unsigned long currentTime = millis();
  
  // Check if enough time has passed since the last detection
  if (currentTime - lastDetectionTime > 1000) { // Adjust the delay if needed
    if (pirbutton == 1) {
      if (value == 1) { // Motion detected
        if (!motionDetected) { // If motion was not previously detected
          Blynk.logEvent("security", "Warning! Motion detected");
          digitalWrite(Buzzer, HIGH);
          motionDetected = true; // Set motionDetected to true
        }
      } else { // No motion detected
        if (motionDetected) { // If motion was previously detected
          digitalWrite(Buzzer, LOW);
          motionDetected = false; // Reset motionDetected to false
        }
      }
      lastDetectionTime = currentTime; // Update the last detection time
    }
  }
}


//Get the ultrasonic sensor values
void ultrasonic() {
  digitalWrite(trig, LOW);
  delayMicroseconds(4);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long t = pulseIn(echo, HIGH);
  long cm = t / 29 / 2;
  Blynk.virtualWrite(V4, cm);

  lcd.setCursor(8, 1);
  lcd.print("W:");
  lcd.print(cm);
  lcd.print("  ");
}

//Get buttons values
BLYNK_WRITE(V5) {
 bool RelayOne = param.asInt();
  if (RelayOne == 1) {
    digitalWrite(relay1, LOW);
  } else {
    digitalWrite(relay1, HIGH);
  }
}

//Get buttons values
BLYNK_WRITE(V6) {
 bool RelayTwo = param.asInt();
  if (RelayTwo == 1) {
    digitalWrite(relay2, LOW);
  } else {
    digitalWrite(relay2, HIGH);
  }
}

void loop() {
  Blynk.run();//Run the Blynk library
  timer.run();//Run the Blynk timer
}
