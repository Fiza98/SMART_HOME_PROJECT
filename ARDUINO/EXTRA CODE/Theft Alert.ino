// This is just extra testing that i did

// please refer in your Blynk Website, you just need to copy 
#define BLYNK_TEMPLATE_ID "xx"
#define BLYNK_TEMPLATE_NAME "xx"
#define BLYNK_AUTH_TOKEN "xx"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

 
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "WiFi Username";  // type your wifi name
char pass[] = "WiFi Password";  // type your wifi password
 
#define PIR_SENSOR  4
BlynkTimer timer;
//int flag=0;
void notifyOnTheft()
{
  int isTheftAlert = digitalRead(PIR_SENSOR);
  Serial.println(isTheftAlert);
  if (isTheftAlert==1) {
    Serial.println("Theft Alert in Home");
    // Blynk.email("XX@gmail.com", "Alert", "Theft Alert in Home");
    //Blynk.notify("Alert : Theft Alert in Home");
    Blynk.logEvent("theft_alert","Theft Alert in Home");
//    flag=1;
  }
  else if (isTheftAlert==0)
  {
   // flag=0;
  }
}

void setup(){
  pinMode(PIR_SENSOR, INPUT);
   Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  //dht.begin();
  timer.setInterval(5000L, notifyOnTheft);
}

void loop(){
  Blynk.run();
  timer.run();
}
