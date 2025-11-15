#include <LiquidCrystal.h>

const int rs=10, en = 9, d4=8, d5=7, d6=6, d7=5;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int VPin=A0;
float Suhu, VD, Vo=0.0;

void setup() {
lcd.begin(16,2);
delay(100);
lcd.clear();
Serial.begin(9600);
}

void loop() {
int sensorValue = analogRead(VPin); 
float Vo = sensorValue * (5.0 / 1023.0); 
float suhu = (Vo - 0.0361) / 0.0489; 
lcd.setCursor(0,0);
lcd.print("VDigital= ");
lcd.setCursor(12,0);
lcd.print(Vo);
lcd.setCursor(0,1);
lcd.print("Suhu = ");
lcd.setCursor(12,1);
lcd.print(Suhu,1);
delay(100);
}
