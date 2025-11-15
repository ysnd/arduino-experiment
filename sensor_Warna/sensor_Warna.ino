#include <Wire.h>
#include "Adafruit_TCS34725.h"

// Inisialisasi sensor dengan nilai integrasi dan gain
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {
  Serial.begin(9600);
  
  if (tcs.begin()) {
    Serial.println("Sensor TCS34725 terdeteksi.");
  } else {
    Serial.println("Sensor TCS34725 tidak terdeteksi. Periksa koneksi Anda.");
    while (1); // Berhenti jika sensor tidak terdeteksi
  }
}

void loop() {
  uint16_t r, g, b, c;
  
  // Membaca nilai dari sensor
  tcs.getRawData(&r, &g, &b, &c);
  
  // Menampilkan nilai di Serial Monitor
  Serial.print("R: "); Serial.print(r, DEC);
  Serial.print(" G: "); Serial.print(g, DEC);
  Serial.print(" B: "); Serial.print(b, DEC);
  Serial.print(" C: "); Serial.print(c, DEC);
  Serial.println();
  
  // Tunggu 1 detik sebelum membaca kembali
  delay(1000);
}
