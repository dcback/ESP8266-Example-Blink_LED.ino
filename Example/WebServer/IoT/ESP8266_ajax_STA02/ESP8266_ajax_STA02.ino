// ESP8266 NodeMCU AJAX Demo
// Updates and Gets data from webpage without page refresh
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
 
#include "index.h"  // Our HTML webpage contents with javascripts
#define LED     D4  // On board LED
 
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
 
void handlesen1()
{
   int sen1 = random(0, 100);
   String sen1Value = String(sen1);
   server.send(200, "text/plane", sen1Value); // Send sen1Value client ajax request
 
   digitalWrite(LED, !digitalRead(LED)); // Toggle LED on data request ajax
}
 
void handlesen2()
{
   int sen2 = random(0, 100);
   String sen2Value = String(sen2);
   server.send(200, "text/plane", sen2Value); // Send sen1Value client ajax request
}
 
void handlesen3()
{
   int sen3 = random(0, 100);
   String sen3Value = String(sen3);
   server.send(200, "text/plane", sen3Value); // Send sen1Value client ajax request
}
//==============================================================
//                  SETUP
//==============================================================
void setup(void)
{
   Serial.begin(115200);
 
   WiFi.begin(ssid, password); // Connect to your WiFi router
   Serial.println("");
 
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
 
   server.on("/", handleRoot); // Which routine to handle at root location. This is display page
   server.on("/readSen1", handlesen1);
   server.on("/readSen2", handlesen2);
   server.on("/readSen3", handlesen3);
 
   server.begin(); //Start server
   Serial.println("HTTP server started");
}
//==============================================================
//                     LOOP
//==============================================================
void loop(void)
{
   server.handleClient(); // Handle client requests
}
