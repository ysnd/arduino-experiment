#include <TaskScheduler.h>

const int irPin = 2;
const int ledPin = 3;

Scheduler runner;

// Task declarations
void readIRSensor();
void checkSerial();

// Define tasks
Task taskReadIR(50, TASK_FOREVER, &readIRSensor); // Baca sensor IR setiap 500ms
Task taskCheckSerial(50, TASK_FOREVER, &checkSerial); // Cek serial input setiap 50ms

void setup() {
  pinMode(irPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Inisialisasi komunikasi serial
  
  // Add tasks to the scheduler
  runner.init();
  runner.addTask(taskReadIR);
  runner.addTask(taskCheckSerial);
  
  // Enable tasks
  taskReadIR.enable();
  taskCheckSerial.enable();
}

void loop() {
  runner.execute();
}

void readIRSensor() {
  int irState = digitalRead(irPin);
  Serial.println(irState); // Kirim status sensor IR ke Raspberry Pi
}

void checkSerial() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == '1') {
      // Nyalakan LED
      digitalWrite(ledPin, HIGH);
    } else if (command == '0') {
      // Matikan LED
      digitalWrite(ledPin, LOW);
    }
  }
}
