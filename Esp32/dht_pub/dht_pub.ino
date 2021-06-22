#include "DHT.h"
#include <WiFi.h>
#include <PubSubClient.h>

int packet_no;
int id;
DHT dht(2,DHT22);
WiFiClient espClient;
PubSubClient client(espClient);

void reconnectmqttserver() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP32Client-";
     clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

char msgmqtt[100];
void callback(char* topic, byte* payload, unsigned int length) {
  String MQTT_DATA = "";
  for (int i=0;i<length;i++) {
    MQTT_DATA += (char)payload[i];
  }
}

void setup() {
  Serial.begin(9600);
  packet_no = 0;
  id = 11;
  dht.begin();

  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
  WiFi.begin("Laptop","12345678");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("..");
  }
  Serial.println("Connected");
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP()));
  client.setServer("192.168.1.105", 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnectmqttserver();
  }
  client.loop();
  snprintf (msgmqtt, 100, 
            "{\"id\": %d, \"packet_no\": %d, \"tempurature\": %f, \"humidity\": %f}",
            id, packet_no, dht.readTemperature(), dht.readHumidity());
  client.publish("test", msgmqtt);
  packet_no = packet_no + 1;
  delay(5000);
}
