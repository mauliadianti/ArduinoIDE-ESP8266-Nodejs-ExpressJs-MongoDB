#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>


#ifndef STASSID
#define STASSID "changethiswithyourssid"
#define STAPSK "changethiswithyourpwd"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

//url server disini
const char* host = "http://localhost:3000";
const uint16_t port = 80;

String number = "112233445566";

HTTPClient http;


void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Wifi terhubung");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());
  
}

void loop() {
  WiFiClient client;
  if (!client.connect(host,port)){
    Serial.println("failed");
    delay(5000);
    return;
  }

  if(client.connected()){
   
    int x = 30; 
    x +=4;
//    Serial.println(x);

    int a = 40;
    a +=5;
//    Serial.println(a);

    DynamicJsonDocument data(200);

    Serial.print("------------kirim ini ke server--------");
    Serial.println();
    data["number"] = number;
    data["hum"] = x;
    data["temp"] = a;

    String json;
    serializeJson(data, json);
    Serial.println(json);
    http.begin("http://localhost:3000/adddata");
    http.addHeader("Content-Type", "application/json");
    int httpCode = http.POST(json);
    String payload = http.getString();


    Serial.print("------------Respon dari server--------");
    Serial.println();
    Serial.print("httpCode: ");
    Serial.println(httpCode);;
    Serial.println(payload);
    Serial.println('\n');

    http.end();
    delay(600000);
    
  }
  else{
    Serial.println("DATA GAK KEKIRIM");
  }
}
