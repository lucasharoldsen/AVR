

int dip1 = 6;
int dip2 = 5;
int dip3 = 4;
int dip4 = 3;
int dip5 = 2;

int ledB = 12;
int ledR = 11;
int ledY = 10;
int ledG = 7;


void setup() {

  for(int x = 2; x < 7; x++){
  	pinMode(x, INPUT);
  }

  pinMode(ledB, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);

  Serial.begin(9600);

  LEDcheck();


}

void loop() {

	int state1 = digitalRead(dip1);
	int state2 = digitalRead(dip2);
	int state3 = digitalRead(dip3);
	int state4 = digitalRead(dip4);
	int state5 = digitalRead(dip5);

	Serial.print(state1);
	Serial.print("\t");
	Serial.print(state2);
	Serial.print("\t");
	Serial.print(state3);
	Serial.print("\t");
	Serial.print(state4);
	Serial.print("\t");
	Serial.println(state5);
	

	

  

}



void LEDcheck(){
	digitalWrite(ledB, HIGH);
  	delay(100);
  	digitalWrite(ledB,LOW);
  	delay(100);
  	digitalWrite(ledR, HIGH);
  	delay(100);
  	digitalWrite(ledR,LOW);
  	delay(100);
  	digitalWrite(ledY, HIGH);
  	delay(100);
  	digitalWrite(ledY,LOW);
  	delay(100);
  	digitalWrite(ledG, HIGH);
  	delay(100);
  	digitalWrite(ledG,LOW);
  	delay(100);
  
}