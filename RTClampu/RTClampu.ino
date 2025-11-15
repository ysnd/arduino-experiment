#include <RtcDS1302.h>

#define DS1302_CLK 5
#define DS1302_DAT 4
#define DS1302_RST 2
#define LED_PIN 13

ThreeWire myWire(DS1302_DAT, DS1302_CLK, DS1302_RST);
RtcDS1302<ThreeWire> Rtc(myWire);

void setup() {
    Serial.begin(9600);
    Rtc.Begin();

    if (!Rtc.IsDateTimeValid()) {
        Serial.println("RTC tidak valid, mungkin baterai habis atau belum diatur.");
    }
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    RtcDateTime now = Rtc.GetDateTime();
    Serial.print("Waktu RTC: ");
    printDateTime(now);
    // Koreksi logika waktu
    if (now.Hour() >= 18 || now.Hour() < 6) {
        digitalWrite(LED_PIN, HIGH);
        Serial.println(" -> LAMPU ON");
    } else {
        digitalWrite(LED_PIN, LOW);
        Serial.println(" -> LAMPU OFF");
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
