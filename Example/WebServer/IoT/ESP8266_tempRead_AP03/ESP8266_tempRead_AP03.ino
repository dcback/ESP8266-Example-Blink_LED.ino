#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "index.h"

//SSID and Password of your WiFi router
const char* ssid = "ESPWebserver";
const char* password = "12345678";

ESP8266WebServer server(80);    // Server on port 80

int tempValue;                  // 온도 값 변수
int cnt = 0;                    // 온도 증가용 변수
//===================================================================
// This routine is executed when you open its IP in browser
//===================================================================
void handleRoot()
{
    String s = MAIN_page;

    tempValue = 10 + cnt;
    cnt = cnt + 1;
    if (tempValue == 20) cnt = 0;

    // int 온도 값을 문자열로 변환 한 다음 HTML의 @@temp@@를 온도 값으로 바꾼다
    s.replace("@@temp@@", String(tempValue));
    server.send(200, "text/html", s);   // 브라우저에 웹 페이지 보낸다

    Serial.println(tempValue);          // 시리얼 모니터링
}
//===================================================================
//                    Power on setup
//===================================================================
void setup()
{
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
void loop()
{
    server.handleClient();
}
