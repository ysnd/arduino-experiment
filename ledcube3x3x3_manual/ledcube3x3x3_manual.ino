// Kolom = anoda (horizontal, XY)
int kolom0 = 2;
int kolom1 = 3;
int kolom2 = 4;
int kolom3 = 5;
int kolom4 = 6;
int kolom5 = 7;
int kolom6 = 8;
int kolom7 = 9;
int kolom8 = 10;

// Layer = katoda (Z axis)
int layer0 = 11; // bawah
int layer1 = 12; // tengah
int layer2 = 13; // atas

void setup() {
  // Set semua kolom dan layer jadi OUTPUT
  pinMode(kolom0, OUTPUT);
  pinMode(kolom1, OUTPUT);
  pinMode(kolom2, OUTPUT);
  pinMode(kolom3, OUTPUT);
  pinMode(kolom4, OUTPUT);
  pinMode(kolom5, OUTPUT);
  pinMode(kolom6, OUTPUT);
  pinMode(kolom7, OUTPUT);
  pinMode(kolom8, OUTPUT);

  pinMode(layer0, OUTPUT);
  pinMode(layer1, OUTPUT);
  pinMode(layer2, OUTPUT);
}

void loop() {
  // LED 0: kolom0, layer0
  digitalWrite(kolom0, HIGH);
  digitalWrite(layer0, LOW);
  delay(300);
  matikanSemua();

  // LED 1: kolom1, layer0
  digitalWrite(kolom1, HIGH);
  digitalWrite(layer0, LOW);
  delay(300);
  matikanSemua();

  // LED 2
  digitalWrite(kolom2, HIGH);
  digitalWrite(layer0, LOW);
  delay(300);
  matikanSemua();

  // LED 3
  digitalWrite(kolom3, HIGH);
  digitalWrite(layer0, LOW);
  delay(300);
  matikanSemua();

  // LED 4
  digitalWrite(kolom4, HIGH);
  digitalWrite(layer0, LOW);
  delay(300);
  matikanSemua();

  // LED 5
  digitalWrite(kolom5, HIGH);
  digitalWrite(layer0, LOW);
  delay(300);
  matikanSemua();

  // LED 6
  digitalWrite(kolom6, HIGH);
  digitalWrite(layer0, LOW);
  delay(300);
  matikanSemua();

  // LED 7
  digitalWrite(kolom7, HIGH);
  digitalWrite(layer0, LOW);
  delay(300);
  matikanSemua();

  // LED 8
  digitalWrite(kolom8, HIGH);
  digitalWrite(layer0, LOW);
  delay(300);
  matikanSemua();

  // Sekarang naik ke layer tengah
  digitalWrite(kolom0, HIGH);
  digitalWrite(layer1, LOW);
  delay(300);
  matikanSemua();

  digitalWrite(kolom1, HIGH);
  digitalWrite(layer1, LOW);
  delay(300);
  matikanSemua();

  digitalWrite(kolom2, HIGH);
  digitalWrite(layer1, LOW);
  delay(300);
  matikanSemua();

  digitalWrite(kolom3, HIGH);
  digitalWrite(layer1, LOW);
  delay(300);
  matikanSemua();

  digitalWrite(kolom4, HIGH);
  digitalWrite(layer1, LOW);
  delay(300);
  matikanSemua();

  digitalWrite(kolom5, HIGH);
  digitalWrite(layer1, LOW);
  delay(300);
  matikanSemua();

  digitalWrite(kolom6, HIGH);
  digitalWrite(layer1, LOW);
  delay(300);
  matikanSemua();

  digitalWrite(kolom7, HIGH);
  digitalWrite(layer1, LOW);
  delay(300);
  matikanSemua();

  digitalWrite(kolom8, HIGH);
  digitalWrite(layer1, LOW);
  delay(300);
  matikanSemua();

  // Layer atas
  digitalWrite(kolom0, HIGH);
  digitalWrite(layer2, LOW);
  delay(300);
  matikanSemua();

  digitalWrite(kolom1, HIGH);
  digitalWrite(layer2, LOW);
  delay(300);
  matikanSemua();

  digitalWrite(kolom2, HIGH);
  digitalWrite(layer2, LOW);
  delay(300);
  matikanSemua();

  digitalWrite(kolom3, HIGH);
  digitalWrite(layer2, LOW);
  delay(300);
  matikanSemua();

  digitalWrite(kolom4, HIGH);
  digitalWrite(layer2, LOW);
  delay(300);
  matikanSemua();

  digitalWrite(kolom5, HIGH);
  digitalWrite(layer2, LOW);
  delay(300);
  matikanSemua();

  digitalWrite(kolom6, HIGH);
  digitalWrite(layer2, LOW);
  delay(300);
  matikanSemua();

  digitalWrite(kolom7, HIGH);
  digitalWrite(layer2, LOW);
  delay(300);
  matikanSemua();

  digitalWrite(kolom8, HIGH);
  digitalWrite(layer2, LOW);
  delay(300);
  matikanSemua();
}

void matikanSemua() {
  // Semua kolom mati
  digitalWrite(kolom0, LOW);
  digitalWrite(kolom1, LOW);
  digitalWrite(kolom2, LOW);
  digitalWrite(kolom3, LOW);
  digitalWrite(kolom4, LOW);
  digitalWrite(kolom5, LOW);
  digitalWrite(kolom6, LOW);
  digitalWrite(kolom7, LOW);
  digitalWrite(kolom8, LOW);

  // Semua layer mati (katoda = HIGH)
  digitalWrite(layer0, HIGH);
  digitalWrite(layer1, HIGH);
  digitalWrite(layer2, HIGH);
}
