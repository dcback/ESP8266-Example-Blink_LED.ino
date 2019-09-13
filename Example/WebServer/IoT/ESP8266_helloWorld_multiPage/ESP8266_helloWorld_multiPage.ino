// https://www.arduinoslovakia.eu/blog/2019/4/esp8266---http-server-s-viac-strankami?lang=en
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "page1.h"
#include "page2.h"
#include "page3.h"

//SSID and Password of your WiFi router
const char *ssid = "Backhomenet";  // "your_ssid"
const char *password = "1700note"; // "your password"

ESP8266WebServer server(80);

void handleRoot() 
{
    Serial.println("GET /");
    server.send(200, "text/html", htmlPage1);
}

void handlePage2() {
    Serial.println("GET /page2");
    server.send(200, "text/html", htmlPage2);
}

void handlePage3() 
{
    Serial.println("GET /page3");
    server.send(200, "text/html", htmlPage3);
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
    server.on("/page2", handlePage2);
    server.on("/page3", handlePage3);

    server.begin();
    Serial.println("HTTP server started");
}

void loop() 
{
    server.handleClient();
}
