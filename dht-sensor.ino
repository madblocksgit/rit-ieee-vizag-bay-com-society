/*************************************
 * Reading Data from DHT11 Sensor
 * Humidity and Temperature
 ************************************/

#include "DHT.h"

int dht_pin=2;

// create an object
DHT dht(2,DHT11);
 
void setup() {
  Serial.begin(9600); 
  dht.begin();
}

void loop() {

 float hum=dht.readHumidity();
 float temp=dht.readTemperature();
 
 if(isnan(hum) || isnan(temp)) {
  return;
 }
 
 Serial.print("Hum: ");
 Serial.print(hum);
 Serial.print(", Temp: ");
 Serial.println(temp);
 delay(2000); // 2 seconds
}
