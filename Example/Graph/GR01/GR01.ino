// https://circuits4you.com/2019/01/25/esp8266-dht11-humidity-temperature-data-logging/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "index.h" //Our HTML webpage contents with javascripts

#define LED     2  //On board LED

unsigned int cnt = 0;

float humidity, temperature;
int   voltage;
//SSID and Password of your WiFi router
const char* ssid = "Backhomenet";
const char* password = "1700note";

ESP8266WebServer server(80); //Server on port 80

void handleRoot() {     // This routine is executed when you open its IP in browser
    String s = MAIN_page; //Read HTML contents
    server.send(200, "text/html", s); //Send web page
}

void handleADC() {

    //Ref 1: https://circuits4you.com/2019/01/11/nodemcu-esp8266-arduino-json-parsing-example/
    //Ref 2: https://circuits4you.com/2019/01/25/arduino-how-to-put-quotation-marks-in-a-string/
    String data = "{\"ADC\":\"" + String(voltage) + "\", \"Temperature\":\"" + String(temperature) + "\", \"Humidity\":\"" + String(humidity) + "\"}";

    digitalWrite(LED, !digitalRead(LED)); //Toggle LED on data request ajax
    server.send(200, "text/plane", data); //Send ADC value, temperature and humidity JSON to client ajax request

    //Get Humidity temperatue data after request is complete
    //Give enough time to handle client to avoid problems
    delay(1000);

    voltage     = 10    + cnt;
    humidity    = 20.00 + cnt;
    temperature = 20.00 - cnt;

    if ( cnt == 5) cnt = 0;
    cnt++;
}

void setup() {
    Serial.begin(115200);
    Serial.println();

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
    server.on("/readADC", handleADC); //This page is called by java Script AJAX

    server.begin();                  //Start server
    Serial.println("HTTP server started");
}

void loop() {
    server.handleClient();          //Handle client requests
}
