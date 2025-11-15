// Array pin untuk kolom (9 kolom, LED anoda)
int colPins[9] = {
  2, 3, 4,   // Baris 0 (belakang)
  5, 6, 7,   // Baris 1 (tengah)
  8, 9, 10   // Baris 2 (depan)
};

// Array pin untuk layer (katoda, lewat transistor NPN)
int layerPins[3] = {
  11, 12, 13 // Layer bawah, tengah, atas
};

void setup() {
  // Set semua kolom sebagai output
  for (int i = 0; i < 9; i++) {
    pinMode(colPins[i], OUTPUT);
    digitalWrite(colPins[i], LOW); // default: mati
  }

  // Set semua layer sebagai output
  for (int i = 0; i < 3; i++) {
    pinMode(layerPins[i], OUTPUT);
    digitalWrite(layerPins[i], HIGH); // HIGH = transistor off
  }
}

void loop() {
  // -------------------------
  // Layer 0: Bawah
  digitalWrite(layerPins[0], LOW); // aktifkan layer 0

  digitalWrite(colPins[0], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[1], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[2], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[3], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[4], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[5], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[6], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[7], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[8], HIGH); delay(100); turnOffAll();

  digitalWrite(layerPins[0], HIGH); // matikan layer

  // -------------------------
  // Layer 1: Tengah
  digitalWrite(layerPins[1], LOW); // aktifkan layer 1

  digitalWrite(colPins[0], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[1], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[2], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[3], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[4], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[5], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[6], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[7], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[8], HIGH); delay(100); turnOffAll();

  digitalWrite(layerPins[1], HIGH); // matikan layer

  // -------------------------
  // Layer 2: Atas
  digitalWrite(layerPins[2], LOW); // aktifkan layer 2

  digitalWrite(colPins[0], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[1], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[2], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[3], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[4], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[5], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[6], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[7], HIGH); delay(100); turnOffAll();
  digitalWrite(colPins[8], HIGH); delay(100); turnOffAll();

  digitalWrite(layerPins[2], HIGH); // matikan layer
}

// -------------------------
// Fungsi untuk mematikan semua LED
void turnOffAll() {
  // Matikan semua kolom
  for (int i = 0; i < 9; i++) {
    digitalWrite(colPins[i], LOW);
  }

  // Matikan semua layer (transistor NPN = OFF)
  for (int i = 0; i < 3; i++) {
    digitalWrite(layerPins[i], HIGH); // HIGH = transistor OFF
  }
}
