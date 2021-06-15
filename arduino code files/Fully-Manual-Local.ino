// Levels of Automation Laboratories
// Fully Manual Local control

#include "DHT.h"
#define DHTTYPE DHT11   // DHT 11

#define dht_dpin 4
DHT dht(dht_dpin, DHTTYPE);

int MotorPin=5; // Motor
int ValueRead=2;
int myflag=0;

void setup()
{
  Serial.begin(9600);
  pinMode(MotorPin, OUTPUT);
  digitalWrite(MotorPin, LOW); // Motor starts turned off
}

void loop()
{
  if (Serial.available()){
    ValueRead=Serial.parseInt();
  }
    if (((ValueRead==1 && myflag==0)|| myflag==1)&!(ValueRead==2 && myflag==1)){
      digitalWrite(MotorPin, HIGH); // Motor activates
      Serial.println("Prendido");
      myflag=1;
    }
    else{
      digitalWrite(MotorPin, LOW); // Motor deactivates
      Serial.println("Apagado");
      myflag=0;
    }
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Current humidity = ");
  Serial.print(h);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(t);
  Serial.println("C  ");
}
