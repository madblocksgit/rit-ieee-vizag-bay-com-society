
/************************************************
 * Toggle all the LEDs (LED1 to LED4) 
 ***********************************************/

int led1=13;
int led2=12;
int led3=19;
int led4=32;

void setup() { // hardware configuration
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
}

void loop() { // logic

  digitalWrite(led1,1);
  digitalWrite(led2,1);
  digitalWrite(led3,1);
  digitalWrite(led4,1);  
  delay(100);
  digitalWrite(led1,0);
  digitalWrite(led2,0);
  digitalWrite(led3,0);
  digitalWrite(led4,0);
  delay(100); // 100ms
}
