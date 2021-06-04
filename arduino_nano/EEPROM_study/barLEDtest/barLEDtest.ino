
void setup() {
  for(int x = 2; x < 12; x++){
    
    pinMode(x, OUTPUT);
}
}

void loop() {
  
  
  for(int x = 2; x < 12; x++){
    digitalWrite(x, HIGH);
    delay(1000);
    digitalWrite(x,LOW);
    delay(1000);
    }

}