/*******************************************************
 * Button1 - Pressed - make all leds on
 * Button2 - Pressed - make buzzer on
 * Button3 - Pressed - switch of all leds and buzzer
 ********************************************************/
 
int button1=18;
int button2=5;
int button3=36;

int led1=13;
int led2=12;
int led3=19;
int led4=32;

int buzzer=4;

void setup() {

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);

  pinMode(button1,INPUT_PULLUP);
  pinMode(button2,INPUT_PULLUP);
  pinMode(button3,INPUT_PULLUP);

  pinMode(buzzer,OUTPUT);
}

void loop() {

  if(digitalRead(button1)==0) {
    digitalWrite(led1,1);
    digitalWrite(led2,1);
    digitalWrite(led3,1);
    digitalWrite(led4,1);
  }
  if(digitalRead(button2)==0) {
    digitalWrite(buzzer,1);
  }
  if(digitalRead(button3)==0) {
    digitalWrite(led1,0);
    digitalWrite(led2,0);
    digitalWrite(led3,0);
    digitalWrite(led4,0);
    digitalWrite(buzzer,0);
  }
}
