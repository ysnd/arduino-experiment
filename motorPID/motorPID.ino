const int potPin = A0;
const int pwmPin = 5;
const int in1 = 6;
const int in2 = 7;
const byte encoderPin = 2;

volatile unsigned long pulseCount = 0;
const int pulsesPerRevolution = 20;
unsigned long lastPulseTime = 0;
const unsigned long debounceTime = 2;


float Kp = 0.6;
float Ki = 0.1;
float Kd = 0.05;
float setpoint = 0;
float input = 0;
float output = 0;
float lastInput = 0;
float integral = 0;

unsigned long previousMillis = 0;
const unsigned long interval = 100; // 100 ms
const float deltaT = interval / 1000.0; // in seconds

const int filterSamples = 5;
float rpmBuffer[filterSamples];
int bufIndex = 0;

const int minPWM = 50;
const float I_max = 100;
const float I_min = -100;

void encoderISR() {
  if (millis() - lastPulseTime >= debounceTime) {
    pulseCount++;
    lastPulseTime = millis();
  }
}

void setup() {
  pinMode(pwmPin, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(encoderPin, INPUT_PULLUP);

  digitalWrite(in1, HIGH); 
  digitalWrite(in2, LOW);

  attachInterrupt(digitalPinToInterrupt(encoderPin), encoderISR, RISING);

  for (int i = 0; i < filterSamples; i++) rpmBuffer[i] = 0;

  Serial.begin(115200);
  Serial.println("Setpoint,ActualRPM,PWM,P,I,D");
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    noInterrupts();
    unsigned long pulses = pulseCount;
    pulseCount = 0;
    interrupts();

    float rawRPM = (pulses * 60000.0) / pulsesPerRevolution / interval;
    
    rpmBuffer[bufIndex] = rawRPM;
    bufIndex = (bufIndex + 1) % filterSamples;

    float filteredRPM = 0;
    for (int i = 0; i < filterSamples; i++) filteredRPM += rpmBuffer[i];
    input = filteredRPM / filterSamples;

    int potValue = analogRead(potPin);
    setpoint = map(potValue, 0, 1023, 0, 500); // RPM max

    if (setpoint <= 0) {
      output = 0;
      integral = 0;
      analogWrite(pwmPin, 0);
      Serial.println("0,0,0,0,0,0");
      return;
    }

    float error = setpoint - input;

    float P = Kp * error;

    integral += error * deltaT;
    integral = constrain(integral, I_min, I_max);
    float I = Ki * integral;

    float derivative = (input - lastInput) / deltaT;
    float D = -Kd * derivative;

    output = P + I + D;

    float feedforward = map(setpoint, 0, 500, 0, 120); // 120 PWM @ 500 RPM
    output += feedforward;

    output = constrain(output, 0, 255);
    if (output > 0 && output < minPWM) output = minPWM;

    analogWrite(pwmPin, (int)output);

    lastInput = input;

    static int stuckCount = 0;
    if (input < 10 && output > minPWM) {
      if (++stuckCount > 5) {
        analogWrite(pwmPin, 0);
        Serial.println("ALERT: Motor stuck! Shutting down");
        delay(1000);
        stuckCount = 0;
      }
    } else stuckCount = 0;

    Serial.print(setpoint); Serial.print(",");
    Serial.print(input); Serial.print(",");
    Serial.print(output); Serial.print(",");
    Serial.print(P); Serial.print(",");
    Serial.print(I); Serial.print(",");
    Serial.println(D);
  }
}
