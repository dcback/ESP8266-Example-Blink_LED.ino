#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "index.h" // web page

//SSID and Password of your WiFi router
const char *ssid = "Backhomenet";
const char *password = "1700note";

ESP8266WebServer server(80); // Server on port 80
//=======================================================================
// handles main page
//=======================================================================
void handleRoot() 
{
    String s = MAIN_page;

    int temp = random(0, 100);   // 0 에서 99 사이 임의 값 출력
    int humi = random(0, 100);   // 0 에서 99 사이 임의 값 출력
    int bright = random(0, 100); // 0 에서 99 사이 임의 값 출력

    //Update it in HTML Code
    s.replace("@@temp@@", String(temp));
    s.replace("@@humi@@", String(humi));
    s.replace("@@bright@@", String(bright));

    server.send(200, "text/html", s);
}

void setup() 
{
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    Serial.println("");

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    server.on("/", handleRoot);

    server.begin();
    Serial.println("HTTP server started");
}

void loop() 
{
    server.handleClient();
}
