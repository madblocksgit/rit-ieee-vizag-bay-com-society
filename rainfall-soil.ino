/********************************************
 * Reading Data from Soil Moisture and Rainfall Sensor
 ********************************************/

int soil=34;
int rainfall=39;

void setup() {
  pinMode(soil,INPUT);
  pinMode(rainfall,INPUT);
  Serial.begin(9600);
}

void loop() {
 Serial.print("Soil: ");
 int s=map(analogRead(soil),0,4095,100,0);
 Serial.print(s);
 Serial.print(",Rainfall: ");
 int r=map(analogRead(rainfall),0,4095,100,0);
 Serial.print(r);  
 delay(2000);
}
