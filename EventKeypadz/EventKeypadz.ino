#include <Keypad.h>
#include <Servo.h>
int pos=0;
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


void setup(){
    Serial.begin(9600);
    keypad.addEventListener(keypadEvent); // Add an event listener for this keypad
    Serial.println("clear");
    serpo.attach(10);
    serpo.write(pos);  
    Serial.println(pos);  
}

void loop(){
    char key = keypad.getKey();

    if (key) {
        Serial.println(key);
    }
}

// Taking care of some special events.
void keypadEvent(KeypadEvent key){
    switch (keypad.getState()){
    case PRESSED:
        if (key == '#') {

        }
        break;

    case RELEASED:
    while (key == '*' && pos < 180) {
    pos;
    serpo.write(pos);
    Serial.println(pos);
    delay(15);
        }
        break;

    case HOLD:
        while (key == '*' && pos < 180) {
    pos++;
    serpo.write(pos);
    Serial.println(pos);
    delay(15);
        }
        break;
    }
}
