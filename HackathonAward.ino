
#include <Servo.h>
Servo servoX;
Servo servoY;  

int pos = 0;
int msDelay = 55;


void setup() {
  servoX.attach(10);  
  servoY.attach(9);  
}

void loop() {
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

