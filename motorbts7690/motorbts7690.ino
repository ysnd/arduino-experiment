// Definisikan pin yang digunakan
const int RPWML = 9;
const int LPWML = 10;

const int RPWMR = 5;
const int LPWMR = 6;

void setup() {
  // Atur pin sebagai output
  pinMode(RPWML, OUTPUT);
  pinMode(LPWML, OUTPUT);
  pinMode(RPWMR, OUTPUT);
  pinMode(LPWMR, OUTPUT);
}

void loop() {
  // Putar motor ke arah kanan dengan kecepatan 255
  analogWrite(RPWMR, 50);
  analogWrite(LPWMR, 0);
  analogWrite(RPWML, 50);
  analogWrite(LPWML, 0);
  delay(2000); // Putar selama 2 detik

  // Berhenti selama 1 detik
  analogWrite(RPWMR, 0);
  analogWrite(LPWMR, 0);
  analogWrite(RPWML, 0);
  analogWrite(LPWML, 0);
  delay(1000);

  // Putar motor ke arah kiri dengan kecepatan 255
  analogWrite(RPWMR, 0);
  analogWrite(LPWMR, 50);
  analogWrite(RPWML, 0);
  analogWrite(LPWML, 50);
  delay(2000); // Putar selama 2 detik

  // Berhenti selama 1 detik
  analogWrite(RPWMR, 0);
  analogWrite(LPWMR, 0);
  analogWrite(RPWML, 0);
  analogWrite(LPWML, 0);
  delay(1000);
}
