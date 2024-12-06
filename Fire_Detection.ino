
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include<SoftwareSerial.h>
#include "DHT.h"
SoftwareSerial Bluetooth(10, 11); 




LiquidCrystal_I2C lcd(0x27,16, 2);
#define DHTPIN 8
#define DHTTYPE DHT22
int flamePin = 7;
int buzzer = 6;
int red = 12;
int motor = 2;
int swt = 4;
int count=0;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
pinMode(flamePin, INPUT);
pinMode(swt, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(red, OUTPUT);
Serial.begin(9600);
pinMode(motor, OUTPUT);
lcd.init();
lcd.backlight();
Bluetooth.begin(9600);
pinMode(10, INPUT);
pinMode(11, OUTPUT);
Serial.println(F("DHTxx test!"));

dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
float t = dht.readTemperature();
int flame = digitalRead(flamePin);
int switc = digitalRead(swt);
Serial.println(flame);
Serial.println(count);

if (switc == 0){
if (flame == 0){
  if (count>5){
    Bluetooth.print("Fire in the hole!!!!!!!!");
    Bluetooth.print(";");
  }
  //float t = dht.readTemperature();
  if (t>26.20){
  analogWrite(buzzer, HIGH);
  digitalWrite(motor, LOW);
  digitalWrite(red, HIGH);
  delay(1500);
  
  
  }

  else if (t>25.80){
  analogWrite(buzzer, HIGH);
  digitalWrite(motor, LOW);
  digitalWrite(red, HIGH);
  delay(1000);
  
    
  }
  analogWrite(buzzer, HIGH);
  digitalWrite(motor, LOW);
  digitalWrite(red, HIGH);
  delay(500);
  
//  digitalWrite(motor, LOW);
//  delay(1000);
  digitalWrite(motor, HIGH);
  delay(1000);
  count=count+1;
}
else{
  analogWrite(buzzer, LOW);
  digitalWrite(red, LOW);
  digitalWrite(motor, HIGH);
  delay(1000);
  count=0;
  
  
}
}
else{
  analogWrite(buzzer, LOW);
  digitalWrite(red, LOW);
  digitalWrite(motor, HIGH);
  delay(1000);
  count=0;

}

//
//  // Reading temperature or humidity takes about 250 milliseconds!
//  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
//  float h = dht.readHumidity();
//  // Read temperature as Celsius (the default)
//  float t = dht.readTemperature();
//  // Read temperature as Fahrenheit (isFahrenheit = true)
//  float f = dht.readTemperature(true);
//
//  // Check if any reads failed and exit early (to try again).
//  if (isnan(h) || isnan(t) || isnan(f)) {
//    Serial.println(F("Failed to read from DHT sensor!"));
//    return;
//  }
//
//  // Compute heat index in Fahrenheit (the default)
//  float hif = dht.computeHeatIndex(f, h);
//  // Compute heat index in Celsius (isFahreheit = false)
//  float hic = dht.computeHeatIndex(t, h, false);
//
//  if t>26.20{
//  analogWrite(buzzer, HIGH);
//  digitalWrite(motor, LOW);
//  digitalWrite(red, HIGH);
//  delay(1000);
//  Bluetooth.print("High level fire!!");
//  Bluetooth.print(";");
//  }
//
//  else if t>25.80{
//  analogWrite(buzzer, HIGH);
//  digitalWrite(motor, LOW);
//  digitalWrite(red, HIGH);
//  delay(500);
//  Bluetooth.print("Medium level fire!!");
//  Bluetooth.print(";");
//    
//  }
//  digitalWrite(motor, HIGH);
//  delay(1000);
//  
//
//  Serial.print(F("Humidity: "));
//  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));
//  Serial.print(f);
//  Serial.print(F("°F  Heat index: "));
//  Serial.print(hic);
//  Serial.print(F("°C "));
//  Serial.print(hif);
//  Serial.println(F("°F"));
}
