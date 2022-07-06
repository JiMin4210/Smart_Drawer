#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ConfigPortal8266.h>
#include <PubSubClient.h> // mqtt용 헤더
#include <SoftwareSerial.h>
#include <ssd1306.h>

const int RX = 13;
const int TX = 12;
SoftwareSerial swSer(RX,TX);

SSD1306 display(0x3c, 4, 5, GEOMETRY_128_32); // oled

WiFiClient espClient;
PubSubClient client(espClient);
void callback(char* topic, byte* payload, unsigned int length);

char*               ssid_pfix = (char*)"2017146010";
String              user_config_html = "<p><input type='text' name='mqtt'placeholder='MQTT_IP'>";      
/*
 *  ConfigPortal library to extend and implement the WiFi connected IOT device
 *
 *  Yoonseok Hur
 *
 *  Usage Scenario:
 *  0. copy the example template in the README.md
 *  1. Modify the ssid_pfix to help distinquish your Captive Portal SSID
 *          char   ssid_pfix[];
 *  2. Modify user_config_html to guide and get the user config data through the Captive Portal
 *          String user_config_html;
 *  2. declare the user config variable before setup
 *  3. In the setup(), read the cfg["meta"]["your field"] and assign to your config variable
 *
 */

void setup() {
    Serial.begin(115200);

    display.init(); // 처음 화면 초기화
    display.flipScreenVertically();
    display.setFont(ArialMT_Plain_16);
    display.drawString(0,0,"Captive Portal");
    display.drawString(0,14,"Start"); // 연결중임을 OLED에 표시
    display.display();

    loadConfig();
    // *** If no "config" is found or "config" is not "done", run configDevice ***
    if(!cfg.containsKey("config") || strcmp((const char*)cfg["config"], "done")) {
        configDevice();
    }
    WiFi.mode(WIFI_STA);
    WiFi.begin((const char*)cfg["ssid"], (const char*)cfg["w_pw"]);

    display.init();
    display.flipScreenVertically();
    display.setFont(ArialMT_Plain_16);
    display.drawString(0,0,(const char*)cfg["ssid"]);
    display.drawString(0,14,"connecting"); // 연결중임을 OLED에 표시
    display.display();

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    // main setup
    Serial.printf("\nIP address : "); Serial.println(WiFi.localIP());

    client.setServer((const char*)cfg["mqtt"], 1883); // cfg 데이터는 애초에 char*함수가 아닌가보다 (클래스 타입인듯?)
    client.setCallback(callback);

    while (!client.connected()) {
        Serial.println("Connecting to MQTT...");
        if (client.connect("Board")) {
            Serial.println("connected");
            client.subscribe("xy");
        } else {
            Serial.print("failed with state "); Serial.println(client.state());
            delay(2000);
        }
    }

    display.init();
    display.flipScreenVertically();
    display.setFont(ArialMT_Plain_16);
    display.drawString(0,10,"MQTT Connect");
    display.display();
    Serial.println("OLED OUTPUT IP");

    swSer.begin(9600);
    delay(500);
    Serial.println("ready to chat Board");
}

void loop() {
    client.loop();
}

void callback(char* topic, byte* payload, unsigned int length) {
    char buf[512];
    byte2buff(buf,payload,length); // 길이대로 안하게되면 그 주솟값에 이전 자료들이 남아있어 이상한값이 나오게되기에 길이를 인자로 넣어준다.
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);
    Serial.print("Message:");
    Serial.println(buf);
    swSer.print(buf);
    
    String incomming = String(buf);
    int xpos = incomming.indexOf(",");
    int zpos = incomming.indexOf(",",xpos+1);

    String strxPos = incomming.substring(0,xpos);
    String strzPos = incomming.substring(xpos+1,zpos);

    xpos = strxPos.toInt();
    zpos = strzPos.toInt();

    Serial.print("xpos = ");
    Serial.println(xpos);
    Serial.print("zpos = ");
    Serial.println(zpos);
    Serial.println("-----------------------");
}

