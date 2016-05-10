
#include <Servo.h>
Servo servoX;
Servo servoY;  

int pos = 0;

const int PhotoBottomPin = A0;
const int PhotoRightPin = A1;
const int PhotoLeftPin = A2;
const int LED_R_Pin = 3;
const int LED_G_Pin = 5;
const int LED_B_Pin = 6;

int msDelay = 55;
int PhotoBottom = 0;
int PhotoRight = 0;
int PhotoLeft = 0;
int xDiff = 0;
int yDiff = 0;
int servoXPos = 90;
int servoYPos = 45;

void setup() {
  servoX.attach(10);  
  servoY.attach(9);  
  servoY.write(servoYPos);
  servoX.write(servoXPos);
  //Serial.begin(9600);
  pinMode(LED_R_Pin, OUTPUT);
  pinMode(LED_G_Pin, OUTPUT);
  pinMode(LED_B_Pin, OUTPUT);
  turnOnOne(LED_R_Pin);
  delay(1000);
}

void loop() {
  getPhotoValues();
  //serialOut();
  xDiff = PhotoRight - PhotoLeft;
  constrainedXupdate(xDiff);
    
  if(PhotoLeft >= PhotoRight)
  {
    yDiff = PhotoBottom - PhotoLeft;
    constrainedYupdate(yDiff);
    turnOnOne(LED_G_Pin);
  }else{
    yDiff = PhotoBottom - PhotoRight;
    constrainedYupdate(yDiff);
    turnOnOne(LED_B_Pin);
  }
  
}

void turnOnOne(int led)
{
  //turn off all
  digitalWrite(LED_R_Pin, LOW);
  digitalWrite(LED_G_Pin, LOW);
  digitalWrite(LED_B_Pin, LOW);
  //turn on the one
  digitalWrite(led, HIGH);
}

void serialOut()
{
  Serial.println(PhotoLeft);
  Serial.println(PhotoRight);
  Serial.println(PhotoBottom);
  Serial.println("=====");
}

void constrainedXupdate(int byThisMuch)
{
  servoXPos = servoXPos + byThisMuch;
  servoXPos = constrain(servoXPos, 1, 178);
  servoX.write(servoXPos);
}

void constrainedYupdate(int byThisMuch)
{
  servoYPos = servoYPos + byThisMuch;
  servoYPos = constrain(servoYPos, 10, 140);
  servoY.write(servoYPos);
}

void getPhotoValues(){
  delay(30);// delay in between reads for stability
  PhotoBottom = analogRead(PhotoBottomPin);
  PhotoRight = analogRead(PhotoRightPin);
  PhotoLeft = analogRead(PhotoLeftPin);
  //re-calibrate
  PhotoLeft = map(PhotoLeft, 0, 500, 0, 90);
  PhotoRight = map(PhotoRight, 0, 500, 0, 90);
  PhotoBottom = map(PhotoBottom, 0, 500, 0, 90);
}




