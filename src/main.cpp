
#include <Arduino.h>
#include <config.h>

unsigned long previous_millis = 0 ;  // store time of last LED update
int incomingByte = 0 ;
int dig_pins_out_vals[end_dig_pin + 1] = {};  // each pin # val will be at that index # in the array

void setup() {  // the setup function runs once when you press reset or power the board
    
    for (int i = 0; i <= num_dig_pins_out; i++) {  // set pins to output mode
        pinMode(dig_pins_out[i], OUTPUT) ;
    
        dig_pins_out_vals[dig_pins_out[i]] = 0 ; // set output pins vals
        digitalWrite(dig_pins_out[i], dig_pins_out_vals[dig_pins_out[i]]); // write output pins to 0. pin_#, value
    }

    Serial.begin(baud) ;
    Serial.setTimeout(100) ; // msec
}


void loop() {

    if (Serial.available() > 0) {  // read incoming byte, an int that is the pin number
        incomingByte = Serial.parseInt();


        if (incomingByte >= start_dig_pin && incomingByte <= end_dig_pin) {
            Serial.print(dig_pins_out_vals[incomingByte]);
            // toggle the value of the pin
            dig_pins_out_vals[incomingByte] = !dig_pins_out_vals[incomingByte];
            digitalWrite(incomingByte, dig_pins_out_vals[incomingByte]); // pin, value
            Serial.print(dig_pins_out_vals[incomingByte]);
        }

        if (debug == 1) {
            Serial.print("\n I received: ");
            Serial.println(incomingByte);

            Serial.print("\n dig_pins_out_vals: ");
            for (int i = 0; i <= end_dig_pin; i++) {
                Serial.print(dig_pins_out_vals[i]) ;
            }     
        }

    }


    if (heartbeat == 1) {  // BEGIN optional heartbeat LED
        unsigned long current_millis = millis();

        if (current_millis - previous_millis >= interval) {
            previous_millis = current_millis;  // save the last time you blinked the LED
            dig_pins_out_vals[board_LED_pin] = !dig_pins_out_vals[board_LED_pin] ;
            digitalWrite(board_LED_pin, dig_pins_out_vals[board_LED_pin]) ;
            //Serial.print(current_millis);
        }
    }  // END hearbeat LED


}  // void loop()