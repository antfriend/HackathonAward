
#include <Servo.h>
Servo servoX;
Servo servoY;  

int pos = 0;

const int PhotoBottomPin = A0;
const int PhotoRightPin = A1;
const int PhotoLeftPin = A2;

int msDelay = 55;
int PhotoBottom = 0;
int PhotoRight = 0;
int PhotoLeft = 0;
int xDiff = 0;
int yDiff = 0;
int servoXPos = 0;
int servoYPos = 0;

void setup() {
  servoX.attach(10);  
  servoY.attach(9);  
}

void loop() {
  getLEDvalues();
  //servoXPos = map(sensorValue, 0, 1023, 0, 180);
  
  if(PhotoLeft >= PhotoRight)
  {
    xDiff = PhotoLeft - PhotoRight;
    servoXPos = 90 + xDiff;
    servoX.write(servoXPos);
    
  }else{
    xDiff = PhotoRight - PhotoLeft;
    servoXPos = 90 - xDiff;
    servoX.write(servoXPos);
    
  }
}

void getLEDvalues(){
  delay(10);// delay in between reads for stability
  PhotoBottom = analogRead(PhotoBottomPin);
  PhotoRight = analogRead(PhotoRightPin);
  PhotoLeft = analogRead(PhotoLeftPin);
}

void movementTestLoop()
{
  for (pos = 0; pos <= 180; pos += 1) { 
    // in steps of 1 degree
    servoX.write(pos);     
    servoY.write(pos);    
    delay(msDelay);                    
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    servoX.write(pos);     
    servoY.write(pos);             
    delay(msDelay);             
  }
}



