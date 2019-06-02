#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "index.h"  //HTML Webpage contents

//SSID and Password of your WiFi router
const char *ssid = "ESPWebserver";
const char *password = "12345678";

ESP8266WebServer server(80); // Server on port 80
//=====================================================================
// This rutine is exicuted when you open its IP in browser
//=====================================================================
void handleRoot() {
    String s = MAIN_page;
    server.send(200, "text/html", s);
}
//=====================================================================
//                              SETUP
//=====================================================================
void setup(void) {
    Serial.begin(115200);
    Serial.println("");
    WiFi.mode(WIFI_AP);                 //only Access Point
    WiFi.softAP(ssid, password);

    IPAddress myIP = WiFi.softAPIP();   // Get IP address
    Serial.print("HotSpot IP:");
    Serial.println(myIP);

    server.on("/", handleRoot); // Which routine to handle at root location

    server.begin(); //Start server
    Serial.println("HTTP server started");
}
//===================================================================
//                    Main Program Loop
//===================================================================
void loop() {
    server.handleClient();
}
