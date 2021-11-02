/*****************************************
 * To transmit this data to the receiver
 * Hum, Temp, Soil Mositure, Rainfall
 *****************************************/

#include "Arduino.h"
#include "LoRa_E32.h"
#include "DHT.h"
#include <LiquidCrystal.h>

int LCD_RS=23;
int LCD_EN=15;
int LCD_D4=25;
int LCD_D5=26;
int LCD_D6=27;
int LCD_D7=14;

int dht_pin=2;

int rainfall=39;
int soil=34;

int M0=22;
int M1=21;
int AUX=33;

// create objects
LiquidCrystal lcd(LCD_RS,LCD_EN,LCD_D4,LCD_D5,LCD_D6,LCD_D7);
DHT dht(2,DHT11);

LoRa_E32 e32(&Serial2,M0,M1,AUX);

struct myData {
  int id;
  int temp;
  int hum;
  int sm;
  int rf;
};

myData data;

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);

  dht.begin();
  e32.begin();
  pinMode(soil,INPUT);
  pinMode(rainfall,INPUT);
}

void loop() {

  int temp=dht.readTemperature();
  int hum=dht.readHumidity();
  if(isnan(hum) || isnan(temp)) {
    return;
  }
  data.id=1; // 8-boxes (4 pairs) - 1,2,3,4
  data.temp=temp;
  data.hum=hum;

  int s=map(analogRead(soil),0,4095,100,0);
  int r=map(analogRead(rainfall),0,4095,100,0);

  data.sm=s;
  data.rf=r;
  lcd.clear();
  lcd.print("Hum: ");
  lcd.print(data.hum);
  lcd.setCursor(8,0);
  lcd.print("Temp: ");
  lcd.print(data.temp);
  lcd.setCursor(0,1);
  lcd.print("SM: ");
  lcd.print(data.sm);
  lcd.setCursor(8,1);
  lcd.print(data.rf);
  delay(2000);
  ResponseStatus rs=e32.sendMessage(&data,sizeof(data));
  Serial.println(rs.getResponseDescription());
  delay(1000);
  lcd.clear();
  lcd.print("Data Sent");
}
