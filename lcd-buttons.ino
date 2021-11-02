
/************************************************
 * My Name when button1 is Pressed
 * RIT Vizag when button2 is Pressed
 * IEEE Vizag Bay Section when button3 is Pressed
 *************************************************/
#include <LiquidCrystal.h>

int button1=18;
int button2=5;
int button3=36;

int LCD_RS=23;
int LCD_EN=15;
int LCD_D4=25;
int LCD_D5=26;
int LCD_D6=27;
int LCD_D7=14;

// create an object
LiquidCrystal lcd(LCD_RS,LCD_EN,LCD_D4,LCD_D5,LCD_D6,LCD_D7);
 
void setup() {
 lcd.begin(16,2); // 16 - cols, 2 - rows
 pinMode(button1,INPUT_PULLUP);
 pinMode(button2,INPUT_PULLUP);
 pinMode(button3,INPUT_PULLUP);
}

void loop() {
 if(digitalRead(button1)==0) {
  lcd.clear();
  lcd.print("MADDY");
 } else if(digitalRead(button2)==0) {
  lcd.clear();
  lcd.print("RIT Vizag");
 } else if(digitalRead(button3)==0) {
  lcd.clear();
  lcd.print("IEEE Vizag Bay Section");
 }
}
