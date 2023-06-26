#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_TEMPLATE_ID "TMPLHf2Zn4vA"
#define BLYNK_TEMPLATE_NAME "Subramani E"
#define BLYNK_AUTH_TOKEN "KT9aQzdSmz5s3jSecDz9fUVg9ZL6TEyo"
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "subru";       //Enter your WIFI name
char pass[] = "subrurocks";  //Enter your WIFI password

//Get the button value
BLYNK_WRITE(V0) {
  digitalWrite(D0, param.asInt());
  if (digitalRead(D0) == 0) {
    Serial.write('a');
  } else {
    Serial.write('A');
  }
}
BLYNK_WRITE(V1) {
  digitalWrite(D1, param.asInt());
  if (digitalRead(D1) == 0) {
    Serial.write('b');
  } else {
    Serial.write('B');
  }
}
BLYNK_WRITE(V2) {
  digitalWrite(D2, param.asInt());
  if (digitalRead(D2) == 0) {
    Serial.write('c');
  } else {
    Serial.write('C');
  }
}
BLYNK_WRITE(V3) {
  digitalWrite(D3, param.asInt());
  if (digitalRead(D3) == 0) {
    Serial.write('d');
  } else {
    Serial.write('D');
  }
}

void setup() {
  //Set the LED pin as an output pin
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  //Initialize the Blynk library
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  //Run the Blynk library
  Blynk.run();
}