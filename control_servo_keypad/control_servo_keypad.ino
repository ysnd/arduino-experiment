#include <Servo.h>
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2};
Servo serpo;
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
byte ledPin = 13; 
int pos = 0;
boolean blink = false;
boolean ledPin_state;

void setup(){
    Serial.begin(9600);
    serpo.attach(10);
    pinMode(ledPin, OUTPUT);              // Sets the digital pin as output.
    digitalWrite(ledPin, HIGH);           // Turn the LED on.
    ledPin_state = digitalRead(ledPin);   // Store initial LED state. HIGH when LED is on.
    keypad.addEventListener(keypadEvent); // Add an event listener for this keypad
}

void loop(){
    char key = keypad.getKey();

    if (key) {
        Serial.println(key);
    }
    if (blink){
        digitalWrite(ledPin,!digitalRead(ledPin));    // Change the ledPin from Hi2Lo or Lo2Hi.
        delay(100);
    }
}

// Taking care of some special events.
void keypadEvent(KeypadEvent key){
    switch (keypad.getState()){
    case PRESSED:
        if (key == '9') {
            for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    serpo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);  
        }
        break;

    case RELEASED:
        if (key == '*') {
            digitalWrite(ledPin,ledPin_state);    // Restore LED state from before it started blinking.
            blink = false;
        }
        break;

    case HOLD:
        if (key == '*') {
            blink = true;    // Blink the LED when holding the * key.
        }
        break;
    }
}
}
