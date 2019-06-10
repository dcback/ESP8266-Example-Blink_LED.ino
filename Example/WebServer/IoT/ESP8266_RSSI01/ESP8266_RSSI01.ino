#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "index.h" // web page

//SSID and Password of your WiFi router
const char *ssid = "Backhomenet";
const char *password = "1700note";

int WiFiStrength = 0;

ESP8266WebServer server(80); // Server on port 80
//=======================================================================
// handles main page
//=======================================================================
void handleRoot() {
    String s = MAIN_page;

    s.replace("@@value@@", String(WiFiStrength)); //Update it in HTML Code
    server.send(200, "text/html", s);
}

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    Serial.println("");

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) {
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

void loop() {
    WiFiStrength = WiFi.RSSI(); // get dBm from the ESP8266
    Serial.print("WiFi Strength: ");
    Serial.print(WiFiStrength); Serial.println("dBm");
    delay(1000);

    server.handleClient();
}
