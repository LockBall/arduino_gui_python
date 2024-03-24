
#include <Arduino.h>
#include <config.h>

unsigned long previous_millis = 0;  // will store last time LED was updated
bool state_13 = 0;
int incomingByte = 0;

void setup() {  // the setup function runs once when you press reset or power the board
    pinMode(LED_BUILTIN, OUTPUT) ;
    Serial.begin(baud) ;
    Serial.setTimeout(100) ; // msec
}

void loop() {

    if (Serial.available() > 0) {  // read the incoming byte:
        incomingByte = Serial.parseInt();

        if (debug == 1) {
            Serial.print("I received: ");
            Serial.println(incomingByte);
        }
    }


    switch (incomingByte) {

        case 13:
            //Serial.print("case 13");
            state_13 = !state_13;
            digitalWrite(LED_BUILTIN, state_13);
            incomingByte = 0;
            break;
        
        default:
            break;
        
    }


    if (heartbeat == 1){  // BEGIN optional heartbeat LED
        unsigned long current_millis = millis();

        if (current_millis - previous_millis >= interval) {
            previous_millis = current_millis;  // save the last time you blinked the LED
            state_13 = !state_13 ;  // alternate LED_state
            digitalWrite(LED_BUILTIN, state_13) ;
            //Serial.print(current_millis);
        }
    }  // END hearbeat LED


}  // void loop()
