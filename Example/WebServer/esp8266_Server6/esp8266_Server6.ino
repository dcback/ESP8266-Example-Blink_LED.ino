#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "page.h"

#define ssid      "Backhomenet"     // WiFi SSID
#define password  "1700note"        // WiFi password

// Creating objects / create Objects
ESP8266WebServer server ( 80 );

void handleRoot() {
    if ( server.hasArg("D4") ) {
        handleD4();
    } else if ( server.hasArg("D5") ) {
        handleD5();
    } else if ( server.hasArg("D6") ) {
        handleD6();
    } else if ( server.hasArg("D7") ) {
        handleD7();
    } else {
        server.send ( 200, "text/html", getPage() );
    }
}

void handleD4() {
    String D4Value;
    updateGPIO(0, server.arg("D4"));
}

void handleD5() {
    String D5Value;
    updateGPIO(1, server.arg("D5"));
}

void handleD6() {
    String D6Value;
    updateGPIO(2, server.arg("D6"));
}

void handleD7() {
    String D7Value;
    updateGPIO(3, server.arg("D7"));
}

void updateGPIO(int gpio, String DxValue) {
    Serial.println("");
    Serial.println("Update GPIO "); Serial.print(GPIOPIN[gpio]); Serial.print(" -> "); Serial.println(DxValue);

    if ( DxValue == "1" ) {
        digitalWrite(GPIOPIN[gpio], LOW);       // default HIGH
        ledGpio[gpio] = "On";
        server.send ( 200, "text/html", getPage() );
    } else if ( DxValue == "0" ) {
        digitalWrite(GPIOPIN[gpio], HIGH);      // default LOW
        ledGpio[gpio] = "Off";
        server.send ( 200, "text/html", getPage() );
    } else {
        Serial.println("Err Led Value");
    }
}

void setup() {
    for ( int x = 0 ; x < 5 ; x++ ) {
        pinMode(GPIOPIN[x], OUTPUT);
        digitalWrite(GPIOPIN[x], HIGH); // HIGH = OFF, LOW = ON
    }
    Serial.begin ( 115200 );

    WiFi.begin ( ssid, password );
    // Waiting for the WiFi connection / Wait for connection
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

    pretempValue = 25.0 + cnt;
    prehumiValue = 50.0 + cnt;
    preco2Value = 1000.0 + cnt;

    cnt++;
    
    tempValue = 25.0 + cnt;
    humiValue = 50.0 + cnt;
    co2Value = 1000.0 + cnt;
    
    if ( cnt == 10 ) cnt = 0;
    Serial.print("T : "); Serial.println(tempValue);
    Serial.print("H : "); Serial.println(humiValue);
    Serial.print("CO2 : "); Serial.println(co2Value);
    delay(1000);
}
