#include <EEPROM.h>

int address = 0;
int bottonpin = 13;
byte value;
int counter;




void setup() {

  for(int x = 2; x < 6; x++){
  	pinMode(x, OUTPUT);
  }

   pinMode(bottonpin, INPUT);

   Serial.begin(9600);
   while (!Serial) {
   ; // wait for serial port to connect. Needed for native USB port only
   }

   counter = EEPROM.read(5);

}



void loop() {

	for(int index = 0; index < 4; index++){
		value = EEPROM.read(index);
		digitalWrite(index + 2, value);
		Serial.print(value);
	}

	Serial.print("\t");
	Serial.print(counter);
	Serial.println();


	int bottonVal = digitalRead(bottonpin);
	EEPROM.update(address, bottonVal);


	address = address + 1;

	if (address == 4) {
		address = 0;
	}

	counter++;
    EEPROM.write(5, counter);

	



	delay(3000);

}