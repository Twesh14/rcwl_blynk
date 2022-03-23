#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "";
char pass[] = "";

// For D1 pin in NodeMCU
#define inPin 5
int count = 0; 

void setup()
{
  
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(inPin,INPUT);
  Blynk.notify("Mission Started");
}

void loop()
{
  Blynk.run();
  bool value = digitalRead(inPin);
  if (value == 1) { 
    count++;
    Blynk.notify("Value is true");
    Blynk.virtualWrite(V1,count);
  }
  delay(3000);
}
