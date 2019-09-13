#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "index.h"      // web page

String username = "";
String psw = "";

//SSID and Password of your WiFi router
const char *ssid = "Backhomenet";
const char *password = "1700note";

ESP8266WebServer server(80);        // Server on port 80
//===================================================================
// This routine is executed when you open its IP in browser
//===================================================================
void handleRoot() 
{
    String s = MAIN_page;

    s.replace("@@username@@", username);
    s.replace("@@psw@@", psw);
        
    server.send(200, "text/html", s);   // 브라우저에 웹 페이지를 보낸다
}
//=====================================================================
// This routine is executed when we press ON/OFF button i.e. form
//=====================================================================
void handleForm() 
{
    username = server.arg("username");  //Get username
    psw = server.arg("psw");            //Get psw

    Serial.print("Username:");
    Serial.println(username);

    Serial.print("Password:");
    Serial.println(psw);

    server.sendHeader("Location", "/"); // Send web browser to root location
    server.send(302, "text/html", "");  // Send browser 302 redirect go back to root location
}
//=================================================================
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
    Serial.println(WiFi.localIP()); // IP address assigned to your ESP

    server.on("/", handleRoot);     // Which routine to handle at root location
    server.on("/form", handleForm); // These request sent when we click on button

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
