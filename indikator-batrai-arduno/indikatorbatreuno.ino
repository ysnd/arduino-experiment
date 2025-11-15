const int analogPin = A0;  // Pin ADC
float vIn = 0.0;           // Tegangan input
float vMax = 4.2;          // Tegangan maksimum baterai 18650
float vMin = 3.0;          // Tegangan minimum baterai 18650

void setup() {
  Serial.begin(9600);
}

void loop() {
  int adcValue = analogRead(analogPin);
  vIn = (adcValue * 5.0) / 1024.0; // Mengkonversi nilai ADC ke tegangan

  // Menghitung persentase baterai
  float batteryPercentage = ((vIn - vMin) / (vMax - vMin)) * 100.0;
  
  // Batasan antara 0% hingga 100%
  if (batteryPercentage > 100) {
    batteryPercentage = 100;
  } else if (batteryPercentage < 0) {
    batteryPercentage = 0;
  }

  Serial.print("Tegangan Baterai: ");
  Serial.print(vIn);
  Serial.print(" V, Persentase: ");
  Serial.print(batteryPercentage);
  Serial.print(" %, AdcValue : ");
  Serial.println(adcValue);


  delay(1000); // Update setiap 1 detik
}
