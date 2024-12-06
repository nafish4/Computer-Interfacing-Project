
int pirPin = 3; //the digital pin connected to the PIR sensor's output
bool force = false;
bool motion = false;
int output = 4;

#include<SoftwareSerial.h>
SoftwareSerial Bluetooth(10, 11); 

void setup(void) {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  digitalWrite(pirPin, LOW);
  pinMode(5, OUTPUT);
  Bluetooth.begin(9600);
  }

void loop(void) {
  int sensorValue = analogRead(A0);
  int pir = digitalRead(pirPin);         
  int switc = digitalRead(2);
  
  if (sensorValue > 50 && force == false){ 
  force = true;
  
  }
  if (motion == false && pir == 1){
    motion = true;
  }
  if(switc == 0){
    if(force == true || motion == true){
      digitalWrite(5,1);
      delay(1000);
      Bluetooth.print("Invasion!");
      Bluetooth.print(";");
   
    }
    
  }
  else{
      force = false;
      motion = false;
      digitalWrite(5,0);
      delay( 1000);
      Bluetooth.print("All good!");
  Bluetooth.print(";");
    }
  Serial.println(sensorValue);
  Serial.println(force);
  Serial.println("-----------");
  Serial.println(pir);
  Serial.println(motion);
  Serial.println("-----------");
  Serial.println(switc);
  delay(1000);
  
    
}
