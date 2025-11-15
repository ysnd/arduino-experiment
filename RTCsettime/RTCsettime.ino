#include <RtcDS1302.h>
#define DS1302_CLK 5
#define DS1302_DAT 4
#define DS1302_RST 2

#define LED_PIN 8

ThreeWire myWire(DS1302_DAT, DS1302_CLK, DS1302_RST);
RtcDS1302<ThreeWire> Rtc(myWire);

void setup() {
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);

    Rtc.Begin();
    RtcDateTime newTime(2025, 3, 28, 11, 49, 0);
    Rtc.SetDateTime(newTime);
    Serial.println("Waktu diatur! Silakan hapus baris ini setelah sekali upload.");
}

void loop() {
    RtcDateTime now = Rtc.GetDateTime();
    Serial.print("Waktu RTC: ");
    printDateTime(now);
    Serial.println();
    
    int jam = now.Hour();
    
    if (jam >= 18 || jam < 6) {  
        digitalWrite(LED_PIN, HIGH); 
    } else {
        digitalWrite(LED_PIN, LOW); 
    }

    delay(1000);
}

void printDateTime(const RtcDateTime &dt) {
    char datestring[20];
    snprintf_P(datestring, sizeof(datestring),
               PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
               dt.Month(), dt.Day(), dt.Year(), dt.Hour(), dt.Minute(), dt.Second());
    Serial.print(datestring);
}
