#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "index.h"

// SSID and Password of your WiFi router
const char *ssid = "Backhomenet";  // "your_ssid"
const char *password = "1700note"; // "your password"

ESP8266WebServer server(80);    // Server on port 80
//===================================================================
// This routine is executed when you open its IP in browser
//===================================================================
void handleRoot() {
    String s = MAIN_page;

    int tempValue;
    tempValue = 30;

    // int 온도 값을 문자열로 변환 한 다음 HTML의 @@temp@@를 온도 값으로 바꾼다
    s.replace("@@temp@@", String(tempValue));
    server.send(200, "text/html", s);   // 브라우저에 웹 페이지 보낸다
}
//===================================================================
//                    Power on setup
//===================================================================
void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);    // Connect to your WiFi router

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    // If connection successful show IP address in serial monitor
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP()); // IP address assigned to your ESP

    server.on("/", handleRoot); // Which routine to handle at root location

    server.begin();             // Start server
    Serial.println("HTTP server started");
}
//===================================================================
//                        Main Program Loop
//===================================================================
void loop() {
    server.handleClient();     // handle client request
}
