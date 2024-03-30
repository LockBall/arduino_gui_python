
const int start_dig_pin = 2 ;
const int end_dig_pin = 13 ;
const int num_dig_pins = end_dig_pin - start_dig_pin + 1 ;  // nano, 12 pins, 2 → 13
//const int dig_pins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 ,13} ;

const int dig_pins_out[] = {13} ;
const int num_dig_pins_out = sizeof(dig_pins_out) / sizeof(dig_pins_out[0]) ;

const int dig_pins_in[] = {} ;
const int num_dig_pins_in = sizeof(dig_pins_in) / sizeof(dig_pins_in[0]) ;

const int board_LED_pin = 13 ;

const long baud = 115200 ;

bool debug = 1;

bool heartbeat = 0;
const long interval = 1000;  // interval at which to blink (milliseconds)

