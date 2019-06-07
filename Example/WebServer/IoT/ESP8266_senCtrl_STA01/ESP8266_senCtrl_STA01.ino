#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "index.h"      // web page

int Load1 = D1;
int Load2 = D2;
int Load3 = D3;
int Load4 = D4;         // Blue LED on Board

String L1Status, L2Status, L3Status, L4Status, Temp;

//SSID and Password of your WiFi router
const char *ssid = "Backhomenet";
const char *password = "1700note";

ESP8266WebServer server(80);        // Server on port 80
//===================================================================
// This routine is executed when you open its IP in browser
//===================================================================
void handleRoot() {
    String s = MAIN_page;

    s.replace("@@L1@@", L1Status);
    s.replace("@@L2@@", L2Status);
    s.replace("@@L3@@", L3Status);
    s.replace("@@L4@@", L4Status);
    s.replace("@@TEMP@@", Temp);

    server.send(200, "text/html", s);   // 브라우저에 웹 페이지를 보낸다
}
//=====================================================================
// This routine is executed when we press ON/OFF button i.e. form
//=====================================================================
void handleForm() {
    String L_state = server.arg("submit");  //Get submit value

    //Change Load-1 State as per request
    if (L_state == "ON1") {
        L1Status = "ON";
        digitalWrite(Load1, LOW);       //Load1 Turned on
    }
    if (L_state == "OFF1") {
        L1Status = "OFF";
        digitalWrite(Load1, HIGH);      //Load1 Turned off
    }

    if (L_state == "ON2") {
        L2Status = "ON";
        digitalWrite(Load1, LOW);       //Load1 Turned on
    }
    if (L_state == "OFF2") {
        L2Status = "OFF";
        digitalWrite(Load1, HIGH);      //Load1 Turned off
    }

    if (L_state == "ON3") {
        L3Status = "ON";
        digitalWrite(Load1, LOW);       //Load1 Turned on
    }
    if (L_state == "OFF3") {
        L3Status = "OFF";
        digitalWrite(Load1, HIGH);      //Load1 Turned off
    }

    if (L_state == "ON4") {
        L4Status = "ON";
        digitalWrite(Load1, LOW);       //Load1 Turned on
    }
    if (L_state == "OFF4") {
        L4Status = "OFF";
        digitalWrite(Load1, HIGH);      //Load1 Turned off
    }

    server.sendHeader("Location", "/"); //Send web browser to root location
    server.send(302, "text/html", "");  //Send browser 302 redirect go back to root location
}
//=================================================================
//                    Power on setup
//===================================================================
void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);    //Connect to your WiFi router

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

    server.on("/", handleRoot);     //Which routine to handle at root location
    server.on("/form", handleForm); //These request sent when we click on button

    server.begin(); //Start server
    Serial.println("HTTP server started");
}
//===================================================================
//                        Main Program Loop
//===================================================================
void loop() {
    server.handleClient();     //handle client request
}
