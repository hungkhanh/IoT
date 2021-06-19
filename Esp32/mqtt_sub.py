#Simple MQTT Subscribe
import paho.mqtt.client as paho
import json
import sys

topic = "test"
ip_host = "192.168.1.105"

def on_message(client, userdata, msg):
    data = json.loads(msg.payload.decode())
    print(msg.topic + ": ")
    print(f"id: {data.get('id')}")
    print(f"packet_no: {data.get('packet_no')}")
    print(f"tempurature: {data.get('tempurature')}")
    print(f"humidity: {data.get('humidity')}")
    print(f"pH: {data.get('pH')}")

client = paho.Client()
client.on_message = on_message

if client.connect(ip_host, 1883, 60) != 0:
    print("Error connect MQTT Broker :(")
    sys.exit(-1)

client.subscribe(topic)

try:
    print("Press Ctrl + C to exit...")
    client.loop_forever()
except:
    print("Disconnecting from broker")
client.disconnect()