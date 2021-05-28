//IR motion sensor
//middle pin-ground,right vcc,left GND

//Connect to digital pin 8

int pirPin = 8;//Define Pir pin
int pinLED = 13; //Define LED Pin

void setup() {
  Serial.begin(9600);
  pinMode(pirPin,INPUT);
  pintMode(pinLED, OUTPUT);
  }

void loop() {
  //
    int sensorValue = digitalRead(pirPin); //read data from the digital pin connected to pir sensor
    if(sensorValue == HIGH) {
    //Serial.println("Motion detected");
    digitalWrite(pinLED,HIGH); //switch on LED if there is motion
    delay(500);
  }
  else if (sensorValue == LOW) {
    //Serial.println("No Motion");
    digitalWrite(pinLED, LOW);
    delay(500);
    }
  }
