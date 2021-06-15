// Levels of Automation Laboratories
// Fully Automatic Local control

#include "DHT.h"
#define DHTTYPE DHT11 // DHT 11

#define dht_dpin 4
DHT dht(dht_dpin, DHTTYPE);

int MotorPin=5; // Motor

void setup()
{
  Serial.begin(9600);
  pinMode(MotorPin, OUTPUT);
  digitalWrite(MotorPin, LOW); // Motor starts turned off
  delay(700);
}

void loop()
{
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    Serial.print("Current humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t);
    Serial.println("C  ");

  if (h>90){
    digitalWrite(MotorPin, HIGH); // Motor activates
    Serial.println("Prendido");
  }
  else {
    digitalWrite(MotorPin, LOW);
    Serial.println("Apagado");
  }
  delay(800);
}
