#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "index.h"      // web page

// SSID and Password of your WiFi router
const char *ssid = "Backhomenet";  // "your_ssid"
const char *password = "1700note"; // "your password"

ESP8266WebServer server(80);    // Server on port 80
//===================================================================
// This routine is executed when you open its IP in browser
//===================================================================
void handleRoot() 
{
    String s = MAIN_page;

    // read the digital pin(D0~D8)
    bool D0_Value = digitalRead(D0);
    bool D1_Value = digitalRead(D1);
    bool D2_Value = digitalRead(D2);
    bool D3_Value = digitalRead(D3);
    bool D4_Value = digitalRead(D4);
    bool D5_Value = digitalRead(D5);
    bool D6_Value = digitalRead(D6);
    bool D7_Value = digitalRead(D7);
    bool D8_Value = digitalRead(D8);

    // D0~D8_Value를 문자열로 변환 후 HTML의 @@D0~D8@@를 변수로 바꾼다
    s.replace("@@D0@@", String(D0_Value));
    s.replace("@@D1@@", String(D1_Value));
    s.replace("@@D2@@", String(D2_Value));
    s.replace("@@D3@@", String(D3_Value));
    s.replace("@@D4@@", String(D4_Value));
    s.replace("@@D5@@", String(D5_Value));
    s.replace("@@D6@@", String(D6_Value));
    s.replace("@@D7@@", String(D7_Value));
    s.replace("@@D8@@", String(D8_Value));

    server.send(200, "text/html", s);   // 브라우저에 웹 페이지 보낸다
}
//===================================================================
//                    Power on setup
//===================================================================
void setup() 
{
    Serial.begin(115200);
    WiFi.begin(ssid, password);    // Connect to your WiFi router

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(500);
        Serial.print(".");
    }

    //If connection successful show IP address in serial monitor
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP()); //IP address assigned to your ESP

    server.on("/", handleRoot); //Which routine to handle at root location

    server.begin();             //Start server
    Serial.println("HTTP server started");
}
//===================================================================
//                        Main Program Loop
//===================================================================
void loop() 
{
    server.handleClient();     //handle client request
}
