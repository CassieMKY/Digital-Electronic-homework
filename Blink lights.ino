int outPutPin = 8;
int outPutPin2 =13;
int outPutPin3 =7;

void setup() {

  pinMode(outPutPin, OUTPUT);
}


void loop() {
  digitalWrite(outPutPin, HIGH);  
  delay(1000);                      
  digitalWrite(outPutPin, LOW);   
  delay(50);                      
  
  digitalWrite(outPutPin2, HIGH);
  delay(600);                       
  digitalWrite(outPutPin2, LOW);   
  delay(50);

digitalWrite(outPutPin3, HIGH);
  delay(1000);                       
  digitalWrite(outPutPin3, LOW);   
  delay(50);
  
}
