#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
 
#include "index.h"     // Our HTML webpage contents with javascripts
 
#define LED D4      // On board LED(==D4)
String value = "OFF";
 
// SSID and Password of your WiFi router
const char *ssid = "Backhomenet";
const char *password = "1700note";
 
ESP8266WebServer server(80); // Server on port 80
//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot()
{
   String s = MAIN_page;             // Read HTML contents
   server.send(200, "text/html", s); // Send web page
}
 
void handleValue1()
{
   String t_state = server.arg("value1");
 
   server.send(200, "text/plane", t_state); // Send web page
 
   Serial.print("value1 : ");
   Serial.println(t_state);
}
 
void handleValue2()
{
   String t_state = server.arg("value2");
 
   server.send(200, "text/plane", t_state); // Send web page
 
   Serial.print("value2 : ");
   Serial.println(t_state);
}
 
void handleValue3()
{
   String t_state = server.arg("value3");
 
   server.send(200, "text/plane", t_state); // Send web page
 
   Serial.print("value3 : ");
   Serial.println(t_state);
}
 
void setup(void)
{
   Serial.begin(115200);
   WiFi.begin(ssid, password); // Connect to your WiFi router
 
   // Onboard LED port Direction output
   pinMode(LED, OUTPUT);
 
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
   Serial.println(WiFi.localIP()); // IP address assigned to your ESP
 
   server.on("/", handleRoot); // Which routine to handle at root location.
   server.on("/setValue1", handleValue1);
   server.on("/setValue2", handleValue2);
   server.on("/setValue3", handleValue3);
 
   server.begin(); // Start server
   Serial.println("HTTP server started");
}
//==============================================================
//                     LOOP
//==============================================================
void loop(void)
{
   server.handleClient(); // Handle client requests
}
