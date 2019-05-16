#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
#define BTN  2

MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
#define BTNNUM  1
//定义按键数组{pin,当前状态,上次状态}
int btn[BTNNUM][3] = {
  {2, 0, 0},
};
boolean run;
int mp3;

const int ledPin = 3;
const int ledPin2 = 4; 
const int ledPin3 = 5;         
//const int buttonPin = 2;
//int buttonState = 0; 


void setup() {

  pinMode(BTN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  Wire.begin();
  mpu.initialize();
  if (!mpu.testConnection()) {
    while (1);
  }
  Serial.begin(115200);


}


//  pinMode(ledPin, OUTPUT);    //initialize the LED pin as an output
//  pinMode(buttonPin, INPUT);  //initialize the pushbutton pin as an output
//   }
 


void loop() {
 
// buttonState = digitalRead(buttonPin);
//    if (buttonState == HIGH) {    
//    digitalWrite(ledPin, LOW);         //turn LED on    
//    Serial.println("LED ON +++++++"); 
//  }
//  else {
 
//    digitalWrite(ledPin, HIGH);          // turn LED off
    //Serial.println("LED OFF -------");



  
  int key = key_scan();
  if (key)
  {
    run = !run;
    mp3 = run;
    digitalWrite(LED_BUILTIN, run);
  }
  digitalWrite(ledPin, run?HIGH:LOW);
  digitalWrite(ledPin2, run?HIGH:LOW);
  digitalWrite(ledPin3, run?HIGH:LOW);
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  int vx = map(ax, -16000, 16000, 90, -90);
  int vy = map(ay, -16000, 16000, 90, -90);
  if (run)
  {
    Serial.print(angleToDistance(vx));
    Serial.print(',');
    Serial.print(angleToDistance(vy));
    Serial.print(',');
    Serial.println(mp3);
    mp3 = 2;
  }
  delay(20);
}

int angleToDistance(int a) {
 
  if (a < -80) {
    return -40;
  }
  else if (a < -65) {
    return -20;
  }
  else if (a < -50) {
    return -10;
  }
  else if (a < -15) {
    return -5;
  }
  else if (a < -5) {
    return -1;
  }
  else if (a > 80) {
    return 40;
  }
  else if (a > 65) {
    return 20;
  }
  else if (a > 15) {
    return 10;
  }
  else if (a > 5) {
    return 1;
  }
  else {
    return 0;
  }
}
//按键扫描函数
int key_scan()
{
  //定义返回值key
  int key = 0;
  //循环读取所有按键
  for (int i = 0; i < BTNNUM; i++)
  { //更新当前状态到数组
    btn[i][1] = digitalRead(btn[i][0]);
    //按键按下
    if (btn[i][1] == LOW)
    {

      digitalWrite(ledPin, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      
      //去抖动
      delay(10);
      //按键按下
      if (digitalRead(btn[i][0] == LOW))
      { //判断上次状态防止循环触发
        if (btn[i][1] != btn[i][2])
        { //识别按键赋值给key跳出循环
          key = btn[i][0];
          btn[i][2] = btn[i][1];
          break;
        }
        //更新最后状态
        btn[i][2] = btn[i][1];
      }
    }
    //更新最后状态
    btn[i][2] = btn[i][1];
  }
  //返回key值 无按键为0
  return key;


}

 
 
