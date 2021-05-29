#include <ESP8266TimerInterrupt.h>
#include <ESP8266_ISR_Timer.h>
#include <ArduinoJson.h>
#include <Firebase.h>
#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiGratuitous.h>
#include <ESP8266WiFiMulti.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiUdp.h>

#define FIREBASE_HOST "distance_measurement-80111.firebaseio.com"
#define WIFI_SSID "YOUR WIFI NAME"
#define WIFI_PASSWORD "YOUR WIFI PASSWORD"

const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

void setup() {
  
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
Serial.begin(115200); 
  
Serial.print("Connecting to ");
Serial.println(WIFI_SSID);
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
}
// Print local IP address and start web server
Serial.println("");
Serial.println("WiFi connected.");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
Firebase.begin(FIREBASE_HOST);  
  
}

void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
  
Firebase.setInt ("Distance",distance);
delay(200);
