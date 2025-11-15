#include <LiquidCrystal.h>

const int rs=10, en = 9, d4=8, d5=7, d6=6, d7=5;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int Va_pin=A0;
int Va=0;//variabel untuk menyimpan nilai digital
float Sudut,Van;

void setup() {
lcd.begin(16,2);
delay(100);
lcd.clear();
Serial.begin(9600);
}

void loop() {
Va = analogRead(Va_pin);
delay(200);
Van=Va/1023.0*5.0;
Sudut = -13.774 * pow(Van, 3) + 191.54 * pow(Van, 2) - 942.28 * Van + 1640.5;

lcd.setCursor(0,0);
lcd.print("Van= ");
lcd.setCursor(12,0);
lcd.print(Van);
lcd.setCursor(0,1);
lcd.print("Sudut = ");
lcd.setCursor(12,1);
lcd.print(Sudut,0);
lcd.setCursor(15,1);
lcd.print((char)223);
delay(100);
}
