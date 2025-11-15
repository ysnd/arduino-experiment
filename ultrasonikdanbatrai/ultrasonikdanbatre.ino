#define trigPin 2
#define echoPin 3
const int analogPin = A0;  // Pin ADC
float vIn = 0.0;           // Tegangan input


long duration;
float distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600); // Inisialisasi komunikasi serial
}

void loop() {
  // Kirim sinyal ultrasonik
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Baca nilai ADC dari pin analog
  int adcValue = analogRead(analogPin);
  vIn = (adcValue * 5.0) / 1024.0; // Mengkonversi nilai ADC ke tegangan

  // Baca sinyal pantulan
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034) / 2; // Menghitung jarak dalam cm
  if (distance > 50) {
    distance = 50;
  }
  
  // Kirim jarak dan tegangan baterai ke serial dalam satu baris dengan delimiter
  Serial.print(distance);
  Serial.print(",");
  Serial.println(vIn);
  
  // Tunggu 1 detik sebelum pengukuran berikutnya
  delay(1000);
}
