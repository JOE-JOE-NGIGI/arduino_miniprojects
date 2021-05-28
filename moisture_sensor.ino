//No need to include any libraries
//define a pin
//ardunio measures upto a max of 1024
//to scale down, map() function is used

int pin_sensor = A0;

void setup() {

  Serial.begin(9600);
  
  
}

void loop (){
  
  int sensorValue = analogRead(pin_sensor);
  sensorValue = map(sensorValue, 0,1023,0,100);
  Serial.println(sensorValue);
  delay(1000);
  }
