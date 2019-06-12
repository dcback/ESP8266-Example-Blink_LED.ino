#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "index.h"      // web page

#define LED     D4      //On board LED

//SSID and Password of your WiFi router
const char *ssid = "Backhomenet";
const char *password = "1700note";

ESP8266WebServer server(80); //Server on port 80

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
    String s = MAIN_page; //Read HTML contents
    server.send(200, "text/html", s); //Send web page
}

void  handleSen1() {
    int a = random(0, 10);
    String sen1Value = String(a);
    server.send(200, "text/plane", sen1Value); //Send ADC value only to client ajax request

    digitalWrite(LED, !digitalRead(LED));   //Toggle LED on data request ajax
    Serial.println(sen1Value);
}
//==============================================================
//                  SETUP
//==============================================================
void setup(void) {
    Serial.begin(115200);

    WiFi.begin(ssid, password);     //Connect to your WiFi router
    Serial.println("");

    //Onboard LED port Direction output
    pinMode(LED, OUTPUT);

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
    Serial.println(WiFi.localIP());  //IP address assigned to your ESP

    server.on("/", handleRoot);      //Which routine to handle at root location. This is display page
    server.on("/readSen1", handleSen1); //This page is called by java Script AJAX

    server.begin();                  //Start server
    Serial.println("HTTP server started");
}
//==============================================================
//                     LOOP
//==============================================================
void loop(void) {
    server.handleClient();          //Handle client requests
}
