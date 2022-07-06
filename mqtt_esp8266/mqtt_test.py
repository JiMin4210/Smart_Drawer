import sys
import paho.mqtt.client as mqtt
subtopic = "#"
pubtopic0 = "xy"
pubtopic1 = "deviceid/JiMin/evt/humidity"
server = "jmk.local"

def on_connect(client, userdata, flags, rc):
    print("Connected with RC : " + str(rc))
    client.subscribe(subtopic)

def on_message(client, userdata, msg):
    print("sub : "+msg.topic+" "+msg.payload.decode('UTF-8'))

client = mqtt.Client()
client.connect(server, 1883, 60)
client.on_connect = on_connect
client.on_message = on_message

client.loop_start()

for line in sys.stdin:
    client.publish(pubtopic0, line.strip())
    #client.publish(pubtopic1, line.strip())
