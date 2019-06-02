#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "index.h"

//SSID and Password of your WiFi router
const char* ssid = "ESPWebserver";
const char* password = "12345678";

ESP8266WebServer server(80);    // Server on port 80
//===================================================================
// This routine is executed when you open its IP in browser
//===================================================================
void handleRoot() {
    String s = MAIN_page;

    int tempValue;
    tempValue = 25;

    // int 온도 값을 문자열로 변환 한 다음 HTML의 @@temp@@를 온도 값으로 바꾼다
    s.replace("@@temp@@", String(tempValue));
    server.send(200, "text/html", s);   // 브라우저에 웹 페이지 보낸다
}
//===================================================================
//                    Power on setup
//===================================================================
void setup() {
    Serial.begin(115200);
    Serial.println("");
    WiFi.mode(WIFI_AP);             // only Access Point
    WiFi.softAP(ssid, password);    // Hotspot Start

    IPAddress myIP = WiFi.softAPIP();   // Get IP address
    Serial.print("HotSpot IP:");
    Serial.println(myIP);

    server.on("/", handleRoot);         // Which routine to handle at root location

    server.begin(); //Start server
    Serial.println("HTTP server started");
}

//===================================================================
//                    Main Program Loop
//===================================================================
void loop() {
    server.handleClient();
}
