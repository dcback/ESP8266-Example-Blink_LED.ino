//https://circuits4you.com/2018/02/04/esp8266-ajax-update-part-of-web-page-without-refreshing/
//ESP8266 NodeMCU AJAX Demo
//Updates and Gets data from webpage without page refresh
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "index.h"      //Our HTML webpage contents with javascripts

#define LED1     D4     //On board LED(==GPIO2)
#define LED2     D5
#define LED3     D6

String ledState1 = "OFF";
String ledState2 = "OFF";
String ledState3 = "OFF";

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

void handleLED1() {
    String t_state1 = server.arg("LEDstate1");
    if (t_state1 == "1") {
        digitalWrite(LED1, LOW);     //LED ON
        ledState1 = "ON";           //Feedback parameter
    }
    else {
        digitalWrite(LED1, HIGH);    //LED OFF
        ledState1 = "OFF";          //Feedback parameter
    }
    server.send(200, "text/plane", ledState1); //Send web page
}

void handleLED2() {
    String t_state2 = server.arg("LEDstate2");
    if (t_state2 == "1") {
        digitalWrite(LED2, LOW);    //LED ON
        ledState2 = "ON";           //Feedback parameter
    }
    else {
        digitalWrite(LED2, HIGH);   //LED OFF
        ledState2 = "OFF";          //Feedback parameter
    }
    server.send(200, "text/plane", ledState2); //Send web page
}

void handleLED3() {
    String t_state3 = server.arg("LEDstate3");
    if (t_state3 == "1") {
        digitalWrite(LED3, LOW);    //LED ON
        ledState3 = "ON";           //Feedback parameter
    }
    else {
        digitalWrite(LED3, HIGH);   //LED OFF
        ledState3 = "OFF";          //Feedback parameter
    }
    server.send(200, "text/plane", ledState3); //Send web page
}
//==============================================================
//                  SETUP
//==============================================================
void setup(void) {
    Serial.begin(115200);

    WiFi.begin(ssid, password); //Connect to your WiFi router

    //Onboard LED port Direction output
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);

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

    server.on("/", handleRoot); //Which routine to handle at root location. This is display page
    server.on("/setLED1", handleLED1);
    server.on("/setLED2", handleLED2);
    server.on("/setLED3", handleLED3);

    server.begin(); //Start server
    Serial.println("HTTP server started");
}
//==============================================================
//                     LOOP
//==============================================================
void loop(void) {
    server.handleClient(); //Handle client requests
}
