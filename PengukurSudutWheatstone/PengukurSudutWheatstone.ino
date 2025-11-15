#include <LiquidCrystal.h>

const int rs=10, en = 9, d4=8, d5=7, d6=6, d7=5;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int VoPin=A0;
int Va=0,Vb=0;//variabel untuk menyimpan nilai deigital
float Sudut, Vaan, Vban, Vab;

void setup() {
lcd.begin(16,2);
delay(100);
lcd.clear();
Serial.begin(9600);
}

void loop() {
Va = analogRead(V0Pin);

delay(200);
Vaan=Va/1023.0*5.0;
Vban=Vb/1023.0*5.0;
Vab=Vaan-Vban;
Sudut = 2.8465 * pow(Vab, 4) - 27.5 * pow(Vab, 3) + 106.88 * pow(Vab, 2) - 230.65 * Vab + 247.52;
lcd.setCursor(0,0);
lcd.print("Vab= ");
lcd.setCursor(12,0);
lcd.print(Vab);
lcd.setCursor(0,1);
lcd.print("Sudut = ");
lcd.setCursor(12,1);
lcd.print(Sudut,0);
lcd.setCursor(15,1);
lcd.print((char)223);
delay(100);
}
