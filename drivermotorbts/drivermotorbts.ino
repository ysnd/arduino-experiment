
const int RPWM = 3; 
const int LPWM = 5; 

void setup() {
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);
}

void loop() {
  analogWrite(RPWM, 128); 
  analogWrite(LPWM, 0);   
  delay(2000);

  analogWrite(RPWM, 0);
  analogWrite(LPWM, 0);
  delay(1000);

  analogWrite(RPWM, 0);
  analogWrite(LPWM, 192); 
  delay(2000);

  analogWrite(RPWM, 0);
  analogWrite(LPWM, 0);
  delay(1000);
}
