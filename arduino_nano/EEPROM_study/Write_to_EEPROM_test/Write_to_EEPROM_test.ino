#include <EEPROM.h>

int address = 0;  //set up variable for address of EEPROM
int bottonpin = 13; // define pin for digital read
byte value;        // variable to store 8 bits
int counter;       //variable for counting age


void setup() {

  for(int x = 2; x < 6; x++){     //set up digital pin 2 to 5 to output
  	pinMode(x, OUTPUT);
  }

   pinMode(bottonpin, INPUT);    //set up button pin to input

   Serial.begin(9600);
   while (!Serial) {
   ;                         // wait for serial port to connect
   }
}



void loop() {

	counter = EEPROM.read(5);  // Read from address 5 and store it to variable counter

	for(int index = 0; index < 4; index++){     //for loop for each addresses
		value = EEPROM.read(index);              // read
		digitalWrite(index + 2, value);          // and output to digital pins
		Serial.print(value);                     // print the value to serial monitor
	}

	Serial.print("\t");
	Serial.print(counter);                       //print age
	Serial.println();


	int bottonVal = digitalRead(bottonpin);      //read from digital input
	EEPROM.update(address, bottonVal);           //update the value for the address of this cycle


	address = address + 1;                      //advance address

	if (address == 4) {                         //condition for reseting address
		address = 0;
	}

	counter++;                                  //advance counter
    EEPROM.write(5, counter);                   //write to counter

	



	delay(3000);

}