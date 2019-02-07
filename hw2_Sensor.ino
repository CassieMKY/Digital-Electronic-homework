const int ledPin = 13;
const int ldrPin = A0;
const int ledPin2 = 10;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
pinMode(ldrPin, INPUT);
pinMode(ledPin2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
int ldrStatus = analogRead(ldrPin);

if (ldrStatus <= 400) {
  digitalWrite(ledPin,HIGH);
  digitalWrite(ledPin2,LOW);
  Serial.print("Its DARK, Turn on the LED : ");
  Serial.println(ldrStatus);
} else {
  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin2,HIGH);
  Serial.print("Its BRIGHT, Turn off the LED :");
  Serial.println(ldrStatus);
}

}
