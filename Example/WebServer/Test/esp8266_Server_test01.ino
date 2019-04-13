#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#define ssid      "Backhomenet"     // WiFi SSID
#define password  "1700note"        // WiFi password

// Creating objects 
ESP8266WebServer server ( 80 );

String getPage() {
    String page = "<html lang='en'><head><meta http-equiv='refresh' content='60' name='viewport' content='width=device-width, initial-scale=1'/>";
    page += "<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css'><script src='https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js'></script><script src='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js'></script>";
    page += "<title>ESP8266 Demo - www.analoglab.com</title></head><body>";
    page += "<div class='container-fluid'>";
    page +=   "<div class='row'>";
    page +=     "<div class='col-md-12'>";
    page +=       "<h1>Demo Webserver ESP8266 + Bootstrap</h1>";
    page +=       "<h3>Sensoring & Conntrol Mini station </h3>";
    page +=       "<ul class='nav nav-pills'>";
    page +=         "<li class='active'>";
    page +=           "<a href='#'> <span class='badge pull-right'>22 &deg;C</span> Temperature</a>";   // &deg; -> °  
    page +=         "</li>";
    page +=         "<li class='active'>";
    page +=           "<a href='#'> <span class='badge pull-right'>33 %</span> Humidity</a>";
    page +=         "</li>";
    page +=         "<li class='active'>";
    page +=           "<a href='#'> <span class='badge pull-right'>1000 ppm</span> Value of CO2</a>";
    page +=           "</li>";
    page +=       "</ul>";
    page += "</div></div></div>";
    page += "</body></html>";
    return page;
}

void handleRoot() {
    server.send ( 200, "text/html", getPage() );
}

void updateGPIO(int gpio, String DxValue) {
    Serial.println("");
    Serial.println("Update GPIO ");
}

void setup() {

    Serial.begin ( 115200 );

    WiFi.begin ( ssid, password );
    // Waiting for the WiFi connection 
    while ( WiFi.status() != WL_CONNECTED ) {
        delay ( 500 ); Serial.print ( "." );
    }
    // WiFi connection established / WiFi connection is OK
    Serial.println ( "" );
    Serial.print ( "Connected to " ); Serial.println ( ssid );
    Serial.print ( "IP address: " ); Serial.println ( WiFi.localIP() );

    // Connect the function that manages the first page / link to the function that manage launch page
    server.on ( "/", handleRoot );

    server.begin();
    Serial.println ( "HTTP server started" );

}

void loop() {
    // put your main code here, to run repeatedly:
    server.handleClient();

    delay(1000);
}
