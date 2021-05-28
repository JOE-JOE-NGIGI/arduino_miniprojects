#include <SPI.h>
#include <Ethernet.h>
int pinLED = 13;
byte mac_address[] = {0xDE,0xAD,0XBE,0xEF,0xEF,0xED};
EthernetServer server(80); 
String readString;
void setup(){
  Serial.begin(9600);
  pinMode(pinLED,OUTPUT);
  Ethernet.begin(mac_address);
  server.begin();
  Serial.print("Server is at ");
  Serial.println(Ethernet.localIP());
  }
void loop(){
  EthernetClient client = server.available();
  if(client){
    while(client.connected()){
      if(client.available()){
        char ch = client.read();
        Serial.print(ch);
        if(readString.length() < 100){
          readString += ch;
          }
          // new line char for every request
          if(ch == '\n'){
            Serial.print(readString);
            client.println("<HTTP/1.1 200 OK>");
            client.print("<Connection-Type: text/html>");
            client.println("<Connection: close>");
            client.println("");
            client.println("<!DOCTYPE html>");
            client.println("<html>");
            client.println("<head>");
            client.println("<title>Webserver</title>");
            client.println("</head>");
            client.println("<body>");
            client.println("<a href=\"/?button1on\"\"><button>LED ON</button></a>");
            client.println("<a href=\"/?button2off\"\"><button>LED OFF</button></a>");
            client.println("<body style=background-color:powerblue>");
            delay(1);
            client.stop();
            if(readString.indexOf("?button1on")>0){
              digitalWrite(pinLED,HIGH);
              }
            if(readString.indexOf("?button2off")>0){
              digitalWrite(pinLED,LOW);
              }
            readString = "";
            client.println("</body>");
            client.println("</html>");
            }
        }
      }
    }
  }
