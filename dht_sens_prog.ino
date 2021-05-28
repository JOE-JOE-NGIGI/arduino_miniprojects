#include <DHT.h> // include dht library

#define DHTPIN 8 // dht is  connected to digital pin8

#define DHTTYPE DHT22  // Define the type of DHT sensor used

#define led_red_PIN 4

#define led_blue_PIN 12

#define buzzer 9

#define threshTemp 30

//create an object dht of type DHT with parameters DHTPIN and DHTTYPE
DHT dht(DHTPIN, DHTTYPE); 

void setup() {
  
  Serial.begin(9600); //open serial monitor at baudrate 9600
  Serial.println("DHT 22 Data collection!");
  dht.begin(); //initiate the dht sensor
 
  pinMode(led_red_PIN, OUTPUT);
  pinMode(led_blue_PIN, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  }

void loop () {
  //wait 2 seconds between measurements
   delay(2000); 
  float tmp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(tmp) || isnan(hum)) {
    Serial.println("Read Failed!");
    return;
    }

    else {

        Serial.print(tmp);
        Serial.print( "  *C ");
        Serial.print(hum);
        Serial.print(" %");
        delay(1000);

        if (tmp > threshTemp) {
          
            digitalWrite(led_red_PIN, HIGH);
            tone(buzzer,1000,200);
            digitalWrite(led_blue_PIN, LOW);
            
            } 
        else if(tmp < threshTemp) {
          
            digitalWrite(led_red_PIN, LOW);
            noTone(buzzer);
            digitalWrite(led_blue_PIN, HIGH);
          }    
      }
  
  }
