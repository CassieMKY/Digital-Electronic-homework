import processing.serial.*;
Serial port;
int x, y;

import ddf.minim.*;
Minim echo_minim;
AudioPlayer echo_player;
PImage pic;

float frameCount = 430;
float cloud = 0;
float star1 = 20;
float star2 = 600;
float star3 = 150;
float ySpeed = 3;
float ySpeed2 = 5;
float ySpeed3 = 1.5;
PImage img;


void setup() {
   
  size(1600, 1000, P2D);
  port = new Serial(this, Serial.list()[1], 115200);
  pic=loadImage("spacecraft.png");
  
  echo_minim = new Minim(this);
  echo_player = echo_minim.loadFile("1.mp3");
  echo_player.loop();
  
}

void draw() {
 background(#3E35C4);
  if (port.available() > 0 ) 
  {

    String rec=port.readStringUntil('\n');
    if (rec!=null) {
      if (rec.indexOf(",")!=-1) {
        String xx=rec.split(",")[0];
        String yy=rec.split(",")[1].trim();
        String zz=rec.split(",")[2].trim();
        if(zz=="1"){
          echo_minim=new Minim(this);
          echo_player=echo_minim.loadFile("1.mp3");
          echo_player.play();
        }else if (zz == "0"){
          //echo_player.stop();
        }
        x+=Integer.parseInt(xx);
        y-=Integer.parseInt(yy);
        if (x<0)x=0;
        if (x>width)x=width;
        if (y<0)y=0;
        if (y>height)y=height;
      }
    }
  }
  
  
  stroke(255);
  strokeWeight(2);
  fill(#000000);

  triangle(532,612,630,800,430,800);
  triangle(1000,100,1200,-200,1400,100);

  ellipse(300,300,300,300);
  ellipse(1300,630,700,700);
  
  strokeWeight(2);
  ellipse(730,130,130,130);//r
  
  image(pic,x,y);
  ellipse(300,130,130,30);
  ellipse(13,700,500,500);
  
  ellipse(900,330,80,80);
  
  
  
  strokeWeight(1);
  //rotate
  pushMatrix();
  translate(13, 700);
  rotate(radians(frameCount));
  ellipse(0,0,500,200);
  popMatrix();
  
  strokeWeight(1);
  //rotate
  pushMatrix();
  translate(730, 130);
  rotate(radians(frameCount));
  ellipse(0,0,65,130);
  popMatrix();
  
  strokeWeight(1);
  //rotate
  pushMatrix();
  translate(1300,630);
  rotate(radians(frameCount));
  ellipse(0,0,700,350);
  popMatrix();
  
  strokeWeight(2);
  line(300,300,300,60);
  line(800,1000,1000,300);
 
  rect(1200,star1,13,13,3);//1000,20
  rect(360,star2,9,9,3);//360,600
  rect(60,star3,13,13,3);//60,150
  
  
  
  star1 = star1 + ySpeed;
  if (star1 > height){
    ySpeed = -3;
  }
  if (star1 < 0) {
    ySpeed = 3;
  }
  
  star2 = star2 + ySpeed2;
  if (star2 > height){
    ySpeed2 = -5;
  }
  if (star2 < 0) {
    ySpeed2 = 5;
  }
  
   star3 = star3 + ySpeed3;
  if (star3 > height){
    ySpeed3 = -1.5;
  }
  if (star3 < 0) {
    ySpeed3 = 1.5;
  }
  
  
  line(800,1000,1000,300);
  fill(#FFFA58);
  noStroke();
  //rotate
  //pushMatrix();
  //translate(300, 300);
  //rotate(radians(frameCount));
  ellipse(300,300,300,60);
  //popMatrix();
  
  strokeWeight(1);
  fill(#000000);
  stroke(255);
  
  ellipseMode(CENTER);
  
  fill(random(255));
  
  noStroke();
  ellipse(frameCount,230,230,36);//460
  frameCount = frameCount + 1;
    if (frameCount > 1300){
    frameCount = 30;
  }
  

  fill(random(255));
  ellipse(cloud,600,300,13);//130
  cloud = cloud + 6;
  
  if (cloud > 1300){
    cloud = 30;
  }
}  




  
  //saveFrame("hw1.jpg");
