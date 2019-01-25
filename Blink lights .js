int outPutPin = 8;
int outPutPin2 =13;

void setup() {
  pinMode(outPutPin, OUTPUT);
}


void loop() {
  digitalWrite(outPutPin, HIGH);   
  delay(1000);                      
  digitalWrite(outPutPin, LOW);   
  delay(50);                       
  
  digitalWrite(outPutPin2, HIGH);
  delay(300);                       
  digitalWrite(outPutPin2, LOW);   
  delay(50);
}
