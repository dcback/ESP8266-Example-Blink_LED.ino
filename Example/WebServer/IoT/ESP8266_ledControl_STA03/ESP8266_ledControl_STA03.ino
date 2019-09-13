#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "index.h"      // web page
#define LED1  D3        // No LED pin define
#define LED2  D4        // Blue LED pin define

String LED_state1 = "OFF";
String LED_state2 = "OFF";

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
    s.replace("@@status1@@", LED_state1);
    s.replace("@@status2@@", LED_state2);
    server.send(200, "text/html", s);   // 브라우저에 웹 페이지를 보낸다
}
//===================================================================
// This routine is executed when we press ON/OFF button i.e. form
//===================================================================
void handleForm() 
{
    String s1 = server.arg("button1");  // Get button1 state
    if (s1 == "ON") 
    {
        digitalWrite(LED1, LOW);        // Turn LED1 on (LED is in reverse connection)
        LED_state1 = "ON";              // Change status to ON
    }
    
    if (s1 == "OFF") 
    {
        digitalWrite(LED1, HIGH);       // Turn LED1 off (LED is in reverse connection)
        LED_state1 = "OFF";             // Change status to OFF
    }
    
    String s2 = server.arg("button2");  // Get button2 state
    if (s2 == "ON") 
    {
        digitalWrite(LED2, LOW);        // Turn LED2 on (LED is in reverse connection)
        LED_state2 = "ON";              // Change status to ON
    }
    
    if (s2 == "OFF") 
    {
        digitalWrite(LED2, HIGH);       // Turn LED2 off (LED is in reverse connection)
        LED_state2 = "OFF";             // Change status to OFF
    }
    server.sendHeader("Location", "/"); // Send web browser to root location
    server.send(302, "text/html", "");  // Send browser 302 redirect go back to root location
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

    // If connection successful show IP address in serial monitor
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());     // IP address assigned to your ESP

    //Change Pin mode once we have sent the ESP IP address
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    digitalWrite(LED1, HIGH);           // LED1 Off State
    digitalWrite(LED2, HIGH);           // LED2 Off State

    server.on("/", handleRoot);         // Which routine to handle at root location
    server.on("/form", handleForm);     // These request sent when we click on button

    server.begin(); //Start server
    Serial.println("HTTP server started");
}
//===================================================================
//                        Main Program Loop
//===================================================================
void loop() 
{
    server.handleClient();     // handle client request
}
