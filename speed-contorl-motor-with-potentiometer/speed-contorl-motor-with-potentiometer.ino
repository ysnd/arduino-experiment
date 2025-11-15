const int potPin = A0;
const int pwmPin = 5;
const int in1 = 6;
const int in2 = 7;
const byte encoderPin = 2;    
volatile unsigned int pulseCount = 0;
unsigned long previousMillis = 0;
const unsigned long interval = 1000; 
const int pulsesPerRevolution = 20; 

void encoderISR() {
  pulseCount++;
}

void setup() {
  pinMode(pwmPin, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(encoderPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderPin), encoderISR, RISING);
  
  // Motor maju
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    noInterrupts(); 
    unsigned int pulses = pulseCount;
    pulseCount = 0;
    interrupts();

    // Hitung RPM
    float rpm = (pulses * 60.0) / pulsesPerRevolution;

    Serial.print("RPM: ");
    Serial.println(rpm);

    previousMillis = currentMillis;
  }

  // Baca potensiometer (0–1023)
  int potValue = analogRead(potPin);

  // Ubah ke nilai PWM (0–255)
  int pwmValue = map(potValue, 0, 1023, 0, 255);

  // Kirim ke motor
  analogWrite(pwmPin, pwmValue);

  // Tampilkan ke serial monitor
  Serial.print("Potensio: ");
  Serial.print(potValue);
  Serial.print("  PWM: ");
  Serial.println(pwmValue);

  delay(1000);
}
