#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "index.h"      // web page

//SSID and Password of your WiFi router
const char *ssid = "Backhomenet";  // "your_ssid"
const char *password = "1700note"; // "your password"

ESP8266WebServer server(80);    // Server on port 80
//===================================================================
// This routine is executed when you open its IP in browser
//===================================================================
void handleRoot() {
    String s = MAIN_page;
