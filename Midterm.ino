#include <Servo.h>
Servo servo1;

int DO = 2; //Pin for Digital Output - DO
int DA = A0; // Pin for Analog Output - AO
int threshold = 351; //Set minimum threshold for LED lit
int sensorvalue = 0;
int sensorDigValue = 0;
int digThreshold = 1;
int pos = 0;
int servoValue = 0;
int servoCnt=0;
int servoFlag=false;
int servoThreshold = 100;

void lightUp() {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    
    int lightValue = analogRead(A1);
    lightValue%=1024;
    Serial.println(servoValue);
    servoValue = map (lightValue, 0, 1024, 0, 180);
    if(!servoFlag){
      servo1.write(servoValue);
      servoFlag = true;
    } else if (++servoCnt>=servoThreshold){
      servoCnt=0;
      servoFlag = true;
    }
    delay(1000);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
//  pinMode(2, INPUT);
//  pinMode(A0, INPUT);
  servo1.attach(13);
  Serial.println("SERVO TEST BEGIN");
  for (pos = 0; pos < 180; pos += 45) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(200);                       // waits 15ms for the servo to reach the position
    Serial.println("servo moving +30 = ");
  }
  for (pos = 180; pos >= 0; pos -= 45) { // goes from 180 degrees to 0 degrees
    servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(200);                       // waits 15ms for the servo to reach the position
    Serial.println("servo moving -30 = ");
  }
  Serial.println("SERVO TEST FINISHED");
  attachInterrupt(digitalPinToInterrupt(2), lightUp, HIGH); 
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);

    int lightValue = analogRead(A1);
    lightValue%=1024;
    Serial.println(servoValue);
    servoValue = map (lightValue, 0, 1024, 0, 180);
    if(!servoFlag){
      servo1.write(servoValue);
    } else if (++servoCnt>=servoThreshold){
      servoCnt=0;
      servoFlag = false;
    }
}
