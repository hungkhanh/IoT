#include "DHT.h"

DHT dht2(2,DHT22);

void setup()
{
  Serial.begin(9600);
  dht2.begin();
}


void loop()
{
    
    delay(2000);
    Serial.print("Temperature: ");
    Serial.print(dht2.readTemperature());
    Serial.print("Humidity: ");
    Serial.println(dht2.readHumidity());
}
