#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "index.h"          // web page
#define LED  ㅇ4            // Blue LED pin define(==D4)
String LED_state = "OFF";   // LED_state를 문자열 변수로 정의

// SSID and Password of your WiFi router
const char *ssid = "Backhomenet";
const char *password = "1700note";

ESP8266WebServer server(80);        // Server on port 80
//===================================================================
// This routine is executed when you open its IP in browser
//===================================================================
void handleRoot() 
{
    String s = MAIN_page;

    // LED_state문자열을 HTML의 @@status@@ 변수로 바꾼다
    s.replace("@@status@@", LED_state);
    server.send(200, "text/html", s);   // 브라우저에 웹 페이지 보낸다
}
//=====================================================================
// This rutine is exicuted when we press ON/OFF button i.e. form
//=====================================================================
void handleForm() 
{
    String s = server.arg("button");    // Get button state
    if (s == "ON") {
        digitalWrite(LED, LOW);         // Turn LED on (LED is in reverse connection)
        LED_state = "ON";               // Change status to ON
    }
    
    if (s == "OFF") 
    {
        digitalWrite(LED, HIGH);        // Turn LED off (LED is in reverse connection)
        LED_state = "OFF";              // Change status to OFF
    }

    server.sendHeader("Location", "/"); // Send web browser to root location
    server.send(302, "text/html", "");  // Send browser 302 redirect go back to root location
}
//=================================================================
//                    Power on setup
//===================================================================
void setup() 
{
    Serial.begin(115200);
    WiFi.begin(ssid, password);    //Connect to your WiFi router

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

    //Change Pin mode once we have sent the ESP IP address
    pinMode(LED, OUTPUT);
    digitalWrite(LED, HIGH);        //ledPinPin Off State

    server.on("/", handleRoot);     //Which routine to handle at root location
    server.on("/form", handleForm); //These request sent when we click on button
    server.begin(); //Start server
    Serial.println("HTTP server started");
}
//===================================================================
//                        Main Program Loop
//===================================================================
void loop() 
{
    server.handleClient();     //handle client request
}
