#include <WiFi.h>
#include "ThingSpeak.h"

const char* ssid = "AndroidAP2734";   // your network SSID (name) 
const char* password = "man12345";   // your network password

WiFiClient  client;

unsigned long myChannelNumber = 1476402;
const char * myWriteAPIKey = "FQWXRH9LJDPKNP8A";

int led = 22;                // the pin that the LED is atteched to
int sensor = 12;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)

void setup() {
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
  WiFi.mode(WIFI_STA);   
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}

void loop(){
   // Connect or reconnect to WiFi
    if(WiFi.status() != WL_CONNECTED){
      Serial.print("Attempting to connect");
      while(WiFi.status() != WL_CONNECTED){
        WiFi.begin(ssid, password); 
        delay(5000);     
      } 
      Serial.println("\nConnected.");
    }
    
  val = digitalRead(sensor);   // read sensor value
  
  if (val == HIGH) {          // check if the sensor is HIGH
    Serial.print("PIR  sensor is ");
    Serial.println( val);
    digitalWrite(led, HIGH);   // turn LED ON
    delay(500);                // delay 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(led, LOW); // turn LED OFF
      delay(500);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.print("PIR sensor is ");
        Serial.println( val);
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
      int x = ThingSpeak.writeField(myChannelNumber, 1, val, myWriteAPIKey);

}
