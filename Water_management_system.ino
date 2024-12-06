#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  
const int waterlevel = A0;
int level = 0;
float sensor_val_turbidity = 0;
int red = 2;
int motor = 3;
int green = 4;
int white = 5;
 
void setup() {
  
  pinMode(red,OUTPUT);
  pinMode(motor,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(white,OUTPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  
}

void loop() {
  level = analogRead(waterlevel);
  sensor_val_turbidity = analogRead(A1);
  Serial.print("Water level sensor = ");
  Serial.println(level);
  //Serial.print("\n");
  Serial.print("Turbidity sensor = ");
  Serial.println(sensor_val_turbidity);
  Serial.print("\n");

  if (level<300){
    digitalWrite(red,HIGH);
    digitalWrite(motor,HIGH);
    digitalWrite(green ,LOW);
    digitalWrite(white,HIGH);
    delay(1000);
  }
  else if(level>590){
    digitalWrite(red,LOW);
    digitalWrite(white,LOW);
    digitalWrite(green ,HIGH);
    digitalWrite(motor,LOW);
    delay(1000);
  }
  else{
    delay(1000);
    digitalWrite(green ,LOW);
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  if (sensor_val_turbidity < 100){
    lcd.print("Water is clean");
  }
  else{
    lcd.print("Water is dirty");
  }
  delay(1000);

}
