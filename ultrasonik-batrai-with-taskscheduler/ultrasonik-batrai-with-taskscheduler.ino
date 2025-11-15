#include <TaskScheduler.h>

// Deklarasi pin
#define trigPin 11
#define echoPin 10
const int analogPin = A0;  // Pin ADC
float vIn = 0.0;           // Tegangan input

long duration;
float distance;

// Membuat scheduler
Scheduler ts;

// Deklarasi tugas
void measureDistance();
void readVoltage();
void sendData();

Task t1(1000, TASK_FOREVER, &measureDistance, &ts, true);
Task t2(1000, TASK_FOREVER, &readVoltage, &ts, true);
Task t3(1000, TASK_FOREVER, &sendData, &ts, true);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600); // Inisialisasi komunikasi serial
}

void loop() {
  ts.execute();
}

// Fungsi untuk mengukur jarak
void measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034) / 2; // Menghitung jarak dalam cm
  if (distance > 50) {
    distance = 50;
  }
}

// Fungsi untuk membaca tegangan
void readVoltage() {
  int adcValue = analogRead(analogPin);
  vIn = (adcValue * 5.0) / 1024.0; // Mengkonversi nilai ADC ke tegangan
}

// Fungsi untuk mengirim data
void sendData() {
  Serial.print(distance);
  Serial.print(",");
  Serial.println(vIn);
}
