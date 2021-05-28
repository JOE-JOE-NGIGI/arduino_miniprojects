#include <Servo.h>

//create object of type servo
Servo myservo; 

int pinServo = 9; //signal pin of the servo

void setup(){
    //attach pin number where servo is connected
    myservo.attach(pinServo); //attach is a function of servo 
}

void loop(){
    //incrementing the angle from 
    for(int pos = 0; pos <=180; pos++) 
    {

      myservo.write(pos);
      delay(20);
      
    }

    for(int pos = 180; pos >= 0; pos--) 
    {

      myservo.write(pos);
      delay(20);
      
    }
    
}
