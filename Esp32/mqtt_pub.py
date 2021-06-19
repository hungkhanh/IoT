#Simple MQTT Publish
import paho.mqtt.client as paho
import json
import sys

topic = "test"
ip_host = "192.168.1.105"
client = paho.Client()

if client.connect(ip_host, 1883, 60) != 0:
    print("Error connect MQTT Broker")
    sys.exit(-1)

data = {"id":11, "packet_no":126, "temperature":30,
"humidity":60, "pH":5.0}

client.publish(topic,json.dumps(data),0)
print(json.dumps(data))
client.disconnect()