#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
 
} 

void loop()
{
  Serial.println();

  int chk = dht.read(DHTPIN);

  float t = dht.readTemperature();
  Serial.print(t);
  
  float h = dht.readHumidity();
  Serial.print(h);

  delay(2000);

}
