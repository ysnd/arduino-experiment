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
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

String msg;


void setup() {
    Serial.begin(9600);
    Serial.println("clear");
    serpo.attach(0);
    serpo.write(pos);  
    Serial.print(pos);  
}


void loop() {
  char key = kpd.getKey();
    if (kpd.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( kpd.key[i].stateChanged )   // Only find keys that have changed state.
            {
                switch (kpd.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                    msg = " PRESSED.";
                break;
                    case HOLD:
                    msg = " HOLD.";
                break;
                    case RELEASED:
                    msg = " RELEASED.";
                break;
                    case IDLE:
                    msg = " IDLE.";
                }
                Serial.print("Key ");
                Serial.print(kpd.key[i].kchar);
                Serial.println(msg);
            }
    } 
    }
{
  if (kpd.key[0].kstate == HOLD && kpd.key[0].kchar == ('9') && pos < 180 ) {
    pos +=2;
    serpo.write(pos);
    Serial.println(pos);
    delay(15);
  }
 else if (kpd.key[0].kstate == HOLD &&  kpd.key[0].kchar == ('7') && pos > 0) {
    pos -=2;
    serpo.write(pos);
    Serial.println(pos);
    delay(15);
  }
  else if (kpd.isPressed ('0')){
   pos=90;
   serpo.write(pos);
   Serial.println("posisi reset");
   delay(15);
  }
}
  } // End loop
