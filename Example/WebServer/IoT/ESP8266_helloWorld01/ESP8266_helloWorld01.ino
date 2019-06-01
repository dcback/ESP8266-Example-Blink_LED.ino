#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

//SSID and Password of your WiFi router
const char *ssid = "Backhomenet";  // "your_ssid"
const char *password = "1700note"; // "your password"

ESP8266WebServer server(80); // Server on port 80
//===================================================================
// IP(192.168.x.x)에 접속 후 루틴 실행
//===================================================================
void handleRoot() {
    server.send(200, "text/plain", "Hello world.. esp8266!");
}
//=====================================================================
//              SETUP
//=====================================================================
void setup(void) {
    Serial.begin(115200);
    WiFi.begin(ssid, password); //Connect to your WiFi router

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) {
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
//                    Main Program Loop
//===================================================================
void loop() {
    server.handleClient();      //handle client request
}
