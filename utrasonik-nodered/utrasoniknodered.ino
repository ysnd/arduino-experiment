#define trigPin 13
#define echoPin 12

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
  
  // Baca sinyal pantulan
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034) / 2; // Menghitung jarak dalam cm
  if (distance >=50) {
    distance = 50;
  }
  Serial.println(distance);
  // Kirim jarak ke serial
  
  
  // Tunggu 1 detik sebelum pengukuran berikutnya
  delay(1000);
}
