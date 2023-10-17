#include <WiFi.h>
#include "ThingSpeak.h"
#define RXp2 16
#define TXp2 17

const char* ssid = "Shubham's Galaxy M51";   // your network SSID (name) 
const char* password = "1234@abcd";   // your network password

WiFiClient  client;

unsigned long myChannelNumber = 2090500;
const char * myWriteAPIKey = "3KVO07AK8FYSIW8Q";
const int FieldNumberTurbidity=1;

String tur="";

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
  WiFi.mode(WIFI_STA);   
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}

void loop() {
    // Connect or reconnect to WiFi
    if(WiFi.status() != WL_CONNECTED){
      Serial.print("Attempting to connect");
      while(WiFi.status() != WL_CONNECTED){
        WiFi.begin(ssid, password); 
        delay(5000);     
      } 
      Serial.println("\nConnected.");
    }
      Serial.println("Tuyr: "+Serial2.readString());
      ThingSpeak.writeField(myChannelNumber,FieldNumberTurbidity,Serial2.readString(),myWriteAPIKey);

}
