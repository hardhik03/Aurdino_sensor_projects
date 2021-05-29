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
  int chk = DHT.read11(DHT11_PIN);
  hum = DHT.humidity;
  temp= DHT.temperature;
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");
  delay(2000);

}
