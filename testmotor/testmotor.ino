#include <Arduino.h>
const int RPWML = 9;  
const int LPWML = 10;  
const int RPWMR = 5;  
const int LPWMR = 6;  


String motorState = "stop";


void setup() {
  pinMode(RPWML, OUTPUT);
  pinMode(LPWML, OUTPUT);
  pinMode(RPWMR, OUTPUT);
  pinMode(LPWMR, OUTPUT);
  Serial.begin(9600); 
  Serial.println("Ready to receive commands: maju, mundur, stop, kanan, kiri");
}

// Fungsi loop utama
void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim(); 
    if (command == "maju") {
      maju();
      motorState = "maju";
    } else if (command == "mundur") {
      mundur();
      motorState = "mundur";
    } else if (command == "stop") {
      stop();
      motorState = "stop";
    } else if (command == "kanan") {
      kanan();
      motorState = "kanan";
    } else if (command == "kiri") {
      kiri();
      motorState = "kiri";
    }
    Serial.println("Motor state: " + motorState);
  }
}

void maju() {
  analogWrite(RPWMR, 70);
  analogWrite(LPWMR, 0);
  analogWrite(RPWML, 70);
  analogWrite(LPWML, 0);
  Serial.print("maju");
}

void mundur() {
  analogWrite(RPWMR, 0);
  analogWrite(LPWMR, 70);
  analogWrite(RPWML, 0);
  analogWrite(LPWML, 70);
  Serial.print("mundur");
}

void stop() {
  analogWrite(RPWMR, 0);
  analogWrite(LPWMR, 0);
  analogWrite(RPWML, 0);
  analogWrite(LPWML, 0);
  Serial.print("stop");
}

  analogWrite(RPWMR, 50); 
  analogWrite(LPWMR, 0); 
  analogWrite(RPWML, 0); 
  analogWrite(LPWML, 50);  
  Serial.print("kanan");  
}

void kiri() {
  analogWrite(RPWMR, 0); 
  analogWrite(LPWMR, 50); 
  analogWrite(RPWML, 50); 
  analogWrite(LPWML, 0);  
  Serial.print("kiri");
}
