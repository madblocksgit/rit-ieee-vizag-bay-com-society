/*********************************************************
 * LoRa Receiver program
 * Id,Hum,Temp,Soil Moisture and Rainfall
 ********************************************************/
#include "Arduino.h"
#include "LoRa_E32.h"
#include <LiquidCrystal.h>

int LCD_RS=23;
int LCD_EN=15;
int LCD_D4=25;
int LCD_D5=26;
int LCD_D6=27;
int LCD_D7=14;

int M0=22;
int M1=21;
int AUX=33;

struct myData {
  int id;
  int temp;
  int hum;
  int sm;
  int rf;
};

// create objects
LiquidCrystal lcd(LCD_RS,LCD_EN,LCD_D4,LCD_D5,LCD_D6,LCD_D7);
LoRa_E32 e32(&Serial2,M0,M1,AUX);

void setup() {
  
 lcd.begin(16,2);
 Serial.begin(9600);
 e32.begin();
}

void loop() {

  if(e32.available()>1) {
    ResponseStructContainer rc=e32.receiveMessage(sizeof(myData));
    if(rc.status.code!=1) {
      Serial.println(rc.status.getReponseDescription());
    } else {
      lcd.clear();
      lcd.print("Data Received");
      delay(1000);

      struct myData rit=*(myData*)rc.data;
      lcd.clear();
      if(rit.id==1) {
        lcd.print("Hum: ");
        lcd.print(rit.hum);
        lcd.setCursor(8,0);
        lcd.print("Temp: ");
        lcd.print(rit.temp);
        lcd.setCursor(0,1);
        lcd.print("Soil: ");
        lcd.print(rit.sm);
        lcd.setCursor(8,1);
        lcd.print("Rain: ");
        lcd.print(rit.rf);
        Serial.print("Hum: ");
        Serial.print(rit.hum);
        Serial.print(",Temp: ");
        Serial.print(rit.temp);
        Serial.print(",Soil: ");
        Serial.print(rit.sm);
        Serial.print("Rain: ");
        Serial.print(rit.rf);
        delay(2000);
      }
    }
  }
}
