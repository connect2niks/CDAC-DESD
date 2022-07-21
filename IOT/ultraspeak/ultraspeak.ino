#include "ThingSpeak.h"
#include "WiFi.h"
  
//----------- Enter you Wi-Fi Details---------//
char ssid[] = "AndroidAP174A"; //SSID
char pass[] = "umeshp285"; // Password
//-------------------------------------------//

const int trigger = 5;//16;
const int echo = 18;//5;
long T;
float distanceCM;
WiFiClient  client;

unsigned long myChannelField =  1142831; // Channel ID
const int ChannelField = 5; // Which channel to write data
const char * myWriteAPIKey = "AI0B2OH6EYV7UDHI"; // Your write API Key

void setup()
{
  Serial.begin(115200);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}
void loop()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
  }
  
  digitalWrite(trigger, LOW);
  delay(1);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  T = pulseIn(echo, HIGH);
  distanceCM = T * 0.034;
  distanceCM = distanceCM / 2;
  Serial.print("Distance in cm: ");
  Serial.println(distanceCM);
  ThingSpeak.writeField(myChannelField, ChannelField, distanceCM, myWriteAPIKey);
  delay(1000);
}
