#include <OneWire.h>
#include <DallasTemperature.h>

// Pin untuk koneksi OneWire
const int oneWirePin = 13;

// Inisialisasi objek OneWire
OneWire oneWire(oneWirePin);

// Inisialisasi objek DallasTemperature
DallasTemperature sensors(&oneWire);

void setup() {
  // Mulai komunikasi serial
  Serial.begin(9600);

  // Inisialisasi sensor
  sensors.begin();
}

void loop() {
  // Mendapatkan data suhu
  sensors.requestTemperatures();

  // Mendapatkan suhu dalam Celcius
  float temperatureC = sensors.getTempCByIndex(0);

  // Mendapatkan suhu dalam Fahrenheit
  float temperatureF = sensors.getTempFByIndex(0);

  // Menampilkan suhu ke Serial Monitor
  Serial.print("Suhu (C): ");
  Serial.print(temperatureC);
  Serial.print("   Suhu (F): ");
  Serial.println(temperatureF);

  // Tunggu 1 detik sebelum membaca suhu lagi
  delay(1000);
}
